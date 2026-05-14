#include "array.hpp"
#include "list.hpp"

template <typename data_type>
class Sequence
{
public:
    virtual data_type Get(int index) = 0;

    virtual int GetLength() = 0;

    virtual void Append(data_type new_elem) = 0;

    virtual void Prepend(data_type new_elem) = 0;

    virtual void InsertAt(data_type new_elem, int postion) = 0;
};


template <typename data_type>
class DynamicSequence: public Sequence<data_type>
{
private:
    DynamicArray<data_type> array;

public:
    DynamicSequence(data_type* items, int length) : array(items, length) {}

    DynamicSequence() : array() {}

    DynamicSequence(DynamicSequence <data_type> & old_array) : array(old_array.array) {}

    int GetLength() {
        return array.GetLength();
    }

    data_type Get(int index) {
        return array.Get(index);
    }

    void Append(data_type new_elem) {
        array.Resize(array.GetLength() + 1);
        array.Set(array.GetLength() - 1, new_elem);
    }

    void Prepend(data_type new_elem) {
        array.Resize(array.GetLength() + 1);
        for (int i = array.GetLength() - 1; 0 < i; i--) {
            array.Set(i, array.Get(i - 1));
        }
        array.Set(0, new_elem);
    }

    void InsertAt(data_type new_elem, int position) {
        array.Resize(array.GetLength() + 1);
        for (int i = array.GetLength() - 1; position < i; i--) {
            array.Set(i, array.Get(i - 1));
        }
        array.Set(position, new_elem);
    }

    DynamicSequence<data_type> GetSubList(int startIndex, int endIndex) {
        DynamicSequence<data_type> result(array.GetSubArray(startIndex, endIndex), endIndex - startIndex);
        return result;
    }
};


template <typename data_type>
class ListSequence: public Sequence<data_type>
{
private:
    LinkedList<data_type> list;

public:
    ListSequence(data_type* items, int length) : list(items, length) {}

    ListSequence() : list() {}

    ListSequence(ListSequence <data_type> & old_list) : list(old_list->list) {}

    int GetLength() {
        return list.GetLength();
    }

    data_type GetFirst() {
        return list.GetFirst();
    }

    data_type Get(int index) {
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

    void InsertAt(data_type new_elem, int postion) {
        list.InsertAt(new_elem, postion);
    }

    ListSequence<data_type> GetSubList(int startIndex, int endIndex) {
        ListSequence<data_type> result;
        result.list = list.GetSubList(startIndex, endIndex); 
        return result;
    }

    void Concat(ListSequence<data_type> *new_list) {
        list.Concat(&(new_list->list));
    }
};