/* Aloque dinamicamente um vetor de inteiro de tamanho 10 e preencha cada elemento do vetor com 
o seu respectivo índice (vetor[i]=i). em seguida, imprima o vetor */

#include<stdio.h> // biblioteca de entrada e saida
#include<stdlib.h> // biblioteca que permite a alocação de memoria
int main(void){ // Função principal
    int tamanho=10; // variavel do tipo inteiro que inicializa com 10
    int i; //declaração de variavel do tipo inteiro
    int *vetor=(int*)malloc(tamanho*sizeof(int)); //aloca na memoria um vetor para inteiro de tamanho da variavel tamanho.
    if (vetor==NULL){ // verificar se realmente ocorreu a alocação na memoria
        printf("Erro ao alocar memória"); //caso não exibirar a segunte mensagem
        exit (1); // encerra o programa
    }
    for (i = 0; i < tamanho; i++){ // laço de repetição que percorre todo o vetor
        vetor[i]=i; //preencher o vetor
    }

    //Imprimir vetor
    for (i = 0; i < tamanho; i++){ // laço de repetição que percorrer todo o vetor
        printf("%d\t",vetor[i]); // exibi na tela, a leitura do vetor
    }
    
    free(vetor); //libera a memoria
    return 0; //Fim do programa 
}
