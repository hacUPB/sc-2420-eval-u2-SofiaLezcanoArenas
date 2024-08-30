#include "minimal.h"
#include <stdio.h>
#include <math.h>

int main(int argc, char* argv[]){

    //pedir dos números y calcular el menor
    int num1, num2, resultado;

    printf("Por favor piensa en dos números enteros\n");
    printf("Ingrese el primero:\n");
    scanf("%i", &num1);
    printf("Ingrese el segundo:\n");
    scanf("%i", &num2);

    printf("the min value is: %d\n",minimal(num1,num2));

    //Elevar el primer número al segundo
    resultado= pow(num1, num2);
    printf("%i elevado a la %i es %i:\n", num1, num2, resultado);
    return 0;
}