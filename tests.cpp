#include "sequences.hpp"

void test_array() {
    int arr[3] = {1, 2, 3};
    DynamicSequence<int> bro(arr, 3);
    bro.Append(7);
    std::cout<<bro.Get(2)<<"\n";
    DynamicSequence<int> subArray = bro.GetSubList(1, 4);
    std::cout<<subArray.Get(0)<<"\n";
    std::cout<<subArray.Get(2)<<"\n";
}

void test_list() {
    int arr1[3] = {1, 2, 3};
    ListSequence bro2(arr1, 3);
    std::cout<<bro2.Get(2)<<"\n";
    bro2.Prepend(0);
    bro2.InsertAt(8, 2);
    std::cout<<bro2.Get(2)<<"\n";
    std::cout<<bro2.GetFirst()<<"\n";
    std::cout<<bro2.GetLast()<<"\n";
}