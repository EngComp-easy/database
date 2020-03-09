/*ctype.h
A maioria das funções desta biblioteca serve para classificar caracteres ASCII,
ou seja, para dizer se um dado byte representa uma letra, ou um dígito, ou um
branco, etc. em código ASCII.  O argumento de cada função não é um char mas sim
um inteiro positivo ou um EOF. Usualmente, o argumento pertence ao intervalo
−1..127.
*/
#include <stdio.h>
#include <ctype.h>   // para tolower que converte o caracter em minúsculo
//#include <fcntl.h> //perror

FILE* fileManager(){
    FILE* arquivo;
    char modo;  //opção
    char* nomeArquivo = "prova.txt";

    printf("Escolha um modo para abrir o arquivo \n\nG-Escritura \nL-Leitura \nA-Anexão \n\n?: ");
    scanf("%c%*c", &modo);
    modo = tolower(modo); //<-passamos a minuscula

    switch ( modo ) { //Vai verificar o modo
        case 'g':
            //G - É para gravação,o parametro wt
            arquivo = fopen ( nomeArquivo, "wt" ); //Só permite escrever no arquivo, borra conteudo anterior
            break;

        case 'l':
            //l - É para leitura  do texto
            arquivo = fopen ( nomeArquivo, "r" ); //modo leitura, no hace falta poner t, por default ja é t, si nao por b(binario), começa do principio.
            break;

        case 'a':
            //A- É para append(anexação)
            arquivo = fopen ( nomeArquivo, "a" ); //Modo Anexar só permite escrever ao fin do arquivo, nao importa si tentar mover o descriptor de arquivo, sempre vai anexar ao fin evitando borrar conteudo.
            break;
    }


    if ( arquivo == NULL ) { //A diretiva NULL em letras maiusculas,é quando a pontar para o espaço da memoria NULO,ou NULL,caso o arquivo não exista
        perror("Desculpe! "); //<-importante para saber que tipo de erro tivemos ao tentar abrir

        //fazemos uma pausa
        printf("\nPulse uma tecla para continuar...");
        scanf("%*c");

        //como nao conseguimos abrir o arquivo retornamos NULL que no apunta a nada.
        return NULL;
    }else{
        //Se conseguimos abrir informamos do exito.
        printf("O arquivo %s esta aberto em modo %s\n", nomeArquivo, (modo=='g')? "gravação.":(modo=='a')? "anexão.": "leitura."  );
    }

    //Se chegamos aqui é por que o arquivo esta aberto e agora retornamos ele como foi pedido.
    return arquivo;
}//FIM fileManager

void finalizar ( FILE *arquivo ) { //Está função vai fechar o arquivo
    fclose ( arquivo );
}//FIM finalizar


//////MAIN////////
int main() {
    FILE* arquivo = fileManager(); //a variavel arquivo recebe o ponteiro ao arquivo.

    if( arquivo == NULL ){
        return 1; // se o programa retornar 1 é por que nao abrio o arquivo nao temos por que fechar ele, saimos aqui mesmo.
    }


    finalizar(arquivo); // se passou pela comprovaçao anterior é preciso fechar o arquivo antes de sair ja que nao vamos fazer mais nada.
    return 0;
}//FIM MAIN
