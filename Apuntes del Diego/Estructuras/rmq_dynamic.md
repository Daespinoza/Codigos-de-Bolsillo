# Range Maximum Query (RMQ) con Segment Tree

Este código implementa un algoritmo de consulta de máximo rango (RMQ) utilizando un árbol de segmentos. El árbol permite realizar consultas sobre el rango de un arreglo para encontrar el valor máximo en un intervalo específico, así como actualizar los valores en el arreglo de manera eficiente.

## Descripción del Código

El código está estructurado en una clase `RMQ` que contiene métodos para inicializar el árbol, construirlo, realizar consultas de máximo en un rango y actualizar los valores.

### Componentes del Código

- **Definiciones y Tipos**:
  - `MAXN`: Máximo tamaño del arreglo (100,000).
  - `operacion(x, y)`: Macro que define la operación a realizar (en este caso, `max`).
  - `neutro`: Valor neutro para la operación (0).

- **Estructura `RMQ`**:
  - `sz`: Tamaño del árbol de segmentos.
  - `t`: Array que representa el árbol de segmentos.
  - `init(int n)`: Inicializa el árbol con un tamaño dado.
  - `updall()`: Construye el árbol completo después de inicializar.
  - `get(int i, int j)`: Consulta el máximo en el rango `[i, j)`.
  - `set(int p, tipo val)`: Actualiza el valor en la posición `p` con el nuevo valor `val`.

### Uso del Código

1. **Compilación**:
   Para compilar el código, puedes usar un compilador de C++ como `g++`. Ejecuta el siguiente comando en la terminal:

   ```bash
   g++ -o r_max_query r_max_query.cpp
   ```
   Asegúrate de reemplazar r_max_query.cpp con el nombre real de tu archivo fuente si es diferente.

2. **Ejecución**: 
   Una vez compilado, ejecuta el programa:

    ```bash
   ./r_max_query
   ```

3. **Interacción**:
   - El programa generará un arreglo aleatorio y te mostrará los valores generados.
   - Realizará varias consultas aleatorias para obtener el máximo en un rango específico.
   - Te permitirá realizar actualizaciones en el arreglo y volver a consultar el máximo en el mismo rango.

## Explicación del Código del RMQ Dinámico

### Estructura `RMQ`

La estructura `RMQ` se utiliza para gestionar consultas de rango de máximo en un arreglo dinámico. Aquí se detallan sus componentes:

- **Definiciones y macros**:
    - `#define MAXN 100000`: Define el tamaño máximo del arreglo.
    - `#define operacion(x, y) max(x, y)`: Define la operación a realizar sobre los elementos, que en este caso es el máximo.
    - `#define forn(i, n) for(int i = 0; i < n; ++i)`: Macro para un bucle for estándar.
    - `#define dforn(i, n) for (int i = n - 1; i >= 0; --i)`: Macro para un bucle for que itera en reversa.

- **Variables miembro**:
    - `int sz;`: Tamaño del segmento.
    - `tipo t[4 * MAXN];`: Árbol segmentado, donde se almacenarán los valores.

- **Método `operator[]`**:
    ```cpp
    tipo &operator[](int p) { return t[sz + p]; }
    ```
    Permite acceder directamente a los elementos en el segmento original, utilizando un índice que se ajusta al árbol segmentado.

### Métodos de la estructura `RMQ`

1. **Inicialización**:
    ```cpp
    void init(int n) {  // O(n log n)
        sz = 1 << (32 - __builtin_clz(n - 1));  // Ajusta tamaño a la potencia de 2 más cercana
        forn(i, 2 * sz) t[i] = neutro;
    }
    ```
    - Ajusta el tamaño `sz` a la potencia de 2 más cercana mayor o igual a `n`, lo cual es importante para construir un árbol segmentado equilibrado.
    - Inicializa el árbol segmentado `t` con un valor neutro (0) en todas las posiciones.

2. **Construcción del árbol**:
    ```cpp
    void updall() {  // O(n)
        dforn(i, sz) t[i] = operacion(t[2 * i], t[2 * i + 1]);
    }
    ```
    - Rellena el árbol segmentado en un tiempo de `O(n)` calculando el máximo entre cada par de nodos hijo para construir el nodo padre.

3. **Consulta de rango**:
    ```cpp
    tipo get(int i, int j) { return get(i, j, 1, 0, sz); }
    ```
    - Método que recibe los límites del rango y llama a una función recursiva para obtener el máximo en el rango `[i, j)`.

    ```cpp
    tipo get(int i, int j, int n, int a, int b) {  // O(log n)
        if (j <= a || i >= b) return neutro;   // Caso fuera de rango
        if (i <= a && b <= j) return t[n];     // Caso completamente dentro del rango
        int c = (a + b) / 2;
        return operacion(get(i, j, 2 * n, a, c), get(i, j, 2 * n + 1, c, b));
    }
    ```
    - Verifica si el rango actual está fuera de los límites; si es así, devuelve el valor neutro.
    - Si el rango está completamente dentro de los límites, devuelve el valor almacenado en el nodo actual.
    - Si hay intersección, divide el rango y consulta recursivamente en los nodos hijo.

4. **Actualización de valores**:
    ```cpp
    void set(int p, tipo val) {  // O(log n)
        for (p += sz; p > 0 && t[p] != val;) {
            t[p] = val; 
            p /= 2;
            val = operacion(t[p * 2], t[p * 2 + 1]);
        }
    }
    ```
    - Actualiza el valor en la posición `p` con el nuevo valor `val`.
    - Empieza desde la hoja correspondiente y sube por el árbol, actualizando los nodos padre hasta llegar a la raíz.
    - La condición `t[p] != val` garantiza que solo se actualicen los nodos que realmente necesitan ser modificados.

### Notas Adicionales

- **Tipo de dato**: `typedef int tipo;` se utiliza para definir el tipo de dato del arreglo, lo que permite cambiar fácilmente el tipo si es necesario.
- **Valor neutro**: `const int neutro = 0;` es el valor que se utiliza para el caso en que no hay elementos en un rango dado o para inicializar el árbol.
