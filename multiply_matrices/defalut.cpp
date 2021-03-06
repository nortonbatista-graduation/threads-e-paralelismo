#include <iostream>
#include <chrono>
#include "lib/timer.h"
#include "lib/matrix.h"

using namespace std;

int main()
{
    srand(time(NULL));

    int width = 3;
    int height = 2;

    matrix_struct* matrix_a = generate_matrix(height, width);
    matrix_struct* matrix_b = generate_matrix(width, height);
    matrix_struct* multiplied_matrix = generate_matrix(height, width);

    cout << "Matrix A" << endl;

    print_matrix(matrix_a);

    cout << "Matrix B" << endl;

    print_matrix(matrix_b);

    cout << "Multiplied Matrices" << endl;

    auto start = now();

    multiplied_matrix = multiply_matrix(matrix_a, matrix_b);

    auto finish = now();
    double elapsed_time_s = convert_to_seconds(elapsed_time(start, finish));

    print_matrix(multiplied_matrix);

    cout << elapsed_time_s;

    return 0;
}
