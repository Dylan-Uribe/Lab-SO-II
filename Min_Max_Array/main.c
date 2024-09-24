#include <stdio.h>

void find_min_max(const int *ptr, const int size, int *max, int *min) {

    *min = *ptr;
    *max = *ptr;

    for (int i = 0; i < size; i++) {
        if (ptr[i] < *min) {
            *min = ptr[i];
        }
        if (ptr[i] > *max) {
            *max = ptr[i];
        }
    }
}

int main()
{
    const int numbers[] = {50,40,30,10,25};

    const int size = sizeof(numbers) / sizeof(numbers[0]);

    int min, max;

    find_min_max(numbers, size, &max, &min);

    printf("El valor minimo del array es: %d \n", min);
    printf("El valor maximo del array es: %d \n", max);

    return 0;
}