#include "sequences.hpp"
#include "tests.hpp" 
#include <stdio.h>
#include <stdlib.h>

static void clear_input_buffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main()
{
    int choice;
    int buffer;
    int buffer2;
    //test_array();
    //test_list();
    int arr[3] = {1, 2, 3};
    DynamicSequence<int> base_array(arr, 3);
    int arr1[3] = {1, 2, 3};
    ListSequence base_list(arr1, 3);
    printf(" [1] Make array(otherwise default array will be used)\n");
    printf(" [2] Make list(otherwise default list will be used)\n");
    printf(" [3] Get array length\n");
    printf(" [4] Get array element\n");
    printf(" [5] Prepend array element\n");
    printf(" [6] Append array element\n");
    printf(" [7] Insert array element\n");
    printf(" [8] Get subarray(it will be printed)\n");
    printf(" [9] Get list length\n");
    printf(" [10] Get list element\n");
    printf(" [11] Prepend list element\n");
    printf(" [12] Append list element\n");
    printf(" [13] Insert list element\n");
    printf(" [14] Get sublist(it will be printed)\n");
    printf(" [15] Get first list element\n");
    printf(" [16] Get last list element\n");
    printf(" [17] Concatenate lists(new list will be created to concatenate it with first one)\n");
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
                //std::cout<<"Length: ";
                //std::cin>>buffer;
                //for (int i = 0; i < base_array.GetLength(); i++) {
                //    std::cout<<"Element: ";
                //   std::cin>>buffer2;
                //    base_array.InsertAt(buffer2, i);
                //}
                //clear_input_buffer();
                break;
            case 2:
                //addition(formA, formB);
                break;
            case 3:
                std::cout<<base_array.GetLength()<<"\n";
                break;
            case 4:
                std::cout<<"Index: ";
                std::cin>>buffer;
                std::cout<<base_array.Get(buffer)<<"\n";
                clear_input_buffer();
                break;
            case 5:
                std::cout<<"New element: ";
                std::cin>>buffer;
                base_array.Prepend(buffer);
                clear_input_buffer();
                break;
            case 6:
                std::cout<<"New element: ";
                std::cin>>buffer;
                base_array.Append(buffer);
                clear_input_buffer();
                break;
            case 7:
                std::cout<<"New element: ";
                std::cin>>buffer;
                std::cout<<"Index: ";
                std::cin>>buffer2;
                base_array.InsertAt(buffer, buffer2);
                clear_input_buffer();
                break;
            case 8: {
                std::cout<<"Start index: ";
                std::cin>>buffer;
                std::cout<<"End index: ";
                std::cin>>buffer2;
                DynamicSequence<int> array_result = base_array.GetSubList(buffer, buffer2);
                for (int i = 0; i < array_result.GetLength(); i++) {
                    std::cout<<array_result.Get(i)<<"\n";
                }
                clear_input_buffer();
                break;
            }
            case 9:
                std::cout<<base_list.GetLength()<<"\n";
                break;
            case 10:
                std::cout<<"Index: ";
                std::cin>>buffer;
                std::cout<<base_list.Get(buffer)<<"\n";
                clear_input_buffer();
                break;
            case 11:
                std::cout<<"New element: ";
                std::cin>>buffer;
                base_list.Prepend(buffer);
                clear_input_buffer();
                break;
            case 12:
                std::cout<<"New element: ";
                std::cin>>buffer;
                base_list.Append(buffer);
                clear_input_buffer();
                break;
            case 13:
                std::cout<<"New element: ";
                std::cin>>buffer;
                std::cout<<"Index: ";
                std::cin>>buffer2;
                base_list.InsertAt(buffer, buffer2);
                clear_input_buffer();
                break;
            case 14: {
                std::cout<<"Start index: ";
                std::cin>>buffer;
                std::cout<<"End index: ";
                std::cin>>buffer2;
                ListSequence<int> list_result = base_list.GetSubList(buffer, buffer2);
                for (int i = 0; i < list_result.GetLength(); i++) {
                    std::cout<<list_result.Get(i)<<"\n";
                }
                clear_input_buffer();
                break;
            }
            case 15:
                std::cout<<base_list.GetFirst()<<"\n";
                break;
            case 16:
                std::cout<<base_list.GetLast()<<"\n";
                break;
            case 17:
                clear_input_buffer();
                break;
            default:
                std::cout<<"Wrong number.\n";
                break;
            case 0:
                std::cout<<"Leaving\n";
                return 0;
        }
    }
};