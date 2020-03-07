#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

bool existe(int valores[], int tam, int valor){
  for(int i = 0; i < tam; i++){
    if(valores[i] == valor)
      return true;
  }
  return false;
}

void imprime(int vetor[], int tam){
  for(int i = 0; i<tam; i++){
    printf("[%d] ", vetor[i]);
  }
  printf("\n");
}

void substitui(int *a, int *b){
  int aux = *a;
  *a = *b;
  *b = aux;
}

void bubblesort(int vetor[], int tam){
  bool marilinda = true;
  while(marilinda == true){
    marilinda = false;
    for(int i = 0; i < tam - 1; i++){
      if(vetor[i] > vetor[i + 1]){
        substitui(&vetor[i], &vetor[i+1]);
        marilinda = true;
      }
    }
    tam--;
  }
  printf("Bubblesort--> ");
}

void selectionsort(int vetor[], int tam){
  int min = 0;
  for(int i = 0; i < tam; i++){
    min = i;
    for(int j = 0; j < tam; j++){
      if(vetor[j] < vetor[min]){
        min = j;
      }
      substitui(&vetor[i], &vetor[min]);
    }
  }
  printf("Selectionsort--> ");
}

void gerar_aleatorios(int vetor[], int tam){
  srand(time(NULL));
  int verifica;
  for(int i = 0; i < tam; i++){
    verifica = rand() % 1000;
    while(existe(vetor, i, verifica)){
      verifica = rand() % 1000;
    }
    vetor[i] = verifica;
  }
  printf("Vetor aleatório--> ");
}

int main(){
  int tam = 10;
  int vetor[tam];
  gerar_aleatorios(vetor, tam);//função para gerar vetor aleatório sem valores repetidos
  imprime(vetor, tam);//função para imprimir vetor
  printf("\n\n");
  bubblesort(vetor, tam);
  imprime(vetor, tam);
  printf("\n\n");
  selectionsort(vetor, tam);
  imprime(vetor, tam);
  return 0;
}
