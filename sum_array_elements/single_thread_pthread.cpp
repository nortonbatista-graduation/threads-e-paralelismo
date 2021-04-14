#include <iostream>
#include <chrono>
#include <time.h>
#include <pthread.h>
#include "../lib/timer.h"

using namespace std;

// how to compile:
// g++ ./sum_array_elements/single_thread_pthread.cpp -o ./sum_array_elements/single_thread_pthread -pthread
// ./sum_array_elements/single_thread_pthread

const int array_size = 160000;
long long int array[array_size] = { 0 };
float sum = 0;

void fill_array(){
  for (int i = 0; i < array_size; i++) {  
    array[i] = i;  
    // cout << array[i] << endl;
  }
}

void* sum_array_elements(void *vargp){
  for (int i = 0; i < array_size; i++){
    sum += array[i];
    // cout << "posicao " << i << ", valor:" << array[i] << endl;
  }
}

int main(){
  pthread_t thread_id;

  srand(time(NULL));
  
  fill_array();

  auto start = now();
  pthread_create(&thread_id, NULL, sum_array_elements, NULL);
  pthread_join(thread_id, NULL);
  auto finish = now();

  double elapsed_time_s = convert_to_seconds(elapsed_time(start, finish));

  cout << "Tempo decorrido Single PThread: " << elapsed_time_s << endl;
  cout << "Total das somas Single PThread: " << sum << endl;

	return 0;
}