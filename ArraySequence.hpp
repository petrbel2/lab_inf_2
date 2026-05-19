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

    virtual Sequence<data_type>* Instance() = 0;

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

    Sequence<data_type>* Append(data_type new_elem) {
        auto result = static_cast<DynamicSequence<data_type>*>(Instance());
        result->array.Resize(array.GetLength() + 1);
        result->array.Set(array.GetLength() - 1, new_elem);
        return result;
    }

    Sequence<data_type>* Prepend(data_type new_elem) {
        auto result = static_cast<DynamicSequence<data_type>*>(Instance());
        result->array.Resize(array.GetLength() + 1);
        for (int i = array.GetLength() - 1; 0 < i; i--) {
           result->array.Set(i, array.Get(i - 1));
        }
        result->array.Set(0, new_elem);
        return result;
    }

    Sequence<data_type>* InsertAt(data_type new_elem, int position) {
        auto result = static_cast<DynamicSequence<data_type>*>(Instance());
        if ((position < 0) or (position > (array.GetLength() - 1))) {
            std::cout<<"Wrong index\n";
            return result;
        }
        else {
        result->array.Resize(array.GetLength() + 1);
        for (int i = result->array.GetLength() - 1; position < i; i--) {
            result->array.Set(i, array.Get(i - 1));
        }
        result->array.Set(position, new_elem);
        return result;
        }
    }

    //Sequence<data_type>* GetSubList(int startIndex, int endIndex) {
    //    auto result = (array.GetSubArray(startIndex, endIndex), endIndex - startIndex);
    //    return result;
    //}
};



template <typename data_type>
class MutDynamicSequence: public DynamicSequence<data_type>
{
    public:
    MutDynamicSequence(data_type* items, int length) {}// : DynamicSequence(items, length) {}

    MutDynamicSequence() {}// : DynamicSequence() {}

    MutDynamicSequence(MutDynamicSequence <data_type> & old_array) {}// : DynamicSequence(old_array) {}

    Sequence<data_type>* Instance() {
        return this;
    }
};

template <typename data_type>
class ImmutDynamicSequence: public DynamicSequence<data_type>
{
    Sequence<data_type>* Instance() {
        ImmutDynamicSequence<data_type> clone = ImmutDynamicSequence(this);
        return clone;
    }
};

#endif