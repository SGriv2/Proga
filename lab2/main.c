#include <stdio.h>

#include "IntVector.h"

int main(){
    IntVector *tmp = int_vector_new(5);
    if (tmp != NULL){
        print_data(tmp);
        printf(" _________________\n");
        printf("|Capacity: %d      |\n", vector_get_capacity(tmp));
        printf("|Size: %d          |\n", vector_get_size(tmp));
        printf("|__________________|\n");

        for (int i=0; i<tmp->capacity; i++){
            int element = i+1;
            vector_set_item(tmp, i, element);
        }

        int index = 3;
        int element = vector_get_item(tmp, index);
        printf("Element in index {%d} = %d\n", index, element);

        index = 4;
        element = 5;
        vector_set_item(tmp, index, element);
        print_data(tmp);
        vector_set_item(tmp, 1, 2);
        print_data(tmp);

        printf("\n");
        int response = int_vector_push_back(tmp, 3);
        if (response == 0){
            print_data(tmp);
        }
        else{
            printf("Error in called function 'push_back'\n");
        }

        printf(" ________________\n");
        printf("|Capacity: %d     |\n", vector_get_capacity(tmp));
        printf("|Size: %d         |\n", vector_get_size(tmp));
        printf("|________________|\n");
        int_vector_pop_back(tmp);
        print_data(tmp);
        printf(" ________________\n");
        printf("|Capacity: %d     |\n", vector_get_capacity(tmp));
        printf("|Size: %d         |\n", vector_get_size(tmp));
        printf("|________________|\n");
        int_vector_shrink_to_fit(tmp);
        print_data(tmp);
        printf(" ________________\n");
        printf("|Capacity: %d     |\n", vector_get_capacity(tmp));
        printf("|Size: %d         |\n", vector_get_size(tmp));
        printf("|________________|\n");

        int_vector_reserve(tmp, 10);
        print_data(tmp);
        printf(" ________________\n");
        printf("|Capacity: %d     |\n", vector_get_capacity(tmp));
        printf("|Size: %d         |\n", vector_get_size(tmp));
        printf("|________________|\n");       

        int_vector_resize(tmp, 7);
        print_data(tmp);
        printf(" ________________\n");
        printf("|Capacity: %d     |\n", vector_get_capacity(tmp));
        printf("|Size: %d         |\n", vector_get_size(tmp));
        printf("|________________|\n");       

        IntVector *copy_vector = int_vector_copy(tmp);
        print_data(copy_vector);
        printf(" ________________\n");
        printf("|Capacity: %d     |\n", vector_get_capacity(copy_vector));
        printf("|Size: %d         |\n", vector_get_size(copy_vector));
        printf("|________________|\n");  


        int_vector_free(copy_vector);
        int_vector_free(tmp);
    }
    
    return 0;
}