#include <stdio.h>
#include <stdlib.h>

void swap_rows(void **array, const int row_1, const int row_2) {
    void *temp = array[row_1];
    array[row_1] = array[row_2];
    array[row_2] = temp;
}

void swap_columns(int **array, const int rows, const int col_1, const int col_2) {
    for(int i = 0; i < rows; i++) {
        const int temp = array[i][col_1];
        array[i][col_1] = array[i][col_2];
        array[i][col_2] = temp;
    }
}

void display(int **array, const int rows, const int cols) {
    printf("Displaying the 2D array:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("%d ", array[i][j]);
        }
        printf("\n");
    }
}

void fill_matrix(int **array, const int rows, const int cols, int start_number) {
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            array[i][j] = start_number++;
        }
    }
}

int **create_matrix(const int rows, const int cols) {

    int **array = malloc(rows * sizeof(int *));

    if(array == NULL) {
        printf("Memory allocation failed for rows.\n");
        return NULL;
    }

    for(int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));

        if (array[i] == NULL) {
            printf("Memory allocation failed for columns in row %d.\n", i);
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return NULL;
        }
    }

    return array;
}

int **create_lower_triangular(const int rows) {

    int **array = malloc(rows * sizeof(int*));

    if(array == NULL) {
        printf("Memory allocation failed for rows.\n");
        return NULL;
    }

    for(int i = 0; i < rows; i++) {
        array[i] = (int *)malloc(i + 1 * sizeof(int));

        if (array[i] == NULL) {
            printf("Memory allocation failed for columns in row %d.\n", i);
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return NULL;
        }
    }

    return array;
}

void fill_lower_triangular(int **array, const int rows, int start_number) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j <= i; j++) {
            array[i][j] = start_number++;
        }
    }
}

void display_lower_triangular(int **array, const int rows) {
    printf("Displaying the lower triangular matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            if (j <= i) {
                printf("%d ", array[i][j]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int **create_upper_triangular(const int rows) {

    int **array = malloc(rows * sizeof(int*));

    if(array == NULL) {
        printf("Memory allocation failed for rows.\n");
        return NULL;
    }

    for(int i = 0; i < rows; i++) {
        array[i] = (int *)malloc((rows - i) * sizeof(int));

        if (array[i] == NULL) {
            printf("Memory allocation failed for columns in row %d.\n", i);
            for (int j = 0; j < i; j++) {
                free(array[j]);
            }
            free(array);
            return NULL;
        }
    }

    return array;
}

void fill_upper_triangular(int **array, const int rows, int start_number) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows - i; j++) {
            array[i][j] = start_number++;
        }
    }
}

void display_upper_triangular(int **array, const int rows) {
    printf("Displaying the lower triangular matrix:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < rows; j++) {
            if (j >= i) {
                printf("%d ", array[i][j - i]);
            } else {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {

    int rows, cols;

    printf("CREATING MATRIX!!!\n");

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    int start_number;

    printf("Enter the starting number to fill the matrix: ");
    scanf("%d", &start_number);

    int **array =  create_matrix(rows, cols);

    if(array ==NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    fill_matrix(array, rows, cols, start_number);

    printf("\nThe 2D array before swapping rows 0 and 1:\n");
    display(array, rows, cols);

    swap_rows((void **)array, 0, 1);

    printf("\nThe 2D array after swapping rows 0 and 1:\n");
    display(array, rows, cols);

    swap_columns(array, rows, 0, 2);

    printf("\nThe 2D array after swapping columns 0 and 2:\n");
    display(array, rows, cols);

    for(int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    //-------------------------------------------------------------------
    printf("CREATING LOWER TRIANGULAR MATRIX\n");
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    int **lower_triangular_matrix = create_lower_triangular(rows);

    if(lower_triangular_matrix == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the starting number to fill the lower triangular matrix: ");
    scanf("%d", &start_number);

    fill_lower_triangular(lower_triangular_matrix, rows, start_number);

    display_lower_triangular(lower_triangular_matrix, rows);

    for(int i = 0; i < rows; i++) {
        free(lower_triangular_matrix[i]);
    }
    free(lower_triangular_matrix);

    //------------------------------------------------------
    printf("CREATING UPPER TRIANGULAR MATRIX\n");
    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    int **upper_triangular_matrix = create_upper_triangular(rows);

    if(upper_triangular_matrix == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter the starting number to fill the upper triangular matrix: ");
    scanf("%d", &start_number);

    fill_upper_triangular(upper_triangular_matrix, rows, start_number);

    display_upper_triangular(upper_triangular_matrix, rows);

    for(int i = 0; i < rows; i++) {
        free(upper_triangular_matrix[i]);
    }
    free(upper_triangular_matrix);

    return 0;
}
