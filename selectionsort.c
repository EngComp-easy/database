#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void imprime(int vetor[], int tam){
  for(int i = 0; i<tam; i++){
    printf("[%d], ", vetor[i]);
  }
  printf("\n");
}

void troca(int *a, int *b){
  int aux = *a;
  *a = *b;
  *b = aux;
}

void selectionsort(int vetor[], int tam){
  int min;
  //Limite de movimento um por um
  for(int i = 0; i < tam; i++){
    //minimo elemento do vetor
    min = i;
    for(int j = 0; j < tam; j++){
      if(vetor[j] < vetor[min]){
        min = j;
      }
      troca(&vetor[min], &vetor[i]);
    }
  }
}

int main(){
  srand(time(NULL));
  int vetor[10], tam = 10;
  for(int i = 0; i<10; i++){
    vetor[i] = rand() % 100;
  }
  imprime(vetor, tam);
  selectionsort(vetor, tam);
  imprime(vetor, tam);
}
