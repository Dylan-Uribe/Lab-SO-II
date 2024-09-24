#include <stdio.h>
#include <pthread.h>
#define MAX_HILOS 10

pthread_t threads_table[MAX_HILOS];

typedef struct {
    int id;
    char *string;
}
thr_param_t;

void *thr_function(void *p) {
    thr_param_t *data = (thr_param_t *) p;

    printf("%d\n %s",data->id, data->string);

    //Devolver el valor
    pthread_exit(&data->id);
}

thr_param_t params [MAX_HILOS];
/*struct test {
    int grade_1;
    int grade_2;
    char *name;
};
*/

/*
void f(int *number) {
    *number = *number +10;
}

void f2(void number) {
    number = 20;
}*/

int main(void) {

    int i, *n;
    printf("Creating threads.....!!!!!!\n");

    for (int i = 0; i < MAX_HILOS; ++i) {
        params[i].id = i;
        params[i].string = "Hello, I'm the thread";

        pthread_create(
            &threads_table[i],
            NULL,
            thr_function,
            (void*)& params[i]
            );
    }

    printf("Threads created, waiting to end.......!!!!");

    for (int i = 0; i < MAX_HILOS; ++i) {
        pthread_join(threads_table[i], &n);

    }


    /*struct test x;

    x.name ="Dylan";
    x.grade_1 = 100;
    x.grade_2 = 90;

    printf("Name: %s\n", x.name); //Para imprimir caractéres alfanuméricos
    printf("Grade 1: %d\n", x.grade_1);
    printf("Grade 2: %d\n", x.grade_2);

    int *z = 30;

    printf("%d\n", &z);
    printf("%d", z);

    int number_1 = 10;

    int number_2 = 10;

    f(&number_1);
    f2(number_2);

    printf("%d\n", number_1);
    printf("%d\n", number_2);*/

    return 0;
}


//Paso de parámetro por referencia o valor