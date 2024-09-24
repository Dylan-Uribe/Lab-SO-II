#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void *insert(const void *arr, const size_t size,
             const size_t index, const void *value,
             const size_t valueSize) {

    if (index > size) {
        printf("Error: Index out of bounds.\n");
        return NULL;
    }

    void *newArray = malloc(size + valueSize);
    if (!(int)newArray) {
        printf("Memory allocation failed during insertion.\n");
        return NULL;
    }

    memcpy(newArray, arr, index);
    memcpy(newArray + index, value, valueSize);
    memcpy(newArray + index + valueSize, arr + index, size - index);

    return newArray;
}

void *delete(const void *arr, const size_t size,
             const size_t index, const size_t valueSize) {

    if (index >= size) {
        printf("Error: Index out of bounds.\n");
        return NULL;
    }

    void *newArray = malloc(size - valueSize);
    if (!(int)newArray) {
        printf("Memory allocation failed during deletion.\n");
        return NULL;
    }

    memcpy(newArray, arr, index);
    memcpy(newArray + index, arr + index + valueSize, size - index - valueSize);

    return newArray;
}

void display(const int *arr, size_t size) {
    for (size_t i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void menu() {
    printf("Menu:\n");
    printf("1. Create array\n");
    printf("2. Insert value\n");
    printf("3. Delete value\n");
    printf("4. Display array\n");
    printf("5. Exit\n");
}

int main(void) {
    size_t arraySize = 5 * sizeof(int);
    int *array = malloc(arraySize);
    if (!(int)array) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Inicializar array con valores predeterminados
    for (int i = 0; i < 5; i++) {
        array[i] = (i + 1) * 10;
    }

    int choice, index;
    int value;
    int *updatedArray = NULL;

    while (1) {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Enter new array size (number of elements): ");
                int newSize;
                scanf("%d", &newSize);
                arraySize = newSize * sizeof(int);
                free(array);
                array = malloc(arraySize);
                if (!(int)array) {
                    printf("Memory allocation failed.\n");
                    return 1;
                }
                printf("Enter %d values:\n", newSize);
                for (int i = 0; i < newSize; i++) {
                    scanf("%d", &array[i]);
                }
                break;
            }

            case 2: {
                printf("Enter the index to insert at: ");
                scanf("%d", &index);
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                updatedArray = insert(array, arraySize, index * sizeof(int), &value, sizeof(int));
                if (updatedArray) {
                    free(array);
                    array = updatedArray;
                    arraySize += sizeof(int);
                }
                break;
            }

            case 3: {
                printf("Enter the index to delete from: ");
                scanf("%d", &index);
                updatedArray = delete(array, arraySize, index * sizeof(int), sizeof(int));
                if (updatedArray) {
                    free(array);
                    array = updatedArray;
                    arraySize -= sizeof(int);
                }
                break;
            }

            case 4: {
                printf("Current array values:\n");
                display(array, arraySize / sizeof(int));
                break;
            }

            case 5:
                free(array);
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    }
}
