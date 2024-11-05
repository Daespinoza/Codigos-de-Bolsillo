#include <iostream>
#include <algorithm>
#include <ctime>
using namespace std;

#define MAXN 100000
#define operacion(x, y) max(x, y)  // Operación de máximo en el rango
// macros
#define forn(i, n) for(int i = 0; i < n; ++i) 
#define dforn(i, n) for (int i = n - 1; i >= 0; --i)

const int neutro = 0;              // Valor neutro para la operación de máximo

typedef int tipo;  // Define el tipo de datos para el arreglo

struct RMQ {
    int sz;              // Tamaño del segmento
    tipo t[4 * MAXN];    // Árbol segmentado

    // Permite acceso directo a un índice en el segmento original
    tipo &operator[](int p) { return t[sz + p]; }

    // Inicializa el RMQ con el tamaño adecuado para cubrir n elementos
    void init(int n) {  // O(n log n)
        sz = 1 << (32 - __builtin_clz(n - 1));  // Ajusta tamaño a la potencia de 2 más cercana
        forn(i, 2*sz) t[i] = neutro;
    }

    // Construye el árbol en O(n) tras haber inicializado los valores
    void updall() {  // O(n)
        dforn(i, sz) t[i]=operacion(t[2*i], t[2*i+1]);}

    // Obtiene el máximo en el rango [i, j)
    tipo get(int i, int j) { return get(i, j, 1, 0, sz); }

    // Función recursiva para consultar el máximo en el rango [i, j)
    tipo get(int i, int j, int n, int a, int b) {  // O(log n)
        if (j <= a || i >= b) return neutro;   // Caso fuera de rango
        if (i <= a && b <= j) return t[n];     // Caso completamente dentro del rango
        int c = (a + b) / 2;
        return operacion(get(i, j, 2 * n, a, c), get(i, j, 2 * n + 1, c, b));
    }

    // Actualiza el valor en la posición p con el valor val
    void set(int p, tipo val) {  // O(log n)
        for(p+=sz; p>0 && t[p]!=val;){
            t[p]=val; 
            p/=2;
            val=operacion(t[p*2], t[p*2+1]);
        }
    }
} rmq;

int main() {
    srand(time(0));  // Inicializa la semilla aleatoria
    
    int n = 10;  // Tamaño del arreglo (puedes cambiar este valor)
    cout << "Generando arreglo aleatorio de largo " << n << "...\n";

    // Inicializa el RMQ con `n` elementos
    rmq.init(n);

    // Genera aleatoriamente los elementos del arreglo y los coloca en el RMQ
    for (int i = 0; i < n; ++i) {
        rmq[i] = rand() % 100;  // Valores aleatorios entre 0 y 99
    }
    
    // Construye el árbol de segmentos completo
    rmq.updall();

    // Muestra el arreglo generado
    cout << "Arreglo generado:\n";
    for (int i = 0; i < n; ++i) {
        cout << rmq[i] << " ";
    }
    cout << endl;

    // Realiza varias consultas y muestra los resultados
    int num_queries = 5;
    cout << "\nRealizando " << num_queries << " consultas aleatorias de rango:\n";
    for (int i = 0; i < num_queries; ++i) {
        int l = rand() % (n / 2);  // `l` aleatorio en la primera mitad
        int r = n / 2 + (rand() % (n - n / 2));  // `r` aleatorio en la segunda mitad
        cout << "Rango [" << l << ", " << r << "]: Maximo = " << rmq.get(l, r) << endl;
    }

    // Realiza varias actualizaciones y muestra el estado después de cada una
    int num_updates = 3;
    cout << "\nRealizando " << num_updates << " actualizaciones aleatorias:\n";
    for (int i = 0; i < num_updates; ++i) {
        int pos = rand() % n;
        int new_val = rand() % 100;  // Nuevo valor aleatorio entre 0 y 99
        cout << "Actualizando posicion " << pos << " a " << new_val << endl;
        rmq.set(pos, new_val);

        // Realiza una consulta después de cada actualización
        int l = rand() % (n / 2);
        int r = n / 2 + (rand() % (n - n / 2));
        cout << "Rango [" << l << ", " << r << "] despues de la actualizacion: Maximo = " << rmq.get(l, r) << endl;
    }

    // Muestra el arreglo actualizado
    cout << "Arreglo actualizado:\n";
    for (int i = 0; i < n; ++i) {
        cout << rmq[i] << " ";
    }
    cout << endl;

    return 0;
}
