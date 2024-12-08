#include <stdio.h>
#include <stdlib.h>

#define LOCATION_ID_LENGTH 1000

// I think I need to use the * operator to note to the compiler that this is a list not a single int...
void location_id_as_lists(int *list_one, int *list_two, int *current_list_index) {
    // fopen returns a pointer to the FILE - FILE is a struct assembled by the fopen functoin
    FILE *file = fopen("input.txt", "r");
    while(*current_list_index < 1000) {
        //fscanf is doing a lot of work here ignoring whitespace and linebreaks
        fscanf(file, "%d %d", &list_one[*current_list_index], &list_two[*current_list_index]);
        (*current_list_index)++;
    }
    return;
}

//lil baby bubble sort
void bubble_sort(int *list, int length_of_array) {
    int length = length_of_array - 1;
    //out loop keeps track of trips through the list
    //we'll only have to make as many loops through the list in the outer loop as the list is long - 1
    for(int loop_count = 0; loop_count < length; loop_count++) {
        //inner loop ensures the largest item will "bubble up" to the end of the list each time through
        //it compares two entries and moves the larger of two to a higher index
        for(int current_index = 0; current_index < length - loop_count; current_index++){
            if(list[current_index] > list[current_index + 1]) {
                int temp_value = list[current_index];
                list[current_index] = list[current_index + 1];
                list[current_index + 1] = temp_value;
            }
        }
    }
}

//compare and sum
int compare_and_sum(int *list_one, int *list_two, int length) {
    int sum = 0;
    int difference = 0;
    for(int i = 0; i < length; i++) {
        int difference = list_one[i] - list_two[i];
        if (difference < 0) {
            difference = -difference;
        }
        sum += difference;
    }
    return sum;
}


int main(void) {
    int list_one[LOCATION_ID_LENGTH];
    int list_two[LOCATION_ID_LENGTH];

    int current_list_index = 0;
    int *ptr_current_list_index = &current_list_index;

    int difference = 0;

    //args are defined in this as pointers but here are just the names of list_one and list_two
    //C treats the variable name of a list as the pointer to the first element
    //list[0] == *list
    location_id_as_lists(list_one, list_two, ptr_current_list_index);
    bubble_sort(list_one, LOCATION_ID_LENGTH);
    bubble_sort(list_two, LOCATION_ID_LENGTH);

    difference = compare_and_sum(list_one, list_two, LOCATION_ID_LENGTH);

    return 0;
}