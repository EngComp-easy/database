#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void imprimir(int vetor[], int tam){
  for(int i = 0; i < tam; i++){
    printf("%d", vetor[i]);
  }
  printf("\n");
}

void merge(int* vetor, int inicio, int meio, int fim){
  int* aux = NULL;
  aux = malloc(sizeof(int));
  aux = vetor;
  
}

void mergesort(int* vetor, int inicio, int fim){
  int meio = ((fim + 1) / 2) - 1;
  for(int i = inicio; i < meio; i++){
    mergesort(vetor, inicio, meio);
  }
  merge(vetor, inicio, meio, fim);
}

int int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int tam = 8;
  int vetor[tam];
  for(int i = 0; i < tam; i++){
    vetor[i] = rand() % 100;
  }
  imprimir(vetor, tam);
  int inicio = 0;
  int fim = tam - 1;
  mergesort(vetor, inicio, fim);
  return 0;
}
