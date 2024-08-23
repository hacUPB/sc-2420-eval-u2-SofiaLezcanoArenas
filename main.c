#include <stdio.h> //permite usar print...
#include <math.h>   // para poder usar pow para elevar
//comentario de una linea
/*comentario de varias lineas. 
No olvidar cerrar*/
int main(int argc, char const *argv[])
{
    float estatura, peso, IMC; //las variables pueden separarse con comas
    char nombre[30]; //arreglo de 30 caracteres

    printf("Ingrese su nombre:\n");
    fgets(nombre, 30, stdin); //solo lee texto

    printf("Ingrese su peso:\n");
    scanf("%f", &peso); // scan f necesita saber qué tipo de dato va a leer, porque solo lee texto. %f convierte el texto en flotante. &peso se refiere a la dirección de memoria donde está peso, para poder guardar ahi el dato.
                        // scanf lee la info que llega por el teclado
    printf("Ingrese su estatura:\n");
    scanf("%f", &estatura);

    //IMC = peso/estatura al cuadrado

    IMC = peso / pow(estatura, 2);

    printf("%s su IMC = %f\n", nombre,  IMC); //para imprimir una variable hay que poner el formato %s es cadena de catacteres. Los datos se reemplazan en orden de escritura.

    return 0;
}