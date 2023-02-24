/* Crie um tipo estruturado para armazenar dados de um funcionário. uma estrutura deste tipo possui os
seguintes campos: nome, salário, identificador e cargo

a) escreva uma função que receba como parâmentro o endereço de uma estrutura do tipo Funcionario e preencha 
seus campos com valores fornecidos pelo usuário via teclado.

b) escreva uma função que receba como parametro o endereço de uma estrutura do tipo Funcionario e 
imprima os valores dos seus campos.

c) implemente uma função para realizar uma alteração no salário de uma estrutura do tipo Funcionario.

d) escreva uma funçõa que receba como parâmetro um vetor de estruturas do tipo Funcionario e imprima o
cargo e salário do Funcionario com maior salário e o cargo e salário do funcionário com o menor salário. */ 

#include<stdio.h> //biblioteca de entrada e saida
#include<stdlib.h> //biblioteca de alocação

typedef struct funcionario{ //estrutura funcionario
	char nome[50],carg[50]; // duas variaveis do tipo caractere
	float sal; // uma variavel do tipo float
	int id; // uma variavel do tipo inteiro
}Funcionario; //renomeio da estrutura

void preencha(Funcionario *preencha, int qtd){ // função para preencher, que recebe dois parametros (um ponteiro e um parametro qtd do tipo inteiro)
	for(int i = 0; i < qtd; i++){ //laço de repetição quer percorre toda a função
    	printf("Qual é o nome do funcionario: "); //exibe na tela a seguinte mensagem
    	scanf(" %[^\n]s", preencha[i].nome); //lê e armazena na posição i nome
    	printf("Qual é o salario do funcionario: "); //exibe na tela a seguinte mensagem
    	scanf("%f", &preencha[i].sal); //lê e armazena na posição i sal
    	printf("Qual é o identificador do funcionario: "); //exibe na tela a seguinte mensagem
    	scanf("%d", &preencha[i].id); //lê e armazena na posição i id
    	printf("Qual o cargo do funcionario: "); //exibe na tela a seguinte mensagem
    	scanf(" %[^\n]s", &preencha[i].carg); //lê e armazena na posição i carg
    }
}
void men_mai(Funcionario * mem, int qtd){ //função de menor e maior salario, que recebe como parametro (um ponteiro e um inteiro)
    float men = 0, mai = 0; // declaração de duas variaveis do tipo float, que sao inicializadas com 0
    int ind_mai, ind_men; // declaração do tipo inteiro, para armazenar o salari 
	for(int i = 0; i < qtd; i++){ // laço que vai percorrer a quantidade de funcionarios
		if(i == 0){ // se o indice é 0, é o funcionairo com menor salario
			men = mem[i].sal; // inicializa com o valor do primeiro funcionario
		}
		if(mem[i].sal > mai){ // se o salario atual for maior que o anterior 
			mai = mem[i].sal; // atualiza o salario maior
			ind_mai = i; // atualiza o indice do funcionario do maior salario
		} 
		if(mem[i].sal < men){ //se o salario atual for menor que o anterior 
			men = mem[i].sal; // atualizar o salario menor 
			ind_men = i; // atualiza o indice do funcionario do menor salario 
		} 
	}
	printf("O funcionario que tem o maior salario e %s, que tem salario de %.1f", mem[ind_mai].nome, mem[ind_mai].sal); //imprime na tela a mensagem, seguindo com o nome do funcionario com o maior salario, e o salario do mesmo
	printf("O funcionario que tem o menor salario e %s, que tem salario de %.1f", mem[ind_men].nome, mem[ind_men].sal); //imprime na tela a mensagem, seguindo com o nome do funcionario com o menor salario, e o salario do mesmo
}

void atualiz (Funcionario * alt, int ind){ //função para atualizar o salario do funcionario, que recebe dois parametros, um do tipo inteiro, e um ponteiro
	alt[ind].sal += 10; //atualiza o salario, adicionando 10 ao valor atual.
}

int main (){  // função principal
	int quant; // declaração de uma variavel do tipo inteiro
	printf("Informe a quantidade de funcionarios: "); // imprime na tela a seguinte mensagem
	scanf ("%i", &quant); // armazena o valor, e guarda no endereço quant
	Funcionario * empr = (Funcionario*) malloc (quant*sizeof(Funcionario) ); // alocação na memoria, para a quantidade de funcionario
	if(empr == NULL){ // verificando se foi alocado na memoria 
        printf("Memoria insuficiente\n"); // caso nao sera exibido a seguinte mensagem
		    exit (1); // encerra o programa
	}
	preencher(empr, quant); // chamada da função preencher
	men_mai(empr,quant);// chamada da função men_mai
  atualiz(empr, 0); // chamada da função atualiz

	return 0; // fim do programa
}
