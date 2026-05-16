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
        if ((index >= array.GetLength()) or (index < 0)) {
            std::cout<<"Wrong index, first value returned\n";
            return array.Get(0);
        }
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
        if ((position < 0) or (position > (array.GetLength() - 1))) {
            std::cout<<"Wrong index\n";
        }
        else {
        array.Resize(array.GetLength() + 1);
        for (int i = array.GetLength() - 1; position < i; i--) {
            array.Set(i, array.Get(i - 1));
        }
        array.Set(position, new_elem);
        }
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


// IMMUTABLES


template <typename data_type>
class ImmutDynamicSequence
{
private:
    DynamicArray<data_type> array;

public:
    ImmutDynamicSequence(data_type* items, int length) : array(items, length) {}

    ImmutDynamicSequence() : array() {}

    ImmutDynamicSequence(ImmutDynamicSequence <data_type> & old_array) : array(old_array.array) {}

    int GetLength() {
        return array.GetLength();
    }

    data_type Get(int index) {
        if ((index >= array.GetLength()) or (index < 0)) {
            std::cout<<"Wrong index, first value returned\n";
            return array.Get(0);
        }
        return array.Get(index);
    }

    void GetData(int length, data_type* massiv) {
        for (int i = 0; i < length; i++) {
            massiv[i] = array.Get(i);
        }
    }

    DynamicSequence<data_type> Append(data_type new_elem) {
        data_type* copy_data = new data_type[array.GetLength()];
        GetData(array.GetLength(), copy_data);
        DynamicSequence<data_type> result(copy_data, array.GetLength());
        result.Append(new_elem);
        return result;
    }

    DynamicSequence<data_type> Prepend(data_type new_elem) {
        data_type* copy_data = new data_type[array.GetLength()];
        GetData(array.GetLength(), copy_data);
        DynamicSequence<data_type> result(copy_data, array.GetLength());
        result.Prepend(new_elem);
        return result;
    }

    DynamicSequence<data_type> InsertAt(data_type new_elem, int position) {
        data_type* copy_data = new data_type[array.GetLength()];
        GetData(array.GetLength(), copy_data);
        DynamicSequence<data_type> result(copy_data, array.GetLength());
        result.InsertAt(new_elem, position);
        return result;
    }

    DynamicSequence<data_type> GetSubList(int startIndex, int endIndex) {
        DynamicSequence<data_type> result(array.GetSubArray(startIndex, endIndex), endIndex - startIndex);
        return result;
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
        DynamicSequence<data_type> result(copy_data, list.GetLength());
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
        DynamicSequence<data_type> result(copy_data, list.GetLength());
        result.Concat(&(new_list->list));
        return result;
    }
};