# Información General

A menos que se indique lo contrario, las siguientes condiciones se aplican a todos los problemas.

## Nombre del Programa

1. Tu solución debe llamarse `codename.c`, `codename.cpp`, `codename.java`, `codename.kt`, `codename.py2` o `codename.py3`, donde `codename` es la letra mayúscula que identifica el problema.

## Entrada

1. La entrada debe leerse de la entrada estándar.
2. La entrada consiste en un único caso de prueba, que se describe usando un número de líneas que depende del problema. No aparecerán datos adicionales en la entrada.
3. Cuando una línea de datos contiene varios valores, están separados por espacios simples. No aparecen otros espacios en la entrada. No hay líneas vacías.
4. Se utiliza el alfabeto inglés. No hay letras con tildes, acentos, diéresis u otros signos diacríticos.
5. Cada línea, incluida la última, tiene la marca de fin de línea habitual.

## Salida

1. La salida debe escribirse en la salida estándar.
2. El resultado del caso de prueba debe aparecer en la salida utilizando un número de líneas que depende del problema. No deben aparecer datos adicionales en la salida.
3. Cuando una línea de resultados contiene varios valores, deben estar separados por espacios simples. No deben aparecer otros espacios en la salida. No debe haber líneas vacías.
4. Se debe utilizar el alfabeto inglés. No debe haber letras con tildes, acentos, diéresis u otros signos diacríticos.
5. Cada línea, incluida la última, debe tener la marca de fin de línea habitual.
6. Para la salida de números reales, redondearlos al racional más cercano con el número requerido de dígitos después del punto decimal. Los casos de prueba son tales que no hay empates al redondear como se especifica.

# Problema A - Enseñanza de Algoritmos

El Concurso Regional de Principiantes de América Latina se acerca, y la Universidad de Byteland quiere preparar un equipo de estudiantes recién admitidos para competir. La universidad tiene N profesores que pueden instruir a los estudiantes en el tema de algoritmos. Cada estudiante candidato debe ser entrenado por un solo profesor, en un subconjunto no vacío de algoritmos que el profesor conoce. Por ejemplo, si un profesor conoce los algoritmos PRIM y KRUSKAL, entonces puede entrenar a un estudiante solo en PRIM, solo en KRUSKAL, o en ambos PRIM y KRUSKAL. Como puedes ver, en este caso hay tres opciones diferentes para que este profesor entrene a un estudiante. En general, un profesor que conoce A algoritmos diferentes puede entrenar a un estudiante en 2^A - 1 formas diferentes. Todas estas 2^A - 1 opciones se pueden llevar a cabo, porque la universidad tiene muchos estudiantes nuevos y no hay límite en el número de estudiantes que un profesor puede entrenar.

La universidad quisiera formar un equipo con la mayor cantidad posible de estudiantes. Sin embargo, cada par de estudiantes en el equipo final debe poder cooperar, lo que significa que cada uno de ellos debe haber sido entrenado en un algoritmo que el otro no ha sido. Por ejemplo, un estudiante entrenado en BFS y DFS puede cooperar con otro estudiante entrenado en DFS y DIJKSTRA, porque el primer estudiante está entrenado en BFS mientras que el segundo no, y el segundo estudiante está entrenado en DIJKSTRA mientras que el primero no. Por otro lado, un estudiante entrenado en BFS y DFS no puede cooperar con otro estudiante entrenado solo en BFS, solo en DFS, o en ambos BFS y DFS, entre otros.

Dado el conjunto de algoritmos que cada profesor conoce, debes determinar el número máximo de estudiantes en un equipo en el que cada estudiante pueda cooperar con los demás. Recuerda que cada estudiante debe ser entrenado por un solo profesor, mientras que cada profesor puede entrenar a tantos estudiantes como sea necesario. Por ejemplo, si hay solo un profesor que conoce los algoritmos DFS, BFS y DIJKSTRA, es posible preparar un equipo con hasta tres estudiantes: un primer estudiante entrenado en DFS y BFS, un segundo estudiante entrenado en DFS y DIJKSTRA, y un tercer estudiante entrenado en BFS y DIJKSTRA.

## Entrada

La primera línea contiene un número entero N (1 <= N <= 100) que indica el número de profesores. Cada una de las siguientes N líneas describe a un profesor con un entero A (1 <= A <= 10) que representa el número de algoritmos que el profesor conoce, seguido de A cadenas de caracteres no vacías y diferentes de como máximo 10 letras mayúsculas cada una, indicando los nombres de los algoritmos que el profesor conoce.

## Salida

Salida una sola línea con un número entero que indica el número máximo de estudiantes en un equipo en el que cada estudiante pueda cooperar con los demás.

## Kotlin

Explicación del Código Kotlin:
1. Función `maxCooperatingStudents`:
   - Crea subconjuntos de algoritmos que cada profesor puede enseñar.
   - Utiliza  `1 shl A` para generar todas las combinaciones posibles de algoritmos.
   - Añade cada subconjunto a la lista `sets`.
3. Bucle principal para calcular el número máximo de estudiantes:
   - Compara cada subconjunto de algoritmos para asegurarse de que los estudiantes pueden cooperar (es decir, que no comparten algoritmos en común).
   - Actualiza `maxStudents` con el número máximo de estudiantes cooperativos.
4. Función `main`:
   - Lee la entrada y la procesa en una lista de listas.
   - Llama a la función maxCooperatingStudents y imprime el resultado.

Código:
```kotlin
fun maxCooperatingStudents(teachers: List<List<String>>): Int {
    val sets = mutableListOf<Set<String>>()
    
    // Crear subconjuntos de algoritmos que cada profesor puede enseñar
    for (teacher in teachers) {
        val A = teacher.size
        for (i in 1 until (1 shl A)) {
            val subset = mutableSetOf<String>()
            for (j in 0 until A) {
                if ((i and (1 shl j)) != 0) {
                    subset.add(teacher[j])
                }
            }
            sets.add(subset)
        }
    }
    
    var maxStudents = 0
    // Encontrar el número máximo de estudiantes que pueden cooperar
    for (i in sets.indices) {
        var count = 1
        for (j in i + 1 until sets.size) {
            val cooperative = sets[i].none { it in sets[j] }
            if (cooperative) count++
        }
        maxStudents = maxOf(maxStudents, count)
    }
    
    return maxStudents
}

fun main() {
    val input = generateSequence(::readLine).toList()
    val N = input[0].toInt()
    val teachers = input.drop(1).map { it.split(" ").drop(1) }
    println(maxCooperatingStudents(teachers))
}
```
