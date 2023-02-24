/* Aloque dinamicamente uma matriz de inteiros 3x3 e preencha cada elemento da matriz com o seu respectivo
índice (matriz[i][j]=i*3+j). Em seguida imprima a matriz*/

#include <stdio.h> // biblioteca de entrada e saida 
#include <stdlib.h> // biblioteca que permite a alocação de memoria


int**cria_matr(int coluna, int linha){//Função para criação da matriz.
    int i,j; //declaração da variavel inteira, que vai ser usada como contador
    int** matriz = (int**) malloc(linha*sizeof(int*)); //alocando as linhas da matriz
    for ( i = 0; i < 3; i++){
        matriz[i]=(int*)malloc(coluna*sizeof(int)); // alocando as colunas da matriz 
        if (matriz[i]==NULL){ // verificar se realmente ocorreu a alocação na memoria
            printf("Erro ao alocar memória"); //caso não exibirar a segunte exibe a mensagem
            exit (1); // encerra o programa
        }
        for ( j = 0; j < coluna; j++){ // laço que vai percorrer todas as colunas, ate a matriz ser preenchida
            matriz[i][j]=i*3+j; //preenche a matriz, fazendo a operação.
        }
    }
    return matriz; //retorna a matriz
}

int main(void){ //função principal do programa
    int i,j; // declaração de duas variaveis do tipo inteiro
    int linha=3,coluna=3; // declara duas variaveis linha e coluna que vai ser igual a tres e vai ser do tipo inteiro
    int** matriz=cria_matr(3,3); // chama a função cria_matr define como 3x3. e que sera um inteiro e armazena no endereço matriz
    //preenche a matriz
    for ( i = 0; i < linha; i++){ // laço de repetição, para percorrer linha a linha
        for ( j = 0; j < coluna; j++){ // laço de repetição, para percorrer coluna a coluna
            matriz[i][j]=i*3+j; // preenche os elementos da matriz, com a posição tendo a seguinte operação
        }
    }
    //imprimir a matriz
    for ( i = 0; i < linha; i++){ // laço de repetição, que percorrer linha a linha
        for ( j = 0; j < coluna; j++){ // laço de repetição, que percorrer coluna a coluna 
            printf("%d", matriz[i][j]); // imprime os valores de cada posição da matriz
        }
    }
    //libera a memoria
    for ( i = 0; i < linha; i++){ // laço de repetição, para liberar linha a linha que foi reservada para a matriz
        free(matriz[i]); // libera a memoria que foi alocada para a linha da matriz 
    }
    free(matriz); // libera a memoria que alocou a matriz
    return 0; // fim do programa
}
