#include <iostream>
#include <algorithm> // Para std::min
#include <cmath> // Para __builtin_clz
#include <cstdlib>   // Para rand()
#include <ctime>     // Para time()
#include <chrono>    // Para medir tiempo

struct RMQ {
    #define LVL 10
    using tipo = int; // Define el tipo de los elementos, puedes cambiarlo si lo deseas
    tipo vec[LVL][1 << (LVL + 1)]; // Matriz para almacenar los valores mínimos de cada nivel
    int n; // Tamaño del arreglo original

    // Función para construir la tabla RMQ
    void build(const tipo arr[], int size) {
        n = size;
        for (int i = 0; i < n; i++) {
            vec[0][i] = arr[i]; // Inicializa el nivel 0 con los valores originales del arreglo
        }
        int maxP = 31 - __builtin_clz(n); // Calcula el número máximo de niveles
        for (int p = 0; p < maxP; ++p) {
            for (int x = 0; x + (1 << p) < n; ++x) {
                vec[p + 1][x] = std::min(vec[p][x], vec[p][x + (1 << p)]); // Llena los niveles superiores
            }
        }
    }

    // Función para realizar consultas de mínimo en el rango [i, j)
    tipo query(int i, int j) {
        int p = 31 - __builtin_clz(j - i); // Calcula el logaritmo en base 2 del tamaño del intervalo
        return std::min(vec[p][i], vec[p][j - (1 << p)]); // Retorna el mínimo entre dos segmentos
    }
};

int main() {
    // Inicialización de números aleatorios
    std::srand(static_cast<unsigned>(std::time(0))); // Semilla para números aleatorios

    // Crear un arreglo de 1000 números aleatorios entre 1 y 100
    const int SIZE = 1000;
    int arr[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = std::rand() % 10000 + 1; // Números entre 1 y 100
    }

    // Crear objeto RMQ y construir la tabla
    RMQ rmq;
    rmq.build(arr, SIZE);

    // Inicia el temporizador total
    auto totalStart = std::chrono::high_resolution_clock::now();

    // Realizamos varias consultas de rango [i, j)
    const int queries[][2] = {
        {0, 100}, {50, 150}, {100, 200}, {200, 300}, {300, 500}, 
        {400, 600}, {600, 800}, {550, 720}, {800, 1000}
    };
    const int numQueries = sizeof(queries) / sizeof(queries[0]);

    // Realizamos las consultas e imprimimos los resultados
    for (int q = 0; q < numQueries; ++q) {
        int minValue = rmq.query(queries[q][0], queries[q][1]);
        std::cout << "Minimo en el rango [" << queries[q][0] << ", " << queries[q][1] << "]: " 
                  << minValue << std::endl;
    }

    // Detiene el temporizador y calcula la duración total
    auto totalEnd = std::chrono::high_resolution_clock::now();
    double totalDuration = std::chrono::duration<double, std::micro>(totalEnd - totalStart).count(); // Duración total

    // Imprime el tiempo total
    std::cout << "Tiempo total de ejecucion: " << totalDuration << " microsegundos" << std::endl;

    return 0;
}