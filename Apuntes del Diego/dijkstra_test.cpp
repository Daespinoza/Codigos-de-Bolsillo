#include <iostream>
#include <vector>
#include <queue>
#include <chrono>  // Para medir el tiempo
#include <utility>
using namespace std;

#define INF 1e9  // Un número grande que representa "infinito"
#define MAX_V 250001  // Máximo número de nodos en el grafo
typedef pair<int, int> ii;  // Definimos 'ii' como una pareja (peso, nodo)
#define pb push_back  // Abreviación para push_back en vectores

vector<ii> G[MAX_V];  // Grafo representado como lista de adyacencia
int N;  // Número de nodos en el grafo

// Macro para añadir una arista entre dos nodos 'a' y 'b' con un peso 'w'
#define add(a, b, w) G[a].pb(make_pair(w, b))

// Función que implementa el algoritmo de Dijkstra
long long dijkstra(int s, int t, vector<int>& dad) {  // s es el nodo origen y t es el nodo destino
    priority_queue<ii, vector<ii>, greater<ii>> Q;  // Cola de prioridad para el algoritmo
    vector<long long> dist(N, INF);  // Vector de distancias inicializadas a infinito
    dad.assign(N, -1);  // Reinicializamos el vector de predecesores
    Q.push(make_pair(0, s));  // Insertamos el nodo origen 's' en la cola con distancia 0
    dist[s] = 0;  // La distancia de 's' a sí mismo es 0
    
    while (!Q.empty()) {  // Mientras la cola no esté vacía
        ii p = Q.top(); Q.pop();  // Tomamos el nodo con la menor distancia
        if (p.second == t) break;  // Si hemos llegado al nodo destino, terminamos
        
        for (auto it : G[p.second]) {  // Recorremos todos los vecinos del nodo actual
            if (dist[p.second] + it.first < dist[it.second]) {  // Si encontramos un camino más corto
                dist[it.second] = dist[p.second] + it.first;  // Actualizamos la distancia al vecino
                dad[it.second] = p.second;  // Actualizamos el predecesor del vecino
                Q.push(make_pair(dist[it.second], it.second));  // Insertamos el vecino en la cola
            }
        }
    }
    
    // Si se encontró un camino válido hacia 't', devolvemos la distancia mínima
    return dist[t];
}

// Función para generar el camino desde 's' hasta 't'
void printPath(int s, int t, const vector<int>& dad) {
    if (dad[t] == -1) {
        cout << "No hay camino desde " << s << " hasta " << t << endl;
        return;
    }
    
    vector<int> path;
    for (int i = t; i != -1; i = dad[i])
        path.push_back(i);
    
    // Imprimimos el camino en orden
    for (int i = path.size() - 1; i >= 0; i--)
        cout << path[i] << (i == 0 ? "\n" : " -> ");
}

int main() {
    // Inicializamos el número de nodos y aristas
    N = 25;  // Por ejemplo, 6 nodos
    int E = 48;  // 9 aristas
    
    // Grafo de 25 nodos con varias aristas (u, v, w) donde u y v son nodos conectados y w es el peso
    add(0, 1, 2);  add(0, 2, 4);  add(0, 3, 1);
    add(1, 4, 7);  add(1, 5, 3);  add(2, 6, 6);
    add(2, 7, 5);  add(3, 8, 4);  add(3, 9, 8);
    add(4, 10, 2); add(5, 11, 9); add(6, 12, 7);
    add(7, 13, 1); add(8, 14, 3); add(9, 15, 6);
    add(10, 16, 4); add(11, 17, 5); add(12, 18, 3);
    add(13, 19, 8); add(14, 20, 2); add(15, 21, 7);
    add(16, 22, 6); add(17, 23, 9); add(18, 24, 4);

    add(1, 0, 2);  add(2, 0, 4);  add(3, 0, 1);
    add(4, 1, 7);  add(5, 1, 3);  add(6, 2, 6);
    add(7, 2, 5);  add(8, 3, 4);  add(9, 3, 8);
    add(10, 4, 2); add(11, 5, 9); add(12, 6, 7);
    add(13, 7, 1); add(14, 8, 3); add(15, 9, 6);
    add(16, 10, 4); add(17, 11, 5); add(18, 12, 3);
    add(19, 13, 8); add(20, 14, 2); add(21, 15, 7);
    add(22, 16, 6); add(23, 17, 9); add(24, 18, 4);

    int origen = 0, destino = 24;  // Queremos encontrar el camino de 0 a 24

    // Creamos el vector de predecesores
    vector<int> dad(N, -1);
    
    // Medimos el tiempo de ejecución de Dijkstra
    auto start = chrono::high_resolution_clock::now();
    long long distancia = dijkstra(origen, destino, dad);
    
    // Mostramos la distancia mínima encontrada
    if (distancia >= INF) {
        cout << "No hay camino disponible desde " << origen << " hasta " << destino << endl;
    } else {
        cout << "La distancia minima desde " << origen << " hasta " << destino << " es: " << distancia << endl;
    }

    

    // Imprimimos el camino mínimo (si existe)
    printPath(origen, destino, dad);

    auto end = chrono::high_resolution_clock::now();
    auto tiempo_microsegundos = chrono::duration_cast<chrono::microseconds>(end - start).count();  // Tiempo en microsegundos

    // Imprimimos el tiempo de ejecución
    cout << "Tiempo de ejecucion: " << tiempo_microsegundos << " microsegundos" << endl;    

    return 0;
}
