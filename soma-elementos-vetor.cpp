#include <iostream>
#include <time.h>

using namespace std;

int main(){
  int tamanho_vetor = 10;
  float soma = 0;
  float vetor[tamanho_vetor];

  //preenche os valores no vetor
  for (int i = 0; i < tamanho_vetor; i++) {  
    vetor[i] = i;  
  }
  
  //soma todos os valores do vetor e imprime cada valor
  for(int i = 0; i < tamanho_vetor; i++){
    soma += vetor[i];
    cout << "vetor " << i << ":" << vetor[i] << endl;
  }

  //imprime o valor da soma
  cout << "Soma: " << soma << endl;
}