# Proyecto-Semestre-3: Apoyo para balancing en juegos en línea

Este proyecto se basa en paginas para ver el porcentaje de uso de personajes como esta:

https://apexlegendsstatus.com/game-stats/legends-pick-rates

Mi código es una manera de organizar datos como en esta página, está diseñada para juegos en linea, recibe el nombre de un personaje/arma y su nombre o identificador y los acomoda para que el usuario pueda ver estos datos y vea si alguno de estos es demasiado débil o demasiado fuerte a través de su uso.

Se utiliza un árbol AVL para poder guardar información de manera eficiente y para que los datos se organicen de manera automática, esto ayuda a guardar tiempo y sirve más para este tipo de programa ya que se intenta comparar el uso de personajes/armas y conviene tener las cosas organizadas lo más pronto posible.

**Análisis de Complejidad**

Árbol AVL para personajes/armas y su uso porcentaje de uso:

Análisis general: 0(log(3n)) Esto es la mayor complejidad que se llega a lograr dentro de el código ya que es cuando se imprimen todos los valores en el menú principal. Es esta complejidad y no 0(log(n)) ya que aparte de realizar la función de imprimir nodos, corre dos funciones similares a la de encontrar nodo en la que busca el nodo más a la izquierda y el nodo más a la derecha.

Función de encontrar nodo: 0(log(n)) Para encontrar el nodo es necesario ir a través de algunos nodos y se localiza dependiendo si el valor buscado es menor o mayor que el nodo actual

Función de agregar nodo: 0(log(n)) Se agrega un nodo nuevo dependiendo de un valor numérico buscando donde se coloca el nodo basado en un número, si es menor que el nodo actual se va a la izquierda y si es mayor a la derecha. Hace esto hasta encontrar un nodo que esté vacío y ahí coloca la información

Función de eliminar nodo: 0(log(n)): Busca la posición del nodo y luego lo elimina, utiliza el mismo método que las otras funciones de checar si el nodo se encuentra a la izquierda o a la derecha y luego elimina el nodo

Función de imprimir nodos: 0(log(n)): Va de nodo a nodo imprimiendo primero los nodos que están más a la izquierda hasta llegar a los nodos a que están hasta abajo en la derecha
