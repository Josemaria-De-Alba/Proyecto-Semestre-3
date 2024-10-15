# Proyecto-Semestre-3


Para este proyecto, quiero hacer una versión alternativa del proyecto que realice el semestre pasado de crear loadouts para Destiny. Esta vez quiero tener un inventario más grande que también se pueda organizar. Quiero tener opciones de como poder organizar los distintos datos, por el momento quiero poder organizar todos los datos por valor numérico y de orden alfabético. Para lograr esto voy a utilizar Listas Doblemente Encadenadas y Arboles Binarios para almacenar y organizar información para luego poder imprimirla y que a partir de esta información ya organizada el jugador pueda tomar decisiones mejor informadas.

Primera Avance:
Empecé a utilizar vectores para guardar una gran cantidad de el mismo tipo de datos. Tengo 3 armas para un vector default, y se prueban todas las funciones. Estas sirven para imprimir los datos, para agregar valores a los vectores, y para sumar el daño total de todas las armas. Para esta entrega me enfoque más en el cambio a utilizar vectores, pero para la siguiente entrega quiero organizarlo para que sea más interactivo a través de ciclos.

Segundo Avance:
Cambie para utilizar listas doblemente encadenadas y binary trees para guardar la información. Funciona aunque no completamente como quiero. Estoy utilizando un bubble sort para organizar la lista y el binary tree se organiza de manera automática. Para poder organizar la lista de manera más fácil, la estoy convirtiendo a un vector y luego organizandola, en el futuro planeo cambiar esto, pero aun no estoy seguro cómo puedo organizar las listas como yo quiero.

#Componentes
Para almacenar datos se utilizan los siguientes métodos con sus respectivas funciones y complejidades:

-Lista Doblemente Encadenada:

Función Inserción: Best: O(1) Worst: O(1) se utiliza para guardar valores nuevos dentro de la lista

Funcion Busqueda: Best: Or) Worst: O(n) se utiliza para encontrar la posición de un valor especificado

Función Actualizar: Best: Or) Worst: O(n) se utiliza para cambiar el valor de algo en una posición especificada

Función Borrar: Best: Or) Worst: O(n) función para borrar un dato en una posición específica

Funciones Imprimir: Best: Or) Worst: O(n) imprime todos los valores dentro de la lista

Función Sort(Bubble): Best: Or) Worst: O(n^2) organiza los valores dentro de la lista después de pasarlos a un vector

-Arbol Binario:

Función Agregar: Best: O(log(n)) Worst: O(n) agrega un valor a el árbol mientras lo ordena al mismo tiempo

Funciones Imprimir: Best: Or) Worst: O(n) imprime todos los valores dentro de la lista

Funciones Localizar: Best: O(log(n)) Worst: O(n) permite encontrar el nivel donde se encuentra un valor especificado
