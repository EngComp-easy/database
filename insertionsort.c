#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void imprime(int vetor[], int tam){
  for(int i = 0; i < tam; i++){
    printf("[%d] ", vetor[i]);
  }
  printf("\n");
}

void insertionsort(int vetor[], int tam){
    int aux, j;
    for(int i = 0; i < tam; i++){
      aux = vetor[i];
      j = i - 1;
      while(j >= 0 && vetor[j] > aux){
        vetor[j + 1] = vetor [j];
        j = j - 1;
      }
      vetor[j + 1] = aux;
    }
}

int main(int argc, char const *argv[]) {
  srand(time(NULL));
  int tam = 10;
  int vetor[tam];
  for(int i = 0; i < tam; i++){
    vetor[i] = rand() % 100;
  }
  imprime(vetor, tam);
  insertionsort(vetor, tam);
  imprime(vetor, tam);

  return 0;
}
