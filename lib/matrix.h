#ifndef MATRIX_H_INCLUDED
#define MATRIX_H_INCLUDED

struct matrix_struct
{
    int** matrix;
    int height;
    int width;
};

void print_array(int* array_print, int width)
{
    for(int i = 0; i < width; i++){
        if(i == 0){
            cout << "[";
        }
        if(i == width - 1){
            cout << array_print[i] << "]";
        }else{
            cout << array_print[i] << ",";
        }
    }

    cout << endl;
}

void print_matrix(matrix_struct* matrix_print)
{
    for(int i = 0; i < matrix_print->height; i++){
        print_array(matrix_print->matrix[i], matrix_print->width);
    }

    cout << endl;
}

int* generate_array(int width)
{
    int* new_array = new int[width];

    for(int i = 0; i < width; i++){
        new_array[i] = rand() % 5;
    }

    return new_array;
}

matrix_struct* generate_matrix(int height, int width)
{
    matrix_struct* new_matrix = new matrix_struct;

    new_matrix->matrix = new int*[height];
    new_matrix->height = height;
    new_matrix->width = width;

    for(int i = 0; i < new_matrix->height; i++){
        new_matrix->matrix[i] = generate_array(new_matrix->width);
    }

    return new_matrix;
}

matrix_struct* multiply_matrix(matrix_struct* matrix_a, matrix_struct* matrix_b)
{
    matrix_struct* multiplied_matrix = generate_matrix(matrix_a->height, matrix_b->width);

    for(int i = 0; i < multiplied_matrix->height; i++){
        for(int j = 0; j < multiplied_matrix->width; j++){
            multiplied_matrix->matrix[i][j] = 0;

            for(int k = 0; k < matrix_a->height + 1; k++){
                multiplied_matrix->matrix[i][j] += matrix_a->matrix[i][k] * matrix_b->matrix[k][j];
            }
        }
    }

    return multiplied_matrix;
}

#endif // MATRIX_H_INCLUDED
