#include <iostream>
#include <set>
#include <chrono> // Para medir tiempo

// Define un tipo para intervalos, usando un par
using ii = std::pair<int, int>;

bool operator< (const ii &a, const ii &b) {
    return a.first < b.first; // Compara por el primer elemento
}

// Estructura para manejar intervalos disjuntos
struct disjoint_intervals {
    std::set<ii> segs; // Conjunto para almacenar los intervalos

    void insert(ii v) { // O(log n)
        if (v.second - v.first == 0) return; // Si el intervalo es nulo, no se inserta

        auto it = segs.lower_bound(v); // Encuentra el lugar para insertar
        auto at = it;

        // Verifica si hay superposición con el intervalo anterior
        if (at != segs.begin() && (--at)->second >= v.first) {
            v.first = at->first; // Unir intervalos
            --it;
        }

        // Eliminar todos los intervalos que se superponen
        for (; it != segs.end() && it->first <= v.second; segs.erase(it++)) {
            v.second = std::max(v.second, it->second);
        }

        segs.insert(v); // Inserta el nuevo intervalo
    }

    void print_intervals() {
        for (const auto &seg : segs) {
            std::cout << "[" << seg.first << ", " << seg.second << "] ";
        }
        std::cout << std::endl;
    }
};

int main() {
    disjoint_intervals di;

    // Inicia el temporizador total
    auto totalStart = std::chrono::high_resolution_clock::now();

    // Ejemplo de inserción de intervalos
    di.insert({1, 3});
    di.insert({2, 5});
    di.insert({6, 9});
    di.insert({8, 10});
    di.insert({15, 18});
    di.insert({17, 20});

    // Imprimir los intervalos disjuntos resultantes
    std::cout << "Intervalos disjuntos resultantes: ";
    di.print_intervals();

    // Detiene el temporizador y calcula la duración total
    auto totalEnd = std::chrono::high_resolution_clock::now();
    double totalDuration = std::chrono::duration<double, std::micro>(totalEnd - totalStart).count(); // Duración total

    // Imprime el tiempo total
    std::cout << "Tiempo total de ejecucion: " << totalDuration << " microsegundos" << std::endl;

    return 0;
}
