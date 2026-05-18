#ifndef ARRAYSEQUENCE_H 
#define ARRAYSEQUENCE_H

#include "array.hpp"
#include "sequences.hpp"

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

#endif