#include "sequences.hpp"
#include "ListSequence.hpp"
#include "DynamicSequence.hpp"

void test_array() {
    std::cout<<"Testing array\n";
    int arr[3] = {1, 2, 3};
    MutDynamicSequence<int> bro(arr, 3);
    if (bro.GetLength() == 3) {
        std::cout<<"Length returned correctly\n";
    }
    else {
        std::cout<<"Length request failture\n";
    }
    bro.Prepend(7);
    if (bro.Get(0) == 7) {
        std::cout<<"Prepend works correctly\n";
    }
    else {
        std::cout<<"Prepend failture\n";
    }
    bro.Append(8);
    if (bro.Get(4) == 8) {
        std::cout<<"Append works correctly\n";
    }
    else {
        std::cout<<"Append failture\n";
    }
    bro.InsertAt(9, 3);
    if (bro.Get(3) == 9) {
        std::cout<<"Insert works correctly\n";
    }
    else {
        std::cout<<"Insert failture\n";
    }
    MutDynamicSequence<int> subArray = *(static_cast<MutDynamicSequence<int>*>(bro.GetSubList(2, 4)));
    if (subArray.Get(0) == 2 and subArray.Get(1) == 9) {
        std::cout<<"GetSubList works correctly\n";
    }
    else {
        std::cout<<"GetSubList failture\n";
    }
}

void test_list() {
    std::cout<<"Testing list"<<"\n";
    int arr1[3] = {1, 2, 3};
    MutListSequence bro(arr1, 3);
    if (bro.GetLength() == 3) {
        std::cout<<"Length returned correctly\n";
    }
    else {
        std::cout<<"Length request failture\n";
    }
    bro.Prepend(7);
    if (bro.Get(0) == 7) {
        std::cout<<"Prepend works correctly\n";
    }
    else {
        std::cout<<"Prepend failture\n";
    }
    bro.Append(8);
    if (bro.Get(4) == 8) {
        std::cout<<"Append works correctly\n";
    }
    else {
        std::cout<<"Append failture\n";
    }
    bro.InsertAt(9, 3);
    if (bro.Get(3) == 9) {
        std::cout<<"Insert works correctly\n";
    }
    else {
        std::cout<<"Insert failture\n";
    }
    int arr2[2] = {4, 5};
    MutListSequence bro3(arr2, 2);
    bro.Concat(&bro3);
    if (bro.GetLast() == 5) {
        std::cout<<"Concat works correctly\n";
    }
    else {
        std::cout<<"Concat failture\n";
    }
}