#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void imprimir(int vetor[], int tam){
  for(int i = 0; i < tam; i++){
    printf("[%d] ", vetor[i]);
  }
  printf("\n");
}

void merge(int* vetor, int inicio, int meio, int fim){
  int *temp, p1, p2, tamanho, i, j, k;
  int fim1 = 0, fim2 = 0;
  tamanho = fim - inicio + 1;
  p1 = inicio;
  p2 = meio + 1;
  temp = (int*)malloc(tamanho*sizeof(int));
  if(temp != NULL){
    for(i = 0; i < tamanho; i++){
      if(!fim1 && !fim2){
        if(vetor[p1] < vetor[p2])
          temp[i] = vetor[p1++];
        else
          temp[i] = vetor[p2++];
        if(p1 > meio) fim1 = 1;
        if(p2 > fim) fim2 = 1;
      }else{
        if(!fim1)
          temp[i] = vetor[p1++];
        else
          temp[i] = vetor[p2++];
      }
    }
    for(j = 0, k = inicio; j < tamanho; j++, k++)
      vetor[k] = temp[j];
  }
  free(temp);
}

void mergesort(int* vetor, int inicio, int fim){
  int meio;
  if(inicio < fim){
    meio = (inicio+fim) / 2;//floor olha apenas para a parte inteira da operação
    mergesort(vetor, inicio, meio);
    mergesort(vetor, meio + 1, fim);
    merge(vetor, inicio, meio, fim);
  }
}

int main(int argc, char const *argv[]) {
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
  printf("\n mergesort \n\n");
  imprimir(vetor, tam);
  return 0;
}
