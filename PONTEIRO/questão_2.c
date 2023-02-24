#include <stdio.h> //biblioteca de entrada e saida.

int main(void) { //função principal do programa.
    int x, *p; // declaração de duas variaveis (x, e o ponteiro de p) do tipo inteiro 
    x = 100;  // a variavel x é inicializado com 100.
    p = &x;  // o ponteiro de p, recebe o endereço de x.
    printf("Valor de p = %p\tValor de *p = %d", p, *p); //imprime na tela as duas informações, (a primeira da variavel, a segunda do ponteiro de p)
    return 0; //fim do programa
}
