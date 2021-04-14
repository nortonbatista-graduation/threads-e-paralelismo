#include <iostream>
#include <chrono>
#include <time.h>
#include <pthread.h>
#include "lib/timer.h"

using namespace std;

// g++ sum_array_elements_pthread.cpp -o sum_array_elements_pthread -pthread
// ./sum_array_elements_pthread

// index of divided array
const int cont_parts_divided = 4;
const int array_size = 160000;
int index = 0;
float array[array_size] = { 0 };
float sum[cont_parts_divided] = { 0 };  

void fill_array(){
  for (int i = 0; i < array_size; i++) {  
    array[i] = i;  
  }
}

void *sum_array_elements(void *vargp){
  //sum all values and print them
  int thread_part = index++;
  int i = 0;
  
    // Each thread computes sum of 1/4th of array

  for (i = thread_part * (array_size / cont_parts_divided); i < (thread_part + 1) * (array_size / cont_parts_divided); i++){
    sum[thread_part] += array[i];
    // cout << "posicao " << i << ", valor:" << array[i] << endl;
  }
  
  //prints value of sum
  // cout << "sum["<< thread_part <<"]: " << sum[thread_part] << endl;
}

int main(){
  srand(time(NULL));
  
  float total_sum = 0;
  pthread_t threads[cont_parts_divided];

  fill_array();

  auto start = now();
  for( int i = 0; i < cont_parts_divided; i++ ) {
    // cout << "main(): creating thread, " << i << endl;
    pthread_create(&threads[i], NULL, sum_array_elements, (void *)threads[i]);
  }

  //joins all threads and waiting for them to complete
  for (int i = 0; i < cont_parts_divided; i++){
    pthread_join(threads[i], NULL);
  }
  auto finish = now();

  for (int i = 0; i < cont_parts_divided; i++){
    total_sum += sum[i];
  }

  double elapsed_time_s = convert_to_seconds(elapsed_time(start, finish));

  cout << "Tempo decorrido PThread: " << elapsed_time_s << endl;
  cout << "Total das somas PThread: " << total_sum << endl;

	return 0;
}