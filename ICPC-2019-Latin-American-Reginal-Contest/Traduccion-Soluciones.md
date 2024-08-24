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

# Problema B: Construir la Casa Perfecta

Alicia y Bob tienen 45 años y han pasado cinco años de retiro cuidando de su campo de vegetales. Ir y venir desde su casa en la ciudad hasta el campo se ha vuelto una tarea agotadora, así que han decidido mudarse al campo permanentemente. Actualmente, tienen una cerca perfecta que rodea todas las plantas vegetales (con un perímetro y área mínimos), pero van a derribar la cerca vieja y construir una nueva casa perfecta donde puedan vivir.

Entonces, ¿qué es una casa perfecta? Tiene algunos requisitos:

1. El área de la casa debe ser un cuadrado centrado en el punto del campo con la vista más hermosa (el origen (0,0)).
2. La casa no puede ser construida sobre ningún vegetal, aunque es posible tener vegetales justo en el borde de la casa.

Alicia y Bob aman los espacios amplios, por lo que tu tarea es determinar el máximo perímetro que puede tener una casa perfecta.

## Entrada

La primera línea contiene un entero N (1 ≤ N ≤ 10,000) indicando el número de plantas de vegetales en el campo de Alicia y Bob.
Cada una de las siguientes N líneas describe una planta de vegetales con dos enteros X y Y (-10^9 ≤ X, Y ≤ 10^9) que indican las coordenadas de la planta. Ninguna planta está en el punto (0,0) y no hay dos plantas en la misma ubicación.

## Salida

Debes imprimir una única línea con un número que indique el perímetro máximo que puede tener la casa perfecta, con exactamente cuatro dígitos después del punto decimal, redondeado si es necesario. Nota que los lados de la casa no necesitan estar alineados con los ejes de las coordenadas.

## Explicación

Imagina que las plantas de vegetales están representadas por puntos en un plano bidimensional. La casa perfecta será un cuadrado cuyo centro esté en el origen (0,0) y que no cubra ningún vegetal en su interior. Sin embargo, la casa puede tocar los vegetales en su borde. Debemos encontrar el tamaño del cuadrado más grande posible (en términos de perímetro) que cumpla con estas condiciones.

El problema esencialmente se reduce a encontrar la distancia máxima de cualquier vegetal desde el origen, ya que esta determinará el radio del círculo circunscrito alrededor del cuadrado más grande que se pueda construir.

## Pseudocódigo

1. Entrada de Datos:
   - Leer N (número de vegetales).
   - Leer las coordenadas (X, Y) de cada vegetal.
2. Calcular la Distancia:
   - Para cada vegetal, calcular la distancia euclidiana desde el origen (0, 0) usando la fórmula de distancia: dist = sqrt(X^2 + Y^2).
3. Encontrar la Distancia Máxima:
   - Mantener un registro de la distancia máxima encontrada.
4. Calcular el Perímetro Máximo:
   - Dado que el cuadrado más grande está circunscrito por un círculo con radio igual a la distancia máxima, el lado del cuadrado es 2 * dist_max / sqrt(2) y el perímetro es 4 * lado.
   - Alternativamente, usar directamente la relación geométrica que establece que el perímetro del cuadrado es 8 * dist_max.
5. Salida:
   - Imprimir el perímetro máximo con 4 dígitos decimales.

```pseudo
function calcular_perimetro_maximo(N, vegetales):
    max_distancia = 0

    for cada vegetal (X, Y) en vegetales:
        # Calcular la distancia euclidiana desde el origen
        distancia = sqrt(X^2 + Y^2)
        
        # Actualizar la distancia máxima
        if distancia > max_distancia:
            max_distancia = distancia

    # El perímetro máximo es 8 veces la distancia máxima
    perimetro_maximo = 8 * max_distancia
    
    # Imprimir el resultado con 4 dígitos decimales
    print("{:.4f}".format(perimetro_maximo))

# Leer la entrada
N = leer_entero()
vegetales = leer_lista_de_pares(N)

# Calcular y mostrar el resultado
calcular_perimetro_maximo(N, vegetales)
```

### Explicación del Pseudocódigo
1. calcular_perimetro_maximo(N, vegetales):
   - Inicializamos una variable max_distancia en 0 para almacenar la distancia más grande desde el origen.
   - Iteramos a través de todos los vegetales. Para cada vegetal, calculamos la distancia euclidiana desde el origen (0, 0) utilizando la fórmula sqrt(X^2 + Y^2).
   - Si la distancia calculada es mayor que max_distancia, actualizamos max_distancia.
   - Una vez procesados todos los vegetales, calculamos el perímetro máximo usando la fórmula perimetro_maximo = 8 * max_distancia y lo imprimimos con 4 dígitos decimales.

### Notas Finales
   - La complejidad del algoritmo es O(N), donde N es el número de vegetales, ya que estamos procesando cada vegetal una vez.
   - Este enfoque garantiza que encontramos la mayor distancia y, por lo tanto, el mayor perímetro posible para la casa perfecta que se puede construir en el campo.

# Problema C - Reducir la Desigualdad

Complejidonia no siempre ha sido la tierra pacífica e igualitaria que todos conocemos hoy. Los ricos Constantones eran los dueños de los medios locales y sumieron a Complejidonia en la tiranía de su despiadado sistema económico: el Nlogonialismo, un sistema que promovía una desigualdad extrema que, curiosamente, siempre beneficiaba a los Constantones.

Mientras que los Constantones poseían la mayor parte de la riqueza, los Cuadradones vivían en extrema pobreza, y la desigualdad se justificaba etiquetando a los Cuadradones como perezosos e ineficientes. Los Nlogones generalmente menospreciaban a los Cuadradones, a pesar de trabajar tanto como ellos, creyendo que estaban mejor gracias a su mezcla de trabajo duro y astucia. Para los Cubiones y Cuaterniones era aún peor, ya que, al provenir de países vecinos, se les veía como criminales y, al mismo tiempo, se les acusaba de robar empleos en Complejidonia.

Todo cambió después de que el Congreso Internacional Colectivista y Popular (ICPC) logró derrocar a los Constantones e instaurar un nuevo sistema económico, un sistema que se esfuerza por la equidad y que tiene en cuenta que cada habitante puede pasar por buenos y malos períodos económicos en la vida.

En el nuevo sistema se estableció un límite superior U sobre cuánta riqueza puede acumular una persona y un límite inferior L que representa la riqueza mínima requerida para que una persona mantenga un estilo de vida decente. Al final de cada mes, cada habitante evalúa su riqueza. Aquellos con más de U donarán el excedente al ICPC, mientras que aquellos que tengan menos de L recibirán lo necesario del ICPC para alcanzar el límite inferior establecido.

Los Cuadradones, que son muy buenos agricultores, necesitan tu ayuda para gestionar sus finanzas. La larga era del Nlogonialismo ha dañado gravemente el medio ambiente y ahora el clima en Complejidonia es muy volátil. Esto tiene un gran impacto en su agricultura, que fluctúa entre períodos buenos y malos.

Un agricultor lleva un registro largo A1, A2, ..., An de sus ingresos netos (ingresos menos gastos) durante una secuencia de N meses. Basado en estos datos, el agricultor quiere planificar cómo invertir su riqueza para evitar ser una carga para el ICPC en el futuro. El agricultor quiere saber, dado un valor inicial de riqueza X al comienzo de un mes B, cuánto poseerá al final del mes E (teniendo en cuenta que al final de cada mes puede donar o recibir una donación para asegurarse de que su riqueza esté entre L y U, inclusive).

## Entrada
   - La primera línea contiene tres enteros N (1 ≤ N ≤ 10^5), L y U (1 ≤ L ≤ U ≤ 2 * 10^6), indicando respectivamente el número de meses para los cuales el agricultor tiene registros de ingresos netos, el límite inferior de riqueza y el límite superior de riqueza.
   - La segunda línea contiene N enteros A1, A2, ..., An (-10^6 ≤ Ai ≤ 10^6 para i = 1, 2, ..., N), donde Ai es el ingreso neto en el mes i.
   - La tercera línea contiene un entero Q (1 ≤ Q ≤ 10^5) que representa el número de escenarios en los que el agricultor está interesado. Cada una de las siguientes Q líneas describe un escenario con tres enteros B, E (1 ≤ B ≤ E ≤ N) y X (L ≤ X ≤ U), indicando que el agricultor quiere saber cuánto poseerá al final del mes E si comienza con una riqueza de X al inicio del mes B, y cada mes j = B, B + 1, ..., E su ingreso neto es Aj.

## Salida
   - Imprime Q líneas, cada una con un entero que indica cuánto poseerá el agricultor al final del período descrito en el escenario correspondiente.

## Explicación

El problema presenta una historia ficticia sobre un país llamado Complejidonia, donde se estableció un nuevo sistema económico para garantizar la equidad entre sus habitantes. Este sistema establece límites superiores e inferiores en la riqueza de los individuos. Si alguien tiene más riqueza de la permitida, debe donar el excedente, y si tiene menos, recibe una donación hasta alcanzar el mínimo requerido.

El problema consiste en ayudar a un agricultor a gestionar sus finanzas. Se nos proporciona un registro de ingresos netos durante varios meses. Basándonos en este registro, debemos responder a múltiples consultas que indican, dada una riqueza inicial en un mes específico, cuánto tendrá el agricultor al final de un período determinado.

Para cada consulta, el agricultor quiere saber cuánto poseerá al final del período después de haber ajustado su riqueza de acuerdo con los límites establecidos por el sistema (donando o recibiendo donaciones cuando sea necesario).

## Pseudocódigo

1. Inicialización:
   - Leer los valores de N, L, U (número de meses, límite inferior y límite superior de riqueza).
   - Leer la lista de ingresos netos A de longitud N.
   - Leer el número de consultas Q.
2. Preprocesamiento:
   - Calcular el arreglo S que almacena la suma acumulada de los ingresos netos hasta cada mes.
   - Esto nos permitirá calcular rápidamente la suma de ingresos netos en cualquier intervalo [B, E].
3. Procesar las consultas:
   - Para cada consulta:
      1. Leer los valores de B, E, y X (mes de inicio, mes de fin, y riqueza inicial).
      2. Calcular la suma de ingresos netos del período [B, E] usando el arreglo de suma acumulada S.
      3. Determinar la riqueza final sumando la riqueza inicial X y la suma de ingresos netos calculada.
      4. Ajustar la riqueza final:
         - Si la riqueza es mayor que el límite superior U, ajustar la riqueza final a U.
         - Si la riqueza es menor que el límite inferior L, ajustar la riqueza final a L.
      5. Almacenar el resultado para esta consulta.
4. Salida:
   - Imprimir los resultados para todas las consultas.

```pseudo
INICIO

    // Leer N, L, U
    LEER N, L, U

    // Leer la lista de ingresos netos A
    LEER LISTA A DE LONGITUD N

    // Leer el número de consultas Q
    LEER Q

    // Preprocesamiento: Calcular suma acumulada S
    CREAR ARREGLO S DE TAMAÑO N + 1
    S[0] = 0
    PARA i DESDE 1 HASTA N HACER
        S[i] = S[i - 1] + A[i - 1]
    FIN PARA

    // Procesar cada consulta
    CREAR LISTA resultados VACÍA
    PARA i DESDE 1 HASTA Q HACER
        LEER B, E, X

        // Calcular la suma de ingresos netos desde el mes B hasta el mes E
        suma_ingresos = S[E] - S[B - 1]

        // Calcular la riqueza final
        riqueza_final = X + suma_ingresos

        // Ajustar la riqueza final según los límites L y U
        SI riqueza_final > U ENTONCES
            riqueza_final = U
        FIN SI
        SI riqueza_final < L ENTONCES
            riqueza_final = L
        FIN SI

        // Guardar el resultado
        AÑADIR riqueza_final A resultados
    FIN PARA

    // Imprimir los resultados
    PARA cada resultado EN resultados HACER
        IMPRIMIR resultado
    FIN PARA

FIN
```

### Explicación del Pseudocódigo

1. Lectura de Entrada:
   - Se leen los valores N, L, y U, que son el número de meses y los límites de riqueza.
   - Se lee la lista de ingresos netos A de longitud N.
   - Se lee el número de consultas Q.
2. Preprocesamiento (Suma Acumulada):
   - Se crea un arreglo S para almacenar las sumas acumuladas de los ingresos netos. Esto permite calcular la suma de ingresos en cualquier intervalo [B, E] de manera eficiente.
   - Se inicializa S[0] a 0, y luego se calcula S[i] como la suma acumulada hasta el mes i.
3. Procesamiento de Consultas:
   - Se itera sobre cada consulta y se leen los valores B, E, y X que representan el mes de inicio, el mes de fin, y la riqueza inicial.
   - Se calcula la suma de ingresos en el intervalo [B, E] restando S[B-1] de S[E].
   - Se suma esta cantidad a la riqueza inicial X para obtener la riqueza final.
   - Se ajusta la riqueza final si excede el límite superior U o si está por debajo del límite inferior L.
   - El resultado se almacena en la lista resultados.
4. Salida:
   - Finalmente, se imprimen todos los resultados de las consultas.

### Notas Finales

- El uso del arreglo de sumas acumuladas permite que las consultas sobre intervalos se resuelvan en tiempo constante, haciendo que el algoritmo sea eficiente.
- Este pseudocódigo es adecuado para manejar las restricciones del problema, con un enfoque en mantener la complejidad del algoritmo dentro de los límites aceptables (O(N + Q)).
- Asegúrate de que la implementación considere las restricciones de los valores para evitar errores de desbordamiento o cálculos incorrectos.
