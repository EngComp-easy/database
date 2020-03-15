#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/////////////////////MERGESORT//////////////////////////////////////////////////
void exibeVetor(int* vetor, int tam){
  printf("vetor:");
  for(int x=0; x<tam; x++){
    printf("%i,", vetor[x]);
  }//for
}//exibeVetor
////////////////////////////////////////////////////////////////////////////////
void merge(int vetorzinho[], int inicio, int meio, int fim){
  int inicio_auxiliar=inicio;//para nao perder o valor da variavel
  int tam = fim - inicio + 1;
  int segundo_comeco= meio + 1;
  int tamanho_auxiliar=0;
  int* vetorzinho_auxiliar = (int*)malloc(tam *sizeof(int));
  while((inicio_auxiliar <= meio) && (segundo_comeco <= fim)){//enquanto nao terminar a comparaçao de dois vetores
    if(vetorzinho[inicio_auxiliar] < vetorzinho[segundo_comeco]){//comparando o conteudo do indice de cada vetor
      vetorzinho_auxiliar[tamanho_auxiliar] = vetorzinho[inicio_auxiliar];//colocando o menor conteudo no vetor auxiliar
      inicio_auxiliar++;//o menor elemento pego do vetor tal, é do vetor tal que se acrescenta indice para comparar o prox
    } else {//aqui ocorre o contrario
      vetorzinho_auxiliar[tamanho_auxiliar] = vetorzinho[segundo_comeco];
      segundo_comeco++;
    }//ifelse
    tamanho_auxiliar++;//para colocar um proximo conteudo no vetor auxiliar, acrescenta seu indice
  }//while
  while(inicio_auxiliar <= meio){// se sobrar elementos na primeira metade do vetor, eles ja ordenados, serao copiados p/ o vetor aux
    vetorzinho_auxiliar[tamanho_auxiliar] = vetorzinho[inicio_auxiliar];
    tamanho_auxiliar++;
    inicio_auxiliar++;
  }//while
  while(segundo_comeco <= fim){//se sobrar elementos na segunda metade do vetor
    vetorzinho_auxiliar[tamanho_auxiliar] = vetorzinho[segundo_comeco];
    tamanho_auxiliar++;
    segundo_comeco++;
  }//while
  for(tamanho_auxiliar = inicio; tamanho_auxiliar <= fim; tamanho_auxiliar++){//copiando o vetor auxiliar ordenado para o vetor original
    vetorzinho[tamanho_auxiliar] = vetorzinho_auxiliar[tamanho_auxiliar - inicio];
  }//for
  free(vetorzinho_auxiliar);//nao precisamos do aux, liberamos memoria

}//merge
////////////////////////////////////////////////////////////////////////////////
void mergeSort(int vet[], int inicio, int fim){
  if(inicio < fim){
    int meio = (fim + inicio)/2;
    mergeSort(vet, inicio, meio);// vai dividindo a primeira metade
    mergeSort(vet, meio+1, fim);// vai dividindo a segunda metade
    merge(vet, inicio, meio, fim);// vai juntando em ordem as metades das metades, até se tornar um vetor inteiro de tamanho original
  }//if

}//mergeSort

////////////////////////////////////////////////////////////////////////////////
int main() {
  //srand(time(NULL));
  int vetor[8]={17, 0, 89, 5, 6, 2, -1, 345};
  // for(int i=0; i<8; i++){
  //   vetor[i]= rand() % 100;
  // }//for
  int inicio = 0;
  int fim = 7;
  mergeSort(vetor, inicio, fim );
  exibeVetor(vetor, 8);
  return 0;
}
