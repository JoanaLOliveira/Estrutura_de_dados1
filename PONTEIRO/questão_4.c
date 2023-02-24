#include <stdio.h> // biblioteca de entrada e saida
#include <math.h> // biblioteca para fazer funções matemáticas

void cal_hexa(float l, float *a, float *p){ //função para calcular o hexagono, e são declarado 3 variaveis do tipo float (sendo dois ponteiros, A e P são ponteiros)
    *p = 6*l; // formula para calcula o perimetro.
    *a = (3*pow(l,2)*sqrt(3))/2;  // formula para calcular a area do hexagono 
}
int main(void){ // função principal do programa
    float l, a, p; // declaração de 3 variaveis do tipo float 
    scanf("%f", &l); // lê o valor que foi inserido no endereço de l
    cal_hexa(l,&a,&p); // chama a função cal_hexa, o &a vai armazenar o valor da area, ja o &p vai armazenar o valor do perimetro. 
    printf("Area = %.2f \n Perimetro = %.2f \n", a,p); // imprime na tela, o valor da area e o valor do perimetro. 
    return 0; //fim do programa
}
