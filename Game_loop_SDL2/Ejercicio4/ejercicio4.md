# Ejercicio 4: Movimiento de Figuras en Pantalla

``` C
//Movimiento de figuras
    //rect�ngulo hacia la izquierda
    rectX -= 1;
    //c�rculo hacia abajo
    centerY -= 1;
    //l�nea hacia arriba
    ly1 += 1;
    ly2 += 1;
```

Con estas líneas incluidas en update, se asegura un movimiento distinto para cada figura tal como se indica. Al ejecutar el programa, se observó un desplazamiento apresurado de cada una hasta que salieron del borde definido por la ventana. Esta velocidad depende del procesador del computador, así que para un mayor control sobre esto, se debería definir un FPS.