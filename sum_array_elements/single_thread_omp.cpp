#include <iostream>
#include <chrono>
#include <time.h>
#include <omp.h>
#include "../lib/timer.h"

using namespace std;

// how to compile:
// g++ ./sum_array_elements/single_thread_omp.cpp -o ./sum_array_elements/single_thread_omp -fopenmp
// ./sum_array_elements/single_thread_omp

const int array_size = 150000;
int array[array_size] = { 0 };

void fill_array(){
  for (int i = 0; i < array_size; i++) {  
    array[i] = i;  
  }
}

int main(){
  float sum = 0;  

  srand(time(NULL));
  
  fill_array();

  auto start = now();
  #pragma omp single
    for (int i = 0; i < array_size; i++){
      sum += array[i];
    }

  auto finish = now();

  double elapsed_time_s = convert_to_seconds(elapsed_time(start, finish));

  std::cout << "Tempo decorrido Single Thread OpenMP: " << elapsed_time_s << endl;
  std::cout << "Total das somas Single Thread OpenMP: " << sum << endl;

	return 0;
}