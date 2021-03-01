## Reto 4 de Alejandro Rubio Martinez

##### Codificación

Vamos a hacer un árbol a partir de un vector de enteros. Para ello lo que intentamos hacer es usar el menor número de centinelas posible. La solución que yo propongo es realizar un árbol binario tal que los elementos del vector que vamos cogiendo los introduzcamos en orden en el árbol de izquierda a derecha en preorden. Es decir, si tenemos el vector `{1,2,3,4,5}` los introduzcamos en este orden:

```c++
		1
	  /   \
	2		3
  /   \
4		5
```

Nos ayudamos de los NULL de c++ para escribir este árbol como el vector `{1,2,3,4,5,NULL,NULL}` empezando siempre por el nodo que no tiene padre y escribiendo de izquierda a derecha. Para hacer esto en el vector que nos dan tan sólo tenemos que rellenar con NULL hasta que tengamos un número que lo podamos expresar como suma de potencias de 2.

##### Decodificación

La decodificación de este árbol sería tan sencilla como una vez que tenemos el vector que representa al árbol eliminar los elementos NULL.