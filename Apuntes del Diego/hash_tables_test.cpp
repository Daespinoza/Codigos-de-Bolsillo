#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
#include <utility> // for std::pair

// Definición del struct Hash
struct Hash {
    // Hash para std::pair<int, int>
    size_t operator()(const std::pair<int, int>& a) const {
        size_t s = std::hash<int>()(a.first);
        return std::hash<int>()(a.second) + 0x9e3779b9 + (s << 6) + (s >> 2);
    }

    // Hash para std::vector<int>
    size_t operator()(const std::vector<int>& v) const {
        size_t s = 0;
        for (auto& e : v) {
            s ^= std::hash<int>()(e) + 0x9e3779b9 + (s << 6) + (s >> 2);
        }
        return s;
    }
};

int main() {
    // Uso de unordered_set con std::pair<int, int> y hash personalizado
    std::unordered_set<std::pair<int, int>, Hash> pair_set;
    pair_set.insert({1, 2});
    pair_set.insert({3, 4});
    pair_set.insert({5, 6});
    pair_set.insert({10, 20});

    // Verificar si un par existe
    if (pair_set.find({1, 2}) != pair_set.end()) {
        std::cout << "El par (1, 2) esta en el conjunto" << std::endl;
    }
    if (pair_set.find({3, 4}) != pair_set.end()) {
        std::cout << "El par (3, 4) esta en el conjunto" << std::endl;
    }

    // Buscar un par que no existe
    if (pair_set.find({7, 8}) == pair_set.end()) {
        std::cout << "El par (7, 8) NO esta en el conjunto" << std::endl;
    }
    if (pair_set.find({10, 21}) == pair_set.end()) {
        std::cout << "El par (10, 21) NO esta en el conjunto" << std::endl;
    }

    // Uso de unordered_map con std::pair<int, int> como clave y hash personalizado
    std::unordered_map<std::pair<int, int>, int, Hash> pair_map;
    pair_map[{1, 2}] = 10;
    pair_map[{3, 4}] = 20;
    pair_map[{5, 6}] = 30;

    std::cout << "El valor para el par (1, 2) es: " << pair_map[{1, 2}] << std::endl;
    std::cout << "El valor para el par (3, 4) es: " << pair_map[{3, 4}] << std::endl;

    // Buscar un par que no existe en el mapa
    if (pair_map.find({10, 21}) == pair_map.end()) {
        std::cout << "El par (10, 21) NO esta en el mapa" << std::endl;
    }

    // Uso de unordered_set con std::vector<int> y hash personalizado
    std::unordered_set<std::vector<int>, Hash> vector_set;
    vector_set.insert({1, 2, 3, 4, 5, 6});
    vector_set.insert({10, 20, 30, 40, 50});
    vector_set.insert({100, 200, 300});

    // Verificar si un vector existe
    if (vector_set.find({1, 2, 3, 4, 5, 6}) != vector_set.end()) {
        std::cout << "El vector {1, 2, 3, 4, 5, 6} esta en el conjunto" << std::endl;
    }
    if (vector_set.find({10, 20, 30, 40, 50}) != vector_set.end()) {
        std::cout << "El vector {10, 20, 30, 40, 50} esta en el conjunto" << std::endl;
    }

    // Buscar un vector que no existe
    if (vector_set.find({7, 8, 9}) == vector_set.end()) {
        std::cout << "El vector {7, 8, 9} NO esta en el conjunto" << std::endl;
    }
    if (vector_set.find({100, 200, 301}) == vector_set.end()) {
        std::cout << "El vector {100, 200, 301} NO esta en el conjunto" << std::endl;
    }

    return 0;
}
