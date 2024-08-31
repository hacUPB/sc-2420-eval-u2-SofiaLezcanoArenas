# Ejercicio 1: Reconociendo las Partes del Game Loop

## Identificación de funciones

- **Setup()**: se llama una sola vez justo al comienzo. En ella se incluyen todas las configuraciones iniciales, como crear y preparar el ambiente del juego, ubicar los objetos en su posición inicial, cargar recursos de ser necesario. Todas las acciones que se requieran hacer una única vez al comienzo.
- **Update()**: se llama en cada loop. Aquí se actualiza el estado del juego, pues se identifican las entradas del usuario, se detectan colisiones, se lleva la cuenta del tiempo en caso de necesitarse y otros procesos. Permite el funcionamiento técnico del juego.
- **Render()**: se llama en cada loop. Se le encargan los procesos gráficos del juego, como dibujar personajes, objetos, fondos, efectos visuales, etc.

## Observaciones al instertar printf() en cada función

- **Setup()**: se visualizó una única vez al principio de la ejecución.
- **Update()**: se veía el mensaje rápidamente pasar por la consola, pues se ejecutaba en cada iteración de un loop infinito.
- **Render()**: al igual que update() se veía el mensaje rápidamente pasar por la consola, porque también se estaba ejecutando en cada iteración de un loop infinito.