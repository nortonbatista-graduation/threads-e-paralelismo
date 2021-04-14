#include <iostream>
#include <chrono>
#include <time.h>
#include <pthread.h>
#include "lib/timer.h"

using namespace std;

// g++ sum_array_elements_single_thread.cpp -o sum_array_elements_single_thread
// ./sum_array_elements_single_thread

const int array_size = 160000;
float array[array_size] = { 0 };

void fill_array(){
  for (int i = 0; i < array_size; i++) {  
    array[i] = i;  
    // cout << array[i] << endl;
  }
}

int main(){
  float sum = 0;  

  srand(time(NULL));
  
  fill_array();

  auto start = now();
  for (int i = 0; i < array_size; i++){
    sum += array[i];
    // cout << "posicao " << i << ", valor:" << array[i] << endl;
  }
  auto finish = now();

  double elapsed_time_s = convert_to_seconds(elapsed_time(start, finish));

  cout << "Tempo decorrido Single Thread: " << elapsed_time_s << endl;
  cout << "Total das somas Single Thread: " << sum << endl;

	return 0;
}