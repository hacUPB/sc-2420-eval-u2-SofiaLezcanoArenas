# Ejercicio 2: Calculando el Tiempo de Ejecución

## Tiempos:
![tiempos](https://github.com/hacUPB/sc-2420-eval-u2-SofiaLezcanoArenas/blob/main/Game_loop_SDL2/Ejercicio2/tiempos%20de%20ejecuci%C3%B3n.png)

Se puede apreciar que en un segundo se ejecutan cuatro veces update y render.

## ¿Por qué es importante mantener una frecuencia de actualización constante?

Mantener una frecuencia de actualización constante evita procesos lentos, reduce el margen de error en la lectura de datos que arroja el usuario y saltos en los gráficos. Además, evita que se desincronicen la ejecución de update con la de render, lo que causaría que no hubiera coherencia entre las acciones y los gráficos. 

Para concluir, mantener una frecuencia de actualización constante, es vital para garantizar una buena experiencia de usuario.