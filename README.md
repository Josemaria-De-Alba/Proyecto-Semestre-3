# Proyecto-Semestre-3: Apoyo para balancing en juegos en línea

Este proyecto se basa en paginas para ver el porcentaje de uso de personajes como esta:

https://apexlegendsstatus.com/game-stats/legends-pick-rates

Mi código es una manera de organizar datos como en esta página, está diseñada para juegos en linea, recibe el nombre de un personaje/arma y su nombre o identificador y los acomoda para que el usuario pueda ver estos datos y vea si alguno de estos es demasiado débil o demasiado fuerte a través de su uso.

Se utiliza un árbol AVL para poder guardar información de manera eficiente y para que los datos se organicen de manera automática, esto ayuda a guardar tiempo y sirve más para este tipo de programa ya que se intenta comparar el uso de personajes/armas y conviene tener las cosas organizadas lo más pronto posible.

Aparte de esto se utiliza un vector que se puede organizar si es que prefieres tener los datos organizados de manera alfabética en vez de por su valor de uso.

**Análisis de Complejidad**

Análisis general: 0(3 log(n)) + 0(n log(n)) + 0(n) Esto es la mayor complejidad que se llega a lograr dentro de el código ya que es cuando se imprimen todos los valores en el menú principal. Es esta complejidad y no 0(log(n)) ya que aparte de realizar la función de imprimir nodos, corre dos funciones similares a la de encontrar nodo en la que busca el nodo más a la izquierda y el nodo más a la derecha. El valor de 0(n log(n)) viene del mergesort que se realiza para asegurarse que el vector está organizado cuando se imprime. El valor de 0(n) también viene del vector ya que es la complejidad necesaria para que se impriman todos los valores.

Árbol AVL para personajes/armas y su porcentaje de uso:

Función de encontrar nodo: 0(log(n)) Para encontrar el nodo es necesario ir a través de algunos nodos y se localiza dependiendo si el valor buscado es menor o mayor que el nodo actual

Función de agregar nodo: 0(log(n)) Se agrega un nodo nuevo dependiendo de un valor numérico buscando donde se coloca el nodo basado en un número, si es menor que el nodo actual se va a la izquierda y si es mayor a la derecha. Hace esto hasta encontrar un nodo que esté vacío y ahí coloca la información

Función de eliminar nodo: 0(log(n)): Busca la posición del nodo y luego lo elimina, utiliza el mismo método que las otras funciones de checar si el nodo se encuentra a la izquierda o a la derecha y luego elimina el nodo

Función de imprimir nodos: 0(log(n)): Va de nodo a nodo imprimiendo primero los nodos que están más a la izquierda hasta llegar a los nodos a que están hasta abajo en la derecha


Vector en clase Sort para personajes/armas y su porcentaje de uso:

Función de agregar un valor: 0(n) Se agregan un valor de un float y un string al final del vector.

Función de mergesort: 0(n(log(n)) Se utilizan las funciones de mergesort con ayuda de las funciones merge split, merge array, y copy array para organizar el vector de manera alfabética.

Función de imprimir: 0(n) Imprime todos los valores dentro del vector, hace esto pasando 1 por uno hasta llegar al final.

Función de encontrar: 0(n) Busca un valor dado por el usuario yendo uno por uno hasta encontrarlo o llegar al final del vector.

Función de eliminar: 0(n) Busca un valor dado por el usuario yendo uno por uno hasta encontrarlo para poder eliminarlo o llegar al final.
