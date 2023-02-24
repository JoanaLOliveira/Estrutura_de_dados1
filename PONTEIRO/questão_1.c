#include <stdio.h> // biblioteca de entrada e saída.

int main (void){   //Função principal do programa


    int x, y, *p; // Declara 3 variaveis (x,y,p) do tipo inteiro.
    y = 0;     // y é inicializado com 0.
    p = &y;   // p receber o endereço de y.
    x = *p;  // x receber o ponteiro de p.
    x = 4;   // x é inicializado com 4.
    (*p)++;  // o valor do ponteiro de p e incrementado. 
    --x;    // o valor de x sofre o decremento.
    (*p) += x; // o valor da variavel p é somado a variavel x.
    printf("%d %d %p", x,y, p); // imprime os valores das variaveis (x,y,p).
    
    return 0; //fim do programa.
}
