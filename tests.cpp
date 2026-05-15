#include "sequences.hpp"

void test_array() {
    int arr[3] = {1, 2, 3};
    DynamicSequence<int> bro(arr, 3);
    bro.Prepend(7);
    std::cout<<bro.Get(2)<<"\n";
    DynamicSequence<int> subArray = bro.GetSubList(1, 4);
    std::cout<<subArray.Get(0)<<"\n";
    std::cout<<subArray.Get(2)<<"\n";
}

void test_list() {
    std::cout<<"list"<<"\n";
    int arr1[3] = {1, 2, 3};
    //int arr2[2] = {4, 5};
    ListSequence bro2(arr1, 3);
    ListSequence<int> bro3 = bro2.GetSubList(0, 3);
    //ListSequence bro3(arr2, 2);
    //bro2.Concat(&bro3);
    //std::cout<<bro2.Get(2)<<"\n";
    //bro2.Prepend(0);
    //bro2.InsertAt(8, 2);
    for (int i = 0; i < bro3.GetLength(); i++) {
        std::cout<<bro3.Get(i)<<"\n";
    }
    std::cout<<"list printed"<<"\n";
    std::cout<<bro2.Get(1)<<"\n";
    std::cout<<bro2.GetFirst()<<"\n";
    std::cout<<bro2.GetLast()<<"\n";
}