#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *delete(const void *arr, const unsigned size,
             const unsigned index,
             const unsigned valueSize)
{
    if(index >= size) {
        printf("Error: Index out of bounds.\n");
        return NULL;
    }

    void *newArray = malloc(size - valueSize);

    if (!newArray) {
        printf("Memory allocation failed during deletion. \n");
        return NULL;
    }

    memcpy(newArray, arr, index);
    memcpy(newArray + index, arr + index + valueSize, size-index-valueSize);

    return newArray;
}

void display(const int *arr, const int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(void)
{
    size_t arraySize = 5 *sizeof(int);
    int *array = malloc(arraySize);

    if (!array) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    const unsigned index = 3 * sizeof(int);
    int *updateArray = array;

    array[0] = 10;
    array[1] = 20;
    array[2] = 30;
    array[3] = 40;
    array[4] = 50;


    printf("Before deletion!!! \n");
    display(updateArray, arraySize/sizeof(int));

    updateArray = delete
    (
        updateArray,
        arraySize,
        index,
        sizeof(int)
    );

    if(updateArray) {
        arraySize -= sizeof(int);
        free(array);
        array = updateArray;
        printf("After insertion!!! \n");
        display(updateArray, arraySize/sizeof(int));
    }

    free(array);

    return 0;
}
