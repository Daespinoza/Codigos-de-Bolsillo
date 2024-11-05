#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <utility> // para std::pair

// Definición del struct Hash adaptado para std::pair<std::string, std::string>
struct Hash {
    // Hash para std::pair<std::string, std::string>
    size_t operator()(const std::pair<std::string, std::string>& a) const {
        size_t s = std::hash<std::string>()(a.first);
        return std::hash<std::string>()(a.second) + 0x9e3779b9 + (s << 6) + (s >> 2);
    }
};

int main() {
    // Uso de unordered_set con std::pair<std::string, std::string> y hash personalizado
    std::unordered_set<std::pair<std::string, std::string>, Hash> name_pair_set;
    name_pair_set.insert({"John", "Smith"});
    name_pair_set.insert({"Sara", "Lee"});

    // Verificar si un par de nombres existe
    if (name_pair_set.find({"John", "Smith"}) != name_pair_set.end()) {
        std::cout << "El par de nombres (John, Smith) esta en el conjunto" << std::endl;
    }

    if (name_pair_set.find({"Sara", "Lee"}) != name_pair_set.end()) {
        std::cout << "El par de nombres (Sara, Lee) esta en el conjunto" << std::endl;
    }

    // Buscar un par de nombres que no existe
    if (name_pair_set.find({"Mike", "Johnson"}) == name_pair_set.end()) {
        std::cout << "El par de nombres (Mike, Johnson) NO esta en el conjunto" << std::endl;
    }

    if (name_pair_set.find({"Alice", "Brown"}) == name_pair_set.end()) {
        std::cout << "El par de nombres (Alice, Brown) NO esta en el conjunto" << std::endl;
    }

    // Uso de unordered_map con std::pair<std::string, std::string> como clave
    std::unordered_map<std::pair<std::string, std::string>, int, Hash> name_pair_map;
    name_pair_map[{"John", "Smith"}] = 1;
    name_pair_map[{"Sara", "Lee"}] = 2;

    std::cout << "El valor para el par de nombres (John, Smith) es: " << name_pair_map[{"John", "Smith"}] << std::endl;
    std::cout << "El valor para el par de nombres (Sara, Lee) es: " << name_pair_map[{"Sara", "Lee"}] << std::endl;

    // Buscar un par de nombres que no existe en el mapa
    if (name_pair_map.find({"Mike", "Johnson"}) == name_pair_map.end()) {
        std::cout << "El par de nombres (Mike, Johnson) NO esta en el mapa" << std::endl;
    }

    if (name_pair_map.find({"Alice", "Brown"}) == name_pair_map.end()) {
        std::cout << "El par de nombres (Alice, Brown) NO esta en el mapa" << std::endl;
    }

    return 0;
}
