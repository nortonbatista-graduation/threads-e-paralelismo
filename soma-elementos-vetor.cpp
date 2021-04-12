#include <time.h>
#include <stdio.h>
#include <stdlib.h>

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
    printf("vetor %d: %f\n", i, vetor[i]);
  }

  //imprime o valor da soma
  printf("Soma: %f\n", soma);
}