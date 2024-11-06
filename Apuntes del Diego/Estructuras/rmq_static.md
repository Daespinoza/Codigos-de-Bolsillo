# Range Minimum Query (RMQ) con Estructura de Datos de Sparse Table

Este código implementa un algoritmo de consulta de mínimo rango (RMQ) utilizando una estructura de datos llamada Sparse Table. Esta estructura permite realizar consultas eficientes sobre el rango de un arreglo para encontrar el valor mínimo en un intervalo específico.

## Descripción del Código

La implementación en este código está contenida en una estructura llamada RMQ, que proporciona una manera eficiente de realizar consultas de mínimo en rangos de un arreglo estático.

## Componentes del Código

- **Definiciones y Tipos:**
    - `LVL`: Define el número de niveles en la tabla, en este caso se define como 10, lo que indica que se pueden manejar arreglos de hasta 2^11 elementos (2048 elementos).
    - `tipo`: Es el tipo de los elementos que va a manejar la estructura, en este caso es un int.
    - `vec[LVL][1 << (LVL + 1)]`: Es la tabla que almacena los valores mínimos precomputados para los diferentes tamaños de intervalos.
- **Métodos de la estructura `RMQ`:**
    - `operator[]`: Permite acceder a los elementos del arreglo de entrada directamente.
    - `build(int n)`: Construye la tabla de Sparse Table a partir del arreglo de entrada.
    - `get(int i, int j)`: Realiza una consulta de mínimo sobre el intervalo `[i, j]`.

## Explicación del Código

La estructura `RMQ` está diseñada para realizar consultas de mínimo en rangos de un arreglo de manera eficiente. A continuación se detallan sus componentes clave:

1. **Inicialización de la Tabla:**

```cpp
    void build(int n) {
        int mp = 31 - __builtin_clz(n);  // Calcula el número de niveles de la tabla
        forn(p, mp) forn(x, n - (1 << p))
            vec[p + 1][x] = std::min(vec[p][x], vec[p][x + (1 << p)]);
    }
```

- `build(int n)`: Este método construye la tabla Sparse Table. La construcción se realiza en `O(n log n)` en tiempo. Se calcula el número de niveles de la tabla `mp` y, luego, se completa cada nivel utilizando la relación recursiva para obtener el mínimo entre dos rangos adyacentes de tamaños `2^p`. Este proceso llena la tabla `vec` con los valores mínimos precomputados.

2. **Consulta de Mínimo en un Rango:**

```cpp
    tipo get(int i, int j) { // intervalo [i, j)
        int p = 31 - __builtin_clz(j - i);  // Calcula el tamaño del intervalo en términos de potencias de 2
        return std::min(vec[p][i], vec[p][j - (1 << p)]);  // Realiza la consulta
    }
```

- `get(int i, int j)`: Este método permite realizar una consulta en el intervalo `[i, j]`. Se utiliza la propiedad de la Sparse Table para calcular el valor mínimo en el intervalo con solo dos consultas a la tabla, lo que hace que el tiempo de consulta sea `O(1)`. Se calcula el valor de p como la potencia de 2 más grande menor o igual a `j - i`, y luego se consulta el valor mínimo entre los dos rangos de tamaño `2^p` que cubren el intervalo completo.

3. **Operador []:**

```cpp
    tipo &operator[](int p) { return vec[0][p]; }
```

- `operator[]`: Permite acceder directamente a los elementos en la tabla `vec` del nivel 0, es decir, a los valores iniciales del arreglo. Este operador facilita la consulta directa sobre los valores de entrada del arreglo.

## Uso del Código

1. **Compilación**: Para compilar el código, puedes usar un compilador de C++ como `g++`. Ejecuta el siguiente comando en la terminal:

```bash
g++ -o rmq_query rmq_query.cpp
```

Asegúrate de reemplazar `rmq_query.cpp` con el nombre real de tu archivo fuente si es diferente.

2. **Ejecución**: Una vez compilado, ejecuta el programa con:

```bash
./rmq_query
```

3. **Interacción**:

- El programa generará un arreglo aleatorio de enteros y construirá la Sparse Table para ese arreglo.
- Realizará consultas para obtener el mínimo en intervalos específicos y mostrará los resultados.

## Detalle de la Implementación de Sparse Table

La Sparse Table es un tipo de estructura de datos que permite realizar consultas de mínimo (o máximo) de forma eficiente en un arreglo estático, con un tiempo de consulta `O(1)` después de un preprocesamiento que toma `O(n log n)` de tiempo. Es particularmente útil cuando se tiene un arreglo fijo y no se realizan actualizaciones dinámicas sobre él.

**Explicación de la Fórmula de Preprocesamiento:**

El preprocesamiento de la Sparse Table se basa en la siguiente idea: para cada posible longitud de intervalo 2^p, precomputamos los valores mínimos en todos los intervalos posibles. La relación de recursión utilizada para llenar la tabla es:

$$ \min(A[i], A[i+2p], A[i+2p+1], \dots) $$

Este preprocesamiento permite que la consulta de un rango sea extremadamente rápida, simplemente comparando los valores precomputados de los dos rangos que cubren el intervalo.

## Ventajas y Limitaciones:

### Ventajas:
- Las consultas son extremadamente rápidas ( `O(1)` ).
- El código es fácil de implementar y muy eficiente para arreglos estáticos.

### Limitaciones:
- No soporta actualizaciones dinámicas (es decir, no se pueden modificar los valores en el arreglo después de la construcción de la Sparse Table).

## Conclusión
Este código es una implementación eficiente del algoritmo RMQ utilizando una Sparse Table. Es ideal para aplicaciones donde se deben realizar muchas consultas de mínimo en un arreglo estático sin necesidad de actualizar los valores.