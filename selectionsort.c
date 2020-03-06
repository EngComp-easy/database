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

void selectionsort(int vetor[], int tam){
  /*int x = 0;
  int aux, menor = vetor[x];
  while(tam != 0){ //procura menor
    if(menor > vetor[x + 1]){
      menor = vetor[x + 1];
    }
    tam--;
    x++;
  }//achou menor
  */
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
