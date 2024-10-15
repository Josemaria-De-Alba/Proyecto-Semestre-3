# Proyecto-Semestre-3

Para este proyecto, quiero hacer una versión alternativa del proyecto que realice el semestre pasado de crear loadouts para Destiny. Esta vez quiero tener un inventario más grande que también se pueda organizar. Quiero tener opciones de como poder organizar los distintos datos, por el momento quiero poder organizar todos los datos por valor numerico y de orden alfabetico.

Primera Avance:
Empecé a utilizar vectores para guardar una gran cantidad de el mismo tipo de datos. Tengo 3 armas para un vector default, y se prueban todas las funciones. Estas sirven para imprimir los datos, para agregar valores a los vectores, y para sumar el daño total de todas las armas. Para esta entrega me enfoque más en el cambio a utilizar vectores, pero para la siguiente entrega quiero organizarlo para que sea más interactivo a través de ciclos.

Segundo Avance:
Cambie para utilizar listas doblemente encadenadas y binary trees para guardar la informacion. Funciona aunque no completamente como quiero. Estoy utilizando un bubble sort para organizar la lista y el binary tree se organiza de manera automatica. Para poder organizar la lista de manera más facil, la estoy convirtiendo a un vectory y luego organizandola, en el futuro planeo cambiar esto, pero aun no estoy seguro como puedo organizar las listas como yo quiero.

#Conponentes
Para almacenar datos se utilizan los siguientes metodos con sus respectivas funciones y complejidades:

-Lista Doblemente Encadenada:

Funcion Insercion: Best: O(1) Worst: O(1) se utiliza para guardar valores nuevos dentro de la lista

Funcion Busqueda: Best: O(n) Worst: O(n) se utiliza para encontrar la posicion de un valor espesificado

Funcion Actualizar: Best: O(n) Worst: O(n) se utiliza para cambiar el valor de algo en una posicion espesificada

Funcion Borrar: Best: O(n) Worst: O(n) funcion para borrar un dato en una posicion espesifica

Funciones Imprimir: Best: O(n) Worst: O(n) imprime todos los valores dentro de la lista

Funcion Sort(Bubble): Best: O(n) Worst: O(n^2) organiza los valores dentro de la lista despues de pasarlos a un vector

-Arbol Binario:

Funcion Agregar: Best: O(log(n)) Worst: O(n) agrea un valor a el arbol mientras lo ordena al mismo tiempo

Funciones Imprimir: Best: O(n) Worst: O(n) imprime todos los valores dentro de la lista
