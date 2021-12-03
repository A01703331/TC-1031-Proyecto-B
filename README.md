# TC-1031-Proyecto-B
Este proyecto imprime los mejores tiempos que se le alimentan en la consola, guardando los valores usando un hash, luego los exporta a un archivo csv para mantener un registro de los mejores tiempos de cada jugador.

## Competencias

### SICT0303B: Usa un algoritmo de hashing adecauado para resolver un problema

Se usa un hash para mantener un registro unico por jugador, siempre y cuando el nombre este escrito de la misma forma, caracter por caracter. Se sobreescribe el valor de tiempo que se guarda cuando el tiempo alimentado es menor al que existe en el registro.

## Analisis de complejidad de tiempo

### Hash 

Esta funcion obtiene el valor a modular del string que se le da, conviritendolo a ASCII para luego transformarlo a un numero entero.  Su complejidad de tiempo es de O(n) para el peor de los casos (en este caso 'n' es el tamaño del string).

### indexOf

Esta funcion encuentra una ubicacion apropiada para el valor que se le alimenta, que en este caso es el nombre del jugador. Es llamada por diferentes algoritmos para obtener la ubicacion del registro. Su complejidad de tiempo es de O(n) para el peor de los casos.

### full

Esta funcion se asegura de que la tabla de has no este llena comparando el tamaño del hash con el conteo de registro. Su complejidad de tiempo es de O(1) para el peor de los casos.

### insert

Este algoritmo primero se asegura de que la tabla hash no este llena, si no lo esta, buscara un indice apropiado para el registro, si indice ya esta ocupado, solo sobreescribira el tiempo registrado si el tiempo alimentado es menor al anterior. Si el registro no existe en la tabla, creara un nuevo registro buscando. Su complejidad de tiempo es de O(n) para el peor de los casos.

### existance

Este algoritmo busca si hay un registro del nombre del jugador que se le da por medio de la funcion indexOf, regresando true si el registro existe. Su complejidad de tiempo es de O(n) para el peor de los casos.


### getTotalTime

Este algoritmo busca el registro del nombre del jugador que se le da por medio de la funcion indexOf, y regresa el tiempo en segundos del jugador si existe el registro. Su complejidad de tiempo es de O(n) para el peor de los casos.

### clear

Esta funcion reinicializa el hash, reemplazando los registros por el valor inicial de cada uno. Su complejidad de tiempo es de O(n) para el peor de los casos.

### printTime

Esta funcion recibe los segundos totales de un registro de tiempo, para luego convertirlos a un formato HH:MM:SS que es comunmente usado. Su complejidad de tiempo es de O(1) para el peor de los casos.

### printBestTimes

Este algoritmo recorre todos los registros que hay, imprimiendo cada registro que no tenga un valor inicial, gracias a la forma en que funciona la insercion de datos, solo imprimira el mejor tiempo del registro. Su complejidad de tiempo es de O(n) para el peor de los casos.
