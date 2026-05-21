#ifndef ARRAY_H 
#define ARRAY_H
#include <iostream>
#include <string>

template <typename data_type>
class DynamicArray
{
private:
    data_type* data;
    int length;

public:
    DynamicArray (data_type* items, int count) {
        data = new data_type[count];
        for (int i = 0; i < count; i++) {
            data[i] = items[i];
        }
        length = count;
    }

    DynamicArray () {
        length = 0;
        data = new data_type[0];
    }

    DynamicArray(DynamicArray<data_type> &dynamicArray) {
        length = dynamicArray.GetLength();
        data = new data_type[length];
        for (int i = 0; i < length; i++) {
            data[i] = dynamicArray.data[i];
        }
    }

    data_type Get(int index) {
        return data[index];
    }

    int GetLength() {
        return length;
    }

    void Set(int count, data_type item) {
        data[count] = item;
    }

    void Resize(int new_length) {
        data_type* new_data = new data_type[new_length];
        if (length < new_length) {
            for (int i = 0; i < length; i++) {
                new_data[i] = data[i];
            }
        }
        else {
            for (int i = 0; i < new_length; i++) {
                new_data[i] = data[i];
            }
        }
        delete[] data;
        data = new_data;
        length = new_length;
    }

    data_type* GetSubArray(int startIndex, int endIndex) {
        int length = endIndex - startIndex;
        if (length <= 0) {
            std::cout<<"endIndex must be strictly greater than startIndex";
            return NULL;
        }
        else {
            data_type *new_data = new data_type[length];
            for (int i = startIndex; i < endIndex; i++) {
                new_data[i - startIndex] = data[i];
            }
            return new_data;
        }
    }

    void Concat(DynamicArray<data_type> *new_array) {
        int count = length;
        Resize(GetLength() + new_array->GetLength());
        for (int i = count; i < length; i++) {
            data[i] = new_array->data[i - count];
        }
    }

    ~DynamicArray() {
        delete[] data;
    }
};

#endif