# Ejercicio 1: Reconociendo las Partes del Game Loop

## Identificación de funciones

- **Setup()**: se llama una sola vez justo al comienzo. En ella se incluyen todas las configuraciones iniciales, como crear y preparar el ambiente del juego, ubicar los objetos en su posición inicial, cargar recursos de ser necesario. Todas las acciones que se requieran hacer una única vez al comienzo.
- **Update()**: se llama en cada loop. Aquí se actualiza el estado del juego, pues se identifican las entradas del usuario, se detectan colisiones, se lleva la cuenta del tiempo en caso de necesitarse y otros procesos. Permite el funcionamiento técnico del juego.
- **Render()**: se llama en cada loop. Se le encargan los procesos gráficos del juego, como dibujar personajes, objetos, fondos, efectos visuales, etc.

## Observaciones al instertar printf() en cada función

- **Setup()**: se visualizó una única vez al principio de la ejecución.
- **Update()**: se veía el mensaje rápidamente pasar por la consola, pues se ejecutaba en cada iteración de un loop infinito.
- **Render()**: al igual que update() se veía el mensaje rápidamente pasar por la consola, porque también se estaba ejecutando en cada iteración de un loop infinito.

# Ejercicio 2: Calculando el Tiempo de Ejecución
## Tiempos:
![tiempos](https://github.com/hacUPB/sc-2420-eval-u2-SofiaLezcanoArenas/blob/main/Game_loop_SDL2/Ejercicio2/tiempos%20de%20ejecuci%C3%B3n.png)

Se puede apreciar que en un segundo se ejecutan cuatro veces update y render.

## ¿Por qué es importante mantener una frecuencia de actualización constante?

Mantener una frecuencia de actualización constante evita procesos lentos, reduce el margen de error en la lectura de datos que arroja el usuario y saltos en los gráficos. Además, evita que se desincronicen la ejecución de update con la de render, lo que causaría que no hubiera coherencia entre las acciones y los gráficos. 

Para concluir, mantener una frecuencia de actualización constante, es vital para garantizar una buena experiencia de usuario.

# Ejercicio 3
![alt text](image.png)

Al colocar `SDL_SetRenderDrawColor(renderer, 200, 0, 100, 255);` antes de cada figura y variar los factores RGB, se pudieron dibujar de diferentes colores las figuras.

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

Con estas líneas incluidas en update, se asegura un movimiento distinto para cada figura tal como se indica. Al ejecutar el programa, se observó un desplazamiento apresurado de cada una hasta que salieron del borde definido por la ventana. Esta velocidad depende del procesador del computador, así que para un mayor control sobre esto, se debería definir un número de FPS.

En el proceso de especificar el número de FPS, faltó la implementación de un tiempo de espera para que todo se viera un poco más despacio.

También están parando cuando se encuentran con los bordes.

## Ejercicio 5
No se puede rotar un rectángulo si se dibuja con la función predeterminada para ello. Sin embargo, creo que si se manipulan adecuadamente, podría dibujarse con líneas y coordinar su movimiento para que el rectángulo aparente rotar.

No hubo problemas con este ejercicio. Solo que también faltó configurar el tiempo de espera.

## Ejercicio 6
