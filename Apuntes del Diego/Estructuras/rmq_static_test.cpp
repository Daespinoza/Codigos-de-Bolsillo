#include <iostream>
#include <algorithm> // Para std::min
#include <cmath>     // Para __builtin_clz
#include <cstdlib>   // Para rand()
#include <ctime>     // Para time()
#include <chrono>    // Para medir tiempo

#define forn(i, n) for (int i = 0; i < (n); ++i)

struct RMQ {
    #define LVL 10
    using tipo = int;
    tipo vec[LVL][1 << (LVL + 1)];

    tipo &operator[](int p) { return vec[0][p]; }

    void build(int n) {
        int mp = 31 - __builtin_clz(n);
        forn(p, mp) forn(x, n - (1 << p))
            vec[p + 1][x] = std::min(vec[p][x], vec[p][x + (1 << p)]);
    }

    tipo get(int i, int j) { // intervalo [i, j)
        int p = 31 - __builtin_clz(j - i);
        return std::min(vec[p][i], vec[p][j - (1 << p)]);
    }
};

int main() {
    std::srand(static_cast<unsigned>(std::time(0)));

    const int SIZE = 1000;
    int arr[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        arr[i] = std::rand() % 10000 + 1;
    }

    RMQ rmq;
    for (int i = 0; i < SIZE; ++i) {
        rmq[i] = arr[i];
    }
    rmq.build(SIZE);

    auto totalStart = std::chrono::high_resolution_clock::now();

    const int queries[][2] = {
        {0, 100}, {50, 150}, {100, 200}, {200, 300}, {300, 500}, 
        {400, 600}, {600, 800}, {550, 720}, {800, 1000}
    };
    const int numQueries = sizeof(queries) / sizeof(queries[0]);

    for (int q = 0; q < numQueries; ++q) {
        int minValue = rmq.get(queries[q][0], queries[q][1]);
        std::cout << "Minimo en el rango [" << queries[q][0] << ", " << queries[q][1] << "]: " 
                  << minValue << std::endl;
    }

    auto totalEnd = std::chrono::high_resolution_clock::now();
    double totalDuration = std::chrono::duration<double, std::micro>(totalEnd - totalStart).count();

    std::cout << "Tiempo total de ejecucion: " << totalDuration << " microsegundos" << std::endl;

    return 0;
}
