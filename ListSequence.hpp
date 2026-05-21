#ifndef LISTSEQUENCE_H 
#define LISTSEQUENCE_H

#include "sequences.hpp"
#include "list.hpp"

template <typename data_type>
class ListSequence: public Sequence<data_type>
{
private:
    LinkedList<data_type> list;

public:
    ListSequence(data_type* items, int length) : list(items, length) {}

    ListSequence() : list() {}

    ListSequence(ListSequence <data_type> & old_list) : list(old_list.list) {}

    int GetLength() {
        return list.GetLength();
    }

    data_type GetFirst() {
        return list.GetFirst();
    }

    data_type Get(int index) {
        if ((index >= list.GetLength()) or (index < 0)) {
            std::cout<<"Wrong index, first value returned\n";
            return list.GetFirst();
        }
        return list.Get(index);
    }

    data_type GetLast() {
        return list.GetLast();
    }

    Sequence<data_type>* Append(data_type new_elem) {
        auto result = static_cast<ListSequence<data_type>*>(Instance());
        result->list.Append(new_elem);
        return result;
    }

    Sequence<data_type>* Prepend(data_type new_elem) {
        auto result = static_cast<ListSequence<data_type>*>(Instance());
        result->list.Prepend(new_elem);
        return result;
    }

    Sequence<data_type>* InsertAt(data_type new_elem, int position) {
        auto result = static_cast<ListSequence<data_type>*>(Instance());
        if ((position < 0) or (position > (list.GetLength() - 1))) {
            std::cout<<"Wrong index\n";
        }
        else {
        result->list.InsertAt(new_elem, position);
        }
        return result;
    }

    Sequence<data_type>* GetSubList(int startIndex, int endIndex) {
        auto result = static_cast<ListSequence<data_type>*>(Instance());
        int new_length = endIndex - startIndex;
        if (new_length < 1) {
            std::cout<<"Incorrect length, full list will be returned\n";
            new_length = list.GetLength();
            return result; 
        }
        result->list.GetSubList(startIndex, endIndex);
        return result;   
    }

    Sequence<data_type>* Concat(Sequence<data_type> *new_list) {
        auto result = static_cast<ListSequence<data_type>*>(Instance());
        result->list.Concat(&((static_cast<ListSequence<data_type>*>(new_list))->list));
        return result;
    }

    virtual Sequence<data_type>* Instance() = 0;
};

template <typename data_type>
class MutListSequence: public ListSequence<data_type>
{
public:
    MutListSequence(data_type* items, int length) : ListSequence<data_type>(items, length) {}

    MutListSequence() : ListSequence<data_type>() {}

    MutListSequence(MutListSequence<data_type> & old_list) : ListSequence<data_type>(old_list) {}

    Sequence<data_type>* Instance() {
        return this;
    }
};

template <typename data_type>
class ImmutListSequence: public ListSequence<data_type>
{
public:
    ImmutListSequence(data_type* items, int length) : ListSequence<data_type>(items, length) {}

    ImmutListSequence() : ListSequence<data_type>() {}

    ImmutListSequence(ImmutListSequence<data_type> & old_list) : ListSequence<data_type>(old_list) {}

    Sequence<data_type>* Instance() {
        return new ImmutListSequence<data_type>(*this); 
    }
};

#endif