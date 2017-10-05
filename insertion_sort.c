#include "setuid0.h"

#include <stdio.h>
#include <stddef.h>

void print_both_arrays(int* array, int* sorted_array, size_t size_of_array)
{
    printf("base_array: ");
    for (size_t i = 0; i < size_of_array; ++i)
    {
        printf("%d", array[i]);
    }
    printf("\n");
    printf("sort_array: ");
    for (size_t i = 0; i < size_of_array; ++i)
    {
        printf("%d", sorted_array[i]);
    }
    printf("\n");
    printf("debugging mode activated; press ENTER key to continue\n");
    getchar();
}

void shift_array_right(int* array, int* sorted_array, size_t j, size_t filling_status, size_t size_of_array)
{
    printf("\n");
    printf("-----> let's shift:\n");
    printf("\n");
    size_t stop_shift = j;
    for (size_t current_shift = filling_status; stop_shift < current_shift; --current_shift)
    {
        printf("current_shift: %zu\n", current_shift);
        printf("stop_shift: %zu\n", stop_shift);
        printf("filling_status: %zu\n", filling_status);
        printf("old_pos: %zu\n", current_shift - 1);
        printf("new_pos: %zu\n", current_shift);
        printf("\n");
        print_both_arrays(array, sorted_array, size_of_array);
        sorted_array[current_shift] = sorted_array[current_shift - 1];
    }
    printf("<----- shift ended\n");
    printf("\n");
    print_both_arrays(array, sorted_array, size_of_array);
}

void insert(int* array, int* sorted_array, int digit, size_t filling_status, size_t size_of_array)
{
    for (size_t j = 0; j < filling_status; ++j)
    {
        printf("insert_position_candidate: %zu\n", j);
        if(digit < sorted_array[j])
        {
            shift_array_right(array, sorted_array, j, filling_status, size_of_array);
            sorted_array[j] = digit;
            print_both_arrays(array, sorted_array, size_of_array);
            return;
        }
    }
    printf("\n");
    printf("digit is bigger than all previous; push back\n");
    printf("\n");
    sorted_array[filling_status] = digit;
    print_both_arrays(array, sorted_array, size_of_array);
}

void insertion_sort(int* array, int* sorted_array, size_t size_of_array)
{
    sorted_array[0] = array[0];
    print_both_arrays(array, sorted_array, size_of_array);
    printf("`^*+.congratulations, insertion of digit 0 with value %d was successfull\n", array[0]);
    printf("\n");
    for (size_t i = 1; i < size_of_array; ++i)
    {
        insert(array, sorted_array, array[i], i, size_of_array);
        printf("`^*+.congratulations, insertion of digit %zu with value %d was successfull\n", i, array[i]);
        printf("\n");
    }
    print_both_arrays(array, sorted_array, size_of_array);
}

int main()
{
    int array[] = {7, 4, 5, 2, 1, 9, 8, 3, 6, 1};
    size_t size_of_array = ARRAY_SIZE(array);
    int sorted_array[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    print_both_arrays(array, sorted_array, size_of_array);
    insertion_sort(array, sorted_array, size_of_array);
    print_both_arrays(array, sorted_array, size_of_array);
}

