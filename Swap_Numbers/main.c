#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swapints (int *a, int *b) {

    const int temp = *a;
    *a = *b;
    *b = temp;
}

void swapIntsNoThird1(int *a, int *b) {

    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;

}

void swapIntsNoThird2(int *a, int *b) {

    *a = *a * *b;
    *b = *a / *b;
    *a = *a / *b;

}

void genericSwap(void *a, void *b, size_t size) {

    void *temp = malloc(size);

    if(temp == NULL) {
        return;
    }

    //memcpy(dest, src, n(size))
    memcpy(temp, a, size); // -> copy "a" value to "temp"
    memcpy(a, b, size); // -> copy "b" value to "a"
    memcpy(b, temp, size); // -> copy "temp" value to "b"

    free(temp);
    
}

int main(void) {

    int a = 10;
    int b = 20;

    printf("EJERCICIO 1 \n");

    printf("------------------ \n");

    printf("BEFORE SWAP!! \n");

    printf("El valor de a es: %d \n", a);
    printf("El valor de b es: %d \n", b);

    swapints(&a,&b);

    printf("AFTER SWAP!! \n");

    printf("El valor de a es: %d \n", a);
    printf("El valor de b es: %d \n", b);

    printf("------------------ \n");

    printf("EJERCICIO 2 \n");

    printf("------------------ \n");

    printf("BEFORE SWAP!! \n");

    printf("El valor de a es: %d \n", a);
    printf("El valor de b es: %d \n", b);

    swapIntsNoThird1(&a,&b);

    printf("AFTER SWAP!! \n");

    printf("El valor de a es: %d \n", a);
    printf("El valor de b es: %d \n", b);

    printf("------------------ \n");

    printf("EJERCICIO 3 \n");

    printf("------------------ \n");

    printf("BEFORE SWAP!! \n");

    printf("El valor de a es: %d \n", a);
    printf("El valor de b es: %d \n", b);

    swapIntsNoThird2(&a,&b);

    printf("AFTER SWAP!! \n");

    printf("El valor de a es: %d \n", a);
    printf("El valor de b es: %d \n", b);

    printf("------------------ \n");

    printf("EJERCICIO 4 \n");
    printf("------------------ \n");

    printf("BEFORE SWAP!! \n");

    printf("El valor de a es: %d \n", a);
    printf("El valor de b es: %d \n", b);

    genericSwap(&a,&b, sizeof(int));

    printf("AFTER SWAP!! \n");

    printf("El valor de a es: %d \n", a);
    printf("El valor de b es: %d \n", b);

    return 0;
}
