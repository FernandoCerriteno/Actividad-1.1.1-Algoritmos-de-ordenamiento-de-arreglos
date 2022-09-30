# Actividad-1.1.1-Algoritmos-de-ordenamiento-de-arreglos
Ejecución de los algoritmos de ordenamiento - Bubble sort, Quick Sort, Merge Sort
El código pide que se ingrrese el tamaño de datos dentro del vector, esto hace referencia al tamaño del vector con datos aleatorios que 
se creara para poder trabajar con los vectores

Descripción
Para esta actividad se realizaron tres algoritmos de ordenamiento, Ordenamiento de Burbuja, Ordenamiento por fusión, y un ordenamiento 
Rápido. Así mismo se obtuvieron el numero de comparaciones que se realizaron en cada uno de estos, con el propósito de observar la eficiencia 
de cada uno de ellos en listas de diferentes tamaños.

Tabla comparativa
Para obtener los datos de esta tabla se crearon vectores de tamaño 10, 100, 1000 y 10 000, cada una con datos aleatorios para mostrar la 
eficiencia de cada uno de los algoritmos, a cada algoritmo se le ingreso el vector por primera vez para que lo ordene, después se le volvió 
a introducir el mismo vector ya ordenado, y finalmente se ordeno el vector de mayor a menor y se volvió a introducir.

Estos fueron los resultados:

Primer Ordenamiento
            Vector de 10	  Vector de 100	  Vector de 1000
Bubble Sort	    45	          4950	          499500
Quick Sort	    25	          585	            10908
Merge Sort	    22	          549	            8678

Vector Ordenado
	          Vector de 10	  Vector de 100	  Vector de 1000
Bubble Sort	    45		        4950	          499500
Quick Sort	    45	          4950	          499500
Merge Sort	    19	          356	            5044

Ordenado de forma descendente
	          Vector de 10	  Vector de 100	  Vector de 1000
Bubble Sort	    45	          4950	          499500
Quick Sort	    45	          4878	          328205
Merge Sort	    15	          319	            5146

Analizando los resultados en la tabla podemos observar que el mejor algoritmo para ordenamiento resulta el de divide y vencerás, 
teniendo el menor numero de comparaciones en todas las pruebas, aunque su implementación resulta ser un poco tediosa, el tiempo de ejecución 
resulta demasiado conveniente, mientras que en un proyecto de poca escala, esta complejidad temporal no representa un problema mayor, en un 
proyecto donde se tenga que trabajar con millones de datos, se puede notar la diferencia en los tiempos de ejecución.
