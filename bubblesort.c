#include <stdio.h>
#include <stdlib.h>

void imprime(int vetor[], int tam){
  for(int i = 0; i<tam; i++){
    printf("%d, ", vetor[i]);
  }
  printf("\n");
}

void bubblesort(int vetor[], int tam){
  int aux;
  for(int k = 0; k < tam; k++){
    for(int i = 0; i < tam - 1; i++){
      if(vetor[i] > vetor[i+1]){
        aux = vetor[i];
        vetor[i] = vetor[i + 1];
        vetor[i + 1] = aux;
      }
    }
  }
}


int main(){
  int vetor[10] = {9, 13, 5, 67, 89, 96, 34, 53, 6, 10};
  imprime(vetor, 10);
  bubblesort(vetor, 10);
  imprime(vetor, 10);
  return 0;
}
