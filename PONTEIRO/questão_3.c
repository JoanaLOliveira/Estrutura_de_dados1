#include <stdio.h> // biblioteca de entrada e saida

int main(void) { // função principal do programa
    int a, b, c,d; // declaração das quatro variaveis (a,b,c,d), do tipo inteiro.
    int *p1; // declaração do ponteiro p1, é do tipo inteiro.
    int *p2 = &a; // declaração do ponteiro p2, do tipo inteiro, que é inicializado com o valor do endereço de a.
    int *p3 = &c; // declaração do ponteiro p3, do tipo inteiro, que é inicializado com o valor do endereço de c.
    p1 = p2; // p1 é igualado a p2
    *p2 = 10; // o ponteiro p2, recebe o valor 10
    b = 20; // b recebe o valor 20
    int **pp; // declaração de um ponteiro para ponteiro chamado de pp, do tipo inteiro
    pp = &p1; // o ponteiro pp recebe o endereço de p1
    *p3 = **pp; // o ponteiro p3, recebe o valor que foi apontado pelo ponteiro para ponteiro pp.
    *p2 = b + (*p1)++; // o ponteiro p1 sofre o incremento, e é somando com b. que vai atualizar o valor de p2 depois da soma.
    printf("%d\t%d\t%d\n", a, b, c); // imprime na tela as três informações das seguintes variaveis (a,b,c).
    return 0; // Fim do programa
}
