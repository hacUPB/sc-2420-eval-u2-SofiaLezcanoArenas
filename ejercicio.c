#include <stdio.h> //permite usar print...
#include <math.h>
//se delara la funión que vamos a usar
float calcula_imc(float,float); //prototipo de la función. El tipo de la función es el tipo de dato que va a devolver, luego el nombre y entre paréntesis los ripos de dato que necesita recibir.

int main(int argc, char const *argv[])
{
    float estatura, peso, imc; //las variables pueden separarse con comas
    char nombre[30]; //arreglo de 30 caracteres

    printf("Ingrese su nombre:\n");
    fgets(nombre, 30, stdin); //solo lee texto

    printf("Ingrese su peso:\n");
    scanf("%f", &peso);
    
    printf("Ingrese su estatura:\n");
    scanf("%f", &estatura);

    imc= calcula_imc(peso, estatura);

    printf("%s su IMC = %f\n", nombre,  imc);

}

float calcula_imc(float peso,float estatura) //para usarla ya no lleva ; sino llaves. También hay que pasarle los argumentos que necesita
{
    float IMC;
    //IMC = peso/estatura al cuadrado
    IMC = peso / pow(estatura, 2);
    return IMC;
}