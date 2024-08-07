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

## Pseudocódigo

Explicación del Pseudocódigo
1. Función max_cooperating_students:
   - Entrada: Lista de profesores, donde cada profesor tiene una lista de algoritmos que conoce.
   - Proceso:
      - Para cada profesor, se generan todos los subconjuntos posibles de algoritmos que el profesor puede enseñar.
      - Se almacenan estos subconjuntos en una lista sets.
   - Salida: Número máximo de estudiantes que pueden cooperar entre sí.
2. Generación de Subconjuntos:
   - Utiliza la técnica de generación de subconjuntos usando bits (bitmasking). Para cada subconjunto posible, añade los algoritmos correspondientes al subconjunto.
3. Cálculo del Número Máximo de Estudiantes Cooperativos:
   - Compara cada conjunto con todos los demás conjuntos para verificar que no tienen elementos comunes (es decir, que pueden cooperar).
   - Mantiene un contador count para rastrear el número de estudiantes cooperativos.
   - Actualiza el número máximo de estudiantes cooperativos max_students.
4. Función Principal:
   - Entrada: Lee el número de profesores y la lista de algoritmos que cada profesor conoce.
   - Proceso: Llama a max_cooperating_students con la lista de profesores.
   - Salida: Imprime el resultado.

```pseudo
función max_cooperating_students(profesores):
    conjuntos = lista vacía

    para cada profesor en profesores:
        algoritmos = algoritmos que el profesor conoce
        A = número de algoritmos que el profesor conoce
        para i de 1 a 2^A - 1:
            subconjunto = conjunto vacío
            para j de 0 a A-1:
                si i-ésimo bit de i está encendido:
                    añadir algoritmos[j] a subconjunto
            añadir subconjunto a conjuntos

    max_estudiantes = 0

    para cada conjunto en conjuntos:
        cuenta = 1
        para cada otro conjunto en conjuntos:
            si conjunto y otro_conjunto no tienen elementos comunes:
                incrementar cuenta
        actualizar max_estudiantes con el máximo de cuenta y max_estudiantes

    retornar max_estudiantes

función principal:
    leer N (número de profesores)
    inicializar lista de profesores
    para cada profesor:
        leer A (número de algoritmos)
        leer algoritmos que el profesor conoce
        añadir lista de algoritmos a lista de profesores
    llamar a max_cooperating_students con la lista de profesores
    imprimir el resultado
```

## Solución en Kotlin

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

## Solución en Python 3

Explicación del Código Python 3:

1. Función `max_cooperating_students`:
   - Crea subconjuntos de algoritmos que cada profesor puede enseñar.
   - Utiliza combinaciones para generar todas las posibles combinaciones de algoritmos.
   - Añade cada subconjunto a la lista `sets`.
2. Bucle principal para calcular el número máximo de estudiantes:
   - Compara cada subconjunto de algoritmos para asegurarse de que los estudiantes pueden cooperar (es decir, que no comparten algoritmos en común).
   - Actualiza `max_students` con el número máximo de estudiantes cooperativos.
3. Bloque principal:
   - Lee la entrada desde stdin y la procesa en una lista de listas.
   - Llama a la función max_cooperating_students y imprime el resultado.

Código:
```python3
def max_cooperating_students(teachers):
    from itertools import combinations
    
    sets = []
    
    # Crear subconjuntos de algoritmos que cada profesor puede enseñar
    for teacher in teachers:
        algorithms = teacher[1:]
        A = len(algorithms)
        for i in range(1, 1 << A):
            subset = set()
            for j in range(A):
                if i & (1 << j):
                    subset.add(algorithms[j])
            sets.append(subset)
    
    max_students = 0
    # Encontrar el número máximo de estudiantes que pueden cooperar
    for combo in combinations(sets, len(sets)):
        all_pairs_cooperate = True
        for i in range(len(combo)):
            for j in range(i + 1, len(combo)):
                if not (combo[i] - combo[j] and combo[j] - combo[i]):
                    all_pairs_cooperate = False
                    break
            if not all_pairs_cooperate:
                break
        if all_pairs_cooperate:
            max_students = max(max_students, len(combo))
    
    return max_students

if __name__ == "__main__":
    import sys
    input = sys.stdin.read
    data = input().strip().split("\n")
    
    N = int(data[0])
    teachers = []
    
    for i in range(1, N + 1):
        line = data[i].split()
        A = int(line[0])
        algorithms = line[1:]
        teachers.append((A, *algorithms))
    
    print(max_cooperating_students(teachers))
```

## Solución en C

Explicación del Código C:

1. Función max_cooperating_students:
   - Crea subconjuntos de algoritmos que cada profesor puede enseñar.
   - Utiliza bits para generar todas las combinaciones posibles de algoritmos.
   - Añade cada subconjunto a la lista `sets`.
2. Bucle principal para calcular el número máximo de estudiantes:
   - Compara cada subconjunto de algoritmos para asegurarse de que los estudiantes pueden cooperar (es decir, que no comparten algoritmos en común).
   - Actualiza `max_students` con el número máximo de estudiantes cooperativos.
3. Función main:
   - Lee la entrada desde stdin y la procesa en matrices.
   - Llama a la función `max_cooperating_students` y imprime el resultado.

Código:
```c
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_ALGORITHMS 10
#define MAX_TEACHERS 100
#define MAX_LENGTH 11

int max_cooperating_students(int N, int A[], char algorithms[][MAX_ALGORITHMS][MAX_LENGTH]) {
    int max_students = 0;
    int sets[1024][MAX_ALGORITHMS], set_sizes[1024], num_sets = 0;
    
    // Crear subconjuntos de algoritmos que cada profesor puede enseñar
    for (int t = 0; t < N; ++t) {
        int a = A[t];
        for (int i = 1; i < (1 << a); ++i) {
            set_sizes[num_sets] = 0;
            for (int j = 0; j < a; ++j) {
                if (i & (1 << j)) {
                    strcpy(sets[num_sets][set_sizes[num_sets]++], algorithms[t][j]);
                }
            }
            ++num_sets;
        }
    }
    
    // Encontrar el número máximo de estudiantes que pueden cooperar
    for (int i = 0; i < num_sets; ++i) {
        int count = 1;
        for (int j = i + 1; j < num_sets; ++j) {
            int cooperative = 1;
            for (int k = 0; k < set_sizes[i]; ++k) {
                for (int l = 0; l < set_sizes[j]; ++l) {
                    if (strcmp(sets[i][k], sets[j][l]) == 0) {
                        cooperative = 0;
                        break;
                    }
                }
                if (!cooperative) break;
            }
            if (cooperative) ++count;
        }
        if (count > max_students) max_students = count;
    }
    
    return max_students;
}

int main() {
    int N;
    scanf("%d", &N);
    
    int A[MAX_TEACHERS];
    char algorithms[MAX_TEACHERS][MAX_ALGORITHMS][MAX_LENGTH];
    
    // Leer la entrada
    for (int i = 0; i < N; ++i) {
        scanf("%d", &A[i]);
        for (int j = 0; j < A[i]; ++j) {
            scanf("%s", algorithms[i][j]);
        }
    }
    
    int result = max_cooperating_students(N, A, algorithms);
    printf("%d\n", result);
    
    return 0;
}
```

## Solución en C++

Explicación del Código C++:

1. Función `max_cooperating_students`:
   - Crea subconjuntos de algoritmos que cada profesor puede enseñar.
   - Utiliza bits para generar todas las combinaciones posibles de algoritmos.
   - Añade cada subconjunto a la lista `sets`.
2. Bucle principal para calcular el número máximo de estudiantes:
   - Compara cada subconjunto de algoritmos para asegurarse de que los estudiantes pueden cooperar (es decir, que no comparten algoritmos en común).
   - Actualiza `max_students` con el número máximo de estudiantes cooperativos.
3. Función main:
   - Lee la entrada desde `cin` y la procesa en un vector de vectores.
   - Llama a la función `max_cooperating_students` y imprime el resultado.

Código:
```c++
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int max_cooperating_students(int N, vector<vector<string>> teachers) {
    vector<set<string>> sets;
    
    // Crear subconjuntos de algoritmos que cada profesor puede enseñar
    for (int t = 0; t < N; ++t) {
        int A = teachers[t].size();
        for (int i = 1; i < (1 << A); ++i) {
            set<string> subset;
            for (int j = 0; j < A; ++j) {
                if (i & (1 << j)) {
                    subset.insert(teachers[t][j]);
                }
            }
            sets.push_back(subset);
        }
    }
    
    int max_students = 0;
    // Encontrar el número máximo de estudiantes que pueden cooperar
    for (int i = 0; i < sets.size(); ++i) {
        int count = 1;
        for (int j = i + 1; j < sets.size(); ++j) {
            bool cooperative = true;
            for (const auto& algo : sets[i]) {
                if (sets[j].count(algo)) {
                    cooperative = false;
                    break;
                }
            }
            if (cooperative) ++count;
        }
        max_students = max(max_students, count);
    }
    
    return max_students;
}

int main() {
    int N;
    cin >> N;
    vector<vector<string>> teachers(N);
    
    // Leer la entrada
    for (int i = 0; i < N; ++i) {
        int A;
        cin >> A;
        teachers[i].resize(A);
        for (int j = 0; j < A; ++j) {
            cin >> teachers[i][j];
        }
    }
    
    int result = max_cooperating_students(N, teachers);
    cout << result << endl;
    
    return 0;
}
```
