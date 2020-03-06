#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void imprime(int vetor[], int tam){
  for(int i = 0; i<tam; i++){
    printf("%d, ", vetor[i]);
  }
  printf("\n");
}

void bubblesort(int vetor[], int tam){
  int aux, k;
  bool trocou = true;
  while(trocou == true){
    trocou = false;
    for(int i = 0; i < tam - 1; i++){
      if(vetor[i] > vetor[i+1]){
        aux = vetor[i];
        vetor[i] = vetor[i + 1];
        vetor[i + 1] = aux;
        trocou = true;
      }//if
    }//for
  }
}

int main(){
  srand (time(NULL));
  int vetor[10];
  for(int i = 0; i<10; i++){
    vetor[i]=rand() % 100;
  }
  imprime(vetor, 10);
  bubblesort(vetor, 10);
  imprime(vetor, 10);
  return 0;
}
