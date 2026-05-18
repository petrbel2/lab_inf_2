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

    void Append(data_type new_elem) {
        list.Append(new_elem);
    }

    void Prepend(data_type new_elem) {
        list.Prepend(new_elem);
    }

    void InsertAt(data_type new_elem, int position) {
        if ((position < 0) or (position > (list.GetLength() - 1))) {
            std::cout<<"Wrong index\n";
        }
        else {
        list.InsertAt(new_elem, position);
        }
    }

    ListSequence<data_type> GetSubList(int startIndex, int endIndex) {
        ListSequence<data_type> result(list.GetSubList(startIndex, endIndex), endIndex - startIndex);
        return result;   
    }

    void Concat(ListSequence<data_type> *new_list) {
        list.Concat(&(new_list->list));
    }
};

template <typename data_type>
class ImmutListSequence
{
private:
    LinkedList<data_type> list;

public:
    ImmutListSequence(data_type* items, int length) : list(items, length) {}

    ImmutListSequence() : list() {}

    ImmutListSequence(ImmutListSequence<data_type> & old_list) : list(old_list.list) {}

    void GetData(int length, data_type* massiv) {
        for (int i = 0; i < length; i++) {
            massiv[i] = list.Get(i);
        }
    }

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

    ListSequence<data_type> Append(data_type new_elem) {
        data_type* copy_data = new data_type[list.GetLength()];
        GetData(list.GetLength(), copy_data);
        ListSequence<data_type> result(copy_data, list.GetLength());
        result.Append(new_elem);
        return result;
    }

    ListSequence<data_type> Prepend(data_type new_elem) {
        data_type* copy_data = new data_type[list.GetLength()];
        GetData(list.GetLength(), copy_data);
        ListSequence<data_type> result(copy_data, list.GetLength());
        result.Prepend(new_elem);
        return result;
    }

    ListSequence<data_type> InsertAt(data_type new_elem, int position) {
        data_type* copy_data = new data_type[list.GetLength()];
        GetData(list.GetLength(), copy_data);
        ListSequence<data_type> result(copy_data, list.GetLength());
        result.InsertAt(new_elem, position);
        return result;
    }

    ListSequence<data_type> GetSubList(int startIndex, int endIndex) {
        ListSequence<data_type> result(list.GetSubList(startIndex, endIndex), endIndex - startIndex);
        return result;   
    }

    ListSequence<data_type> Concat(ListSequence<data_type> *new_list) {
        data_type* copy_data = new data_type[list.GetLength()];
        GetData(list.GetLength(), copy_data);
        ListSequence<data_type> result(copy_data, list.GetLength());
        result.Concat(&(new_list->list));
        return result;
    }
};

#endif