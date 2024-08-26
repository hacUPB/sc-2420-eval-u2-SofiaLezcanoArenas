#include "minimal.h"
#define ANCHO_PANTALLA 800  //para crear constantes simbólicas. Se escriben en mayúsculas sostenidas para saber que es una constante y no una variable.
int minimal(int a, int b){
    if(a < b) return a;
    else return b;
}