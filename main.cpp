#include "ListSequence.hpp"
#include "DynamicSequence.hpp"
#include "tests.hpp" 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

static void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    int choice;
    int buffer;
    int buffer2;
    MutListSequence<int> bro;
    //bro.Prepend(1);
    std::cout<<bro.GetFirst();
    test_array();
    test_list();
    std::cout<<"Length: ";
    std::cin>>buffer;
    int* arr = new int[buffer];
    for (int i = 0; i < buffer; i++) {
        std::cout<<"Element: ";
        std::cin>>arr[i];
    }
    MutDynamicSequence<int> base_array(arr, buffer);
    delete[] arr;
    std::cout<<"Length: ";
    std::cin>>buffer;
    int* arr1 = new int[buffer];
    for (int i = 0; i < buffer; i++) {
        std::cout<<"Element: ";
        std::cin>>arr1[i];
    }
    MutListSequence<int> base_list(arr1, buffer);
    delete[] arr1;
    printf(" [1] Get array length\n");
    printf(" [2] Get array element\n");
    printf(" [3] Prepend array element\n");
    printf(" [4] Append array element\n");
    printf(" [5] Insert array element\n");
    printf(" [6] Get subarray(it will be printed)\n");
    printf(" [7] Get list length\n");
    printf(" [8] Get list element\n");
    printf(" [9] Prepend list element\n");
    printf(" [10] Append list element\n");
    printf(" [11] Insert list element\n");
    printf(" [12] Get sublist(it will be printed)\n");
    printf(" [13] Get first list element\n");
    printf(" [14] Get last list element\n");
    printf(" [15] Concatenate lists(new list will be created to concatenate it with first one)\n");
    printf(" [0] Exit\n");
    printf("----------------------------\n");
    while (1) {
        
        printf("Choose: ");

        if (scanf("%d", &choice) != 1) {
            printf("Ошибка: введено не число.\n");
            clear_input_buffer();
            continue;
        }

        switch (choice) {
            case 1:
                std::cout<<base_array.GetLength()<<"\n";
                break;
            case 2:
                std::cout<<"Index: ";
                std::cin>>buffer;
                std::cout<<base_array.Get(buffer)<<"\n";
                clear_input_buffer();
                break;
            case 3:
                std::cout<<"New element: ";
                std::cin>>buffer;
                base_array.Prepend(buffer);
                clear_input_buffer();
                break;
            case 4:
                std::cout<<"New element: ";
                std::cin>>buffer;
                base_array.Append(buffer);
                clear_input_buffer();
                break;
            case 5:
                std::cout<<"New element: ";
                std::cin>>buffer;
                std::cout<<"Index: ";
                std::cin>>buffer2;
                base_array.InsertAt(buffer, buffer2);
                clear_input_buffer();
                break;
            case 6: {
                std::cout<<"Start index: ";
                std::cin>>buffer;
                std::cout<<"End index: ";
                std::cin>>buffer2;
                MutDynamicSequence<int> array_result = *(static_cast<MutDynamicSequence<int>*>(base_array.GetSubList(buffer, buffer2)));
                for (int i = 0; i < array_result.GetLength(); i++) {
                    std::cout<<array_result.Get(i)<<"\n";
                }
                clear_input_buffer();
                break;
            }
            case 7:
                std::cout<<base_list.GetLength()<<"\n";
                break;
            case 8:
                std::cout<<"Index: ";
                std::cin>>buffer;
                std::cout<<base_list.Get(buffer)<<"\n";
                clear_input_buffer();
                break;
            case 9:
                std::cout<<"New element: ";
                std::cin>>buffer;
                base_list.Prepend(buffer);
                clear_input_buffer();
                break;
            case 10:
                std::cout<<"New element: ";
                std::cin>>buffer;
                base_list.Append(buffer);
                clear_input_buffer();
                break;
            case 11:
                std::cout<<"New element: ";
                std::cin>>buffer;
                std::cout<<"Index: ";
                std::cin>>buffer2;
                base_list.InsertAt(buffer, buffer2);
                clear_input_buffer();
                break;
            case 12: {
                std::cout<<"Start index: ";
                std::cin>>buffer;
                std::cout<<"End index: ";
                std::cin>>buffer2;
                MutListSequence<int> list_result = *(static_cast<MutListSequence<int>*>(base_list.GetSubList(buffer, buffer2)));
                for (int i = 0; i < list_result.GetLength(); i++) {
                    std::cout<<list_result.Get(i)<<"\n";
                }
                clear_input_buffer();
                break;
                }
            case 13:
                std::cout<<base_list.GetFirst()<<"\n";
                break;
            case 14:
                std::cout<<base_list.GetLast()<<"\n";
                break;
            case 15: {
                std::cout<<"Length: ";
                std::cin>>buffer;
                int* arr2 = new int[buffer];
                for (int i = 0; i < buffer; i++) {
                std::cout<<"Element: ";
                std::cin>>arr2[i];
                }
                MutListSequence<int> concat_list(arr2, buffer);
                base_list.Concat(&concat_list);
                for (int i = 0; i < base_list.GetLength(); i++) {
                    std::cout<<base_list.Get(i)<<"\n";
                }
                delete[] arr2;
                clear_input_buffer();
                break;
                }
            default:
                std::cout<<"Wrong number.\n";
                break;
            case 0:
                std::cout<<"Leaving\n";
                return 0;
        }
    }
};