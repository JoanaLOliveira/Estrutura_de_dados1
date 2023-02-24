/* Crie um tipo estruturado para armazenar dados 
de uma pessoa. Uma estrutura deste tipo possui os
seguintes campos: nome da pessoa, numero do documento
e idade

a) Escreva uma função que receba como parâmetro o 
endereço de uma estrutura do tipo Pessoa e preencha
seus campos com valores fornecidos pelo usuário via
teclado.

b)Escreva uma função que receba como parâmetro o 
endereço de uma estrutura do tipo Pessoa e imprima
os valores dos seus campos.

c) implemente uma função para realizar uma atualização
da idade de uma estrutura do tipo Pessoa.

d) Escreva uma função que receba como parâmetro um
vetor de estruturas do tipo Pessoa e imprima o nome
da Pessoa mais velha e mais nova
*/ 

#include <stdio.h> // biblioteca de entrada e saida
#include <stdlib.h> //biblioteca de alocação
#include <string.h> //biblioteca de manipulação de strings

typedef struct pessoa{ // estrutura do tipo pessoa
    char nome[80]; // variavel do tipo caractere para o nome
    int doc, ida; //variavel do tipo inteiro para o documento e idade
} Pessoa; // renomeia a estrutura

void preenche(Pessoa *i){ // função preencher  
    int d; // contador para percorrer o laço de repetição
    for (d = 0; d < 4; d++){ // laço de repetição que percorre toda o vetor
        printf("Digite o nome: "); //exibe na tela a seguinte mensagem
        scanf(" %[^\n]", &i[d].nome); // lê e armazena no endereço 
        printf("Digite o numero do documento: "); //exibe na tela a seguinte mensagem
        scanf("%d", &i[d].doc); // lê e armazena no endereço
        printf("Digite a idade: "); //exibe na tela a seguinte mensagem
        scanf("%d", &i[d].ida); //lê e armazena no endereço
    }
}

void imprima(Pessoa *i){ //função imprime que recebe como parametro um ponteiro
    int n; //indice
    for (i = 0; i < 4; i++) //laço de repetição que percorre e imprimi os dados dos funcionarios
    {
        printf("Nome do funcionario: %s\n", i[n].nome); //exibi na tela a mensangem, e o dado que corresponde ao nome 
        printf("Numero do documento: %d\n", i[n].doc); //exibi na tela a mensangem, e o dado que corresponde ao documento
        printf("Idade da pessoa: %d\n", i[n].ida); //exibi na tela a mensangem, e o dado que corresponde a idade
    }
}

void atualiza(Pessoa *i, int val){ // função de atualiza recebe dois parametros (um ponteiro da struct, e um do tipo inteiro )
    int a; //declaração do contador
    for (a = 0; a < 4; a++){ // laço de repetição que percorrer o vetor
        if (val == i[a].doc){ // verifica se o vetor atual e igual ao documento
            printf("Atualize a idade da pessoa: "); //exibi a seguinte mensagem
            scanf("%d", &i[a].ida); // lê e armazena a idade que foi informada
        } 
    }
}

void mai_men(Pessoa *i){ //função que recebe um parametro ponteiro
    int mai = i[0].ida; // variavel do tipo inteiro para armazena a maior idade
    int men = i[0].ida; //variavel do tipo inteiro para armazena a menor idade
    char nome_mai[100]; // variavel do tipo caractere para armazena o nome do mais velho 
    char nome_men[100]; // variavel do tipo caractere para armazena o nome do mais novo
    strcpy(nome_mai, i[0].nome); // armazena o nome da pessoa do vetor i para a variavel do mais velho
    strcpy(nome_men, i[0].nome); // armazena o nome da pessoa do vetor i para a variavel do mais novo
    for (int m = 1; m < 4; m++){ // laço de repetição para o vetor
        if (i[m].ida > mai){ // verifica se a idade e maior que o anterior ja armazenado no indice maior
            strcpy(nome_mai, i[m].nome); // se for verdade, ele vai exibir na variavel o nome do mais velho
            mai = i[m].ida; // atualiza a idade do mais velho
        }
        if (i[m].ida < men){ // verifica se a idade e menor que o anterior ja armazenado no indice menor
            strcpy(nome_men, i[m].nome); // se for verdade, ele vai exibir na variavel o nome do mais novo
            men = i[m].ida; // atualiza a idade do mais novo
        }
    }
    printf("Pessoa mais velha encontrada idade: %d nome: %s\n", mai, nome_mai); //exibe na tela a seguinte mensagem, com a idade do mais velho e o nome do mesmo
    printf("Pessoa mais nova encontrada idade: %d nome: %s\n", men, nome_men); //exibe na tela a seguinte mensagem, com a idade do mais novo e o nome do mesmo
}

int main(void) // Função principal
{
    Pessoa *p1 = (Pessoa *)malloc(4 * sizeof(Pessoa)); // alocação na memoria para pessoa
    int p2, val; // declaração de duas variaveis do tipo inteiro
    printf("Quer alterar a idade de alguem ? (1) Sim ou (2) Nao\n"); // exibe na tela a seguinte mensagem
    scanf("%d", &p2); //armazena a escolha, e guarda no endereço de p2
    if (p2 == 1){ // esse laço é para caso o usuario selecione a função para atualizar a idade de alguem
        printf("Qual o numero do documento: "); // exibi na tela a seguinte mensagem 
        scanf("%d", &val); // lê e armazena no endereço do 
    }
    preenche(p1); //chamada da função preenche
    imprima(p1); // chamada da função imprimir
    atualiza(p1, val); // chmada da função atualiza
    mai_men(p1); // chamada da função mai_men
    return 0; // fim do programa
}
