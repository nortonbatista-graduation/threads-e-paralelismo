#include <iostream>
#include <chrono>
#include <time.h>
#include <pthread.h>
#include "../lib/timer.h"

using namespace std;

// how to compile:
// g++ ./sum_array_elements/multi_threads_pthread.cpp -o ./sum_array_elements/multi_threads_pthread -pthread
// ./sum_array_elements/multi_threads_pthread

#define ARRAY_SIZE 16000
const int cont_threads = 4;
int index = 0;
long long int array[ARRAY_SIZE] = { 0 };
float sum[4] = { 0 };  

void fill_array(){
  for (int i = 0; i < ARRAY_SIZE; i++) {  
    array[i] = i;
    // cout <<  array[i] << endl;
  }
}

void *sum_array_elements(void *vargp){
  //sum all values and print them
  int thread_part = index++;
  
  // each thread computes sum of 1/4th of array
  for (int i = thread_part * (ARRAY_SIZE / 4); i < (thread_part + 1) * (ARRAY_SIZE / 4); i++){
    sum[thread_part] += array[i];
    // cout << "posicao " << i << ", valor:" << array[i] << endl;
  }
  
  //prints value of sum
  // cout << "sum["<< thread_part <<"]: " << sum[thread_part] << endl;
}

int main(){
  srand(time(NULL));
  
  fill_array();
  float total_sum = 0;
  pthread_t threads[cont_threads];

  auto start = now();
  for(int i = 0; i < cont_threads; i++) {
    // cout << "main(): creating thread, " << i << endl;
    pthread_create(&threads[i], NULL, sum_array_elements, (void *)NULL);
  }

  //joins all threads and waiting for them to complete
  for (int i = 0; i < cont_threads; i++){
    pthread_join(threads[i], NULL);
  }

  for (int i = 0; i < cont_threads; i++){
    total_sum += sum[i];
  }

  auto finish = now();
  double elapsed_time_s = convert_to_seconds(elapsed_time(start, finish));

  cout << "Tempo decorrido Multiple PThread: " << elapsed_time_s << endl;
  cout << "Total das somas Multiple PThread: " << total_sum << endl;

	return 0;
}