#include <iostream>
#include <map>
#include <chrono>

using namespace std;

struct state {
    int len, link;
    map<char, int> next;
    state() {}
};

const int MAXLEN = 10010;
state st[MAXLEN * 2];  // Cada estado del autómata de sufijos
int sz, last;  // `sz`: número de estados creados, `last`: último estado añadido

// Inicializa el autómata
void sa_init() {
    for (int i = 0; i < sz; i++) {
        st[i].next.clear();
    }
    sz = last = 0;
    st[0].len = 0;
    st[0].link = -1;
    ++sz;  // El primer estado es el estado vacío
}

// Extiende el automaton con un carácter
void sa_extend(char c) {
    int cur = sz++;
    st[cur].len = st[last].len + 1;  // La longitud del nuevo estado es una más que el anterior
    int p;
    for (p = last; p != -1 && !st[p].next.count(c); p = st[p].link) {
        st[p].next[c] = cur;  // Agregamos la transición
    }
    if (p == -1) {
        st[cur].link = 0;  // Si no hay sufijo, conectamos con el estado inicial
    } else {
        int q = st[p].next[c];
        if (st[p].len + 1 == st[q].len) {
            st[cur].link = q;  // Si la longitud coincide, conectamos
        } else {
            int clone = sz++;
            st[clone].len = st[p].len + 1;
            st[clone].next = st[q].next;
            st[clone].link = st[q].link;
            for (; p != -1 && st[p].next.count(c) && st[p].next[c] == q; p = st[p].link) {
                st[p].next[c] = clone;
            }
            st[q].link = st[cur].link = clone;  // Enlace del nuevo estado y del clonado
        }
    }
    last = cur;  // Actualizamos el último estado
}

// Función para construir el automaton de sufijos a partir de una cadena
void build_suffix_automaton(string s) {
    sa_init();
    for (char c : s) {
        sa_extend(c);  // Añadimos cada carácter de la cadena
    }
}

// Función para medir el tiempo de construcción
void test_suffix_automaton(string s) {
    auto start = chrono::high_resolution_clock::now();
    build_suffix_automaton(s);
    auto end = chrono::high_resolution_clock::now();
    
    chrono::duration<double> tiempo = end - start;
    cout << "Tiempo de ejecucion: " << tiempo.count() << " segundos" << endl;
}

// Función main para ejecutar el código
int main() {
    string s = "abacabadabacaba";  // Ejemplo de cadena de prueba
    cout << "Construyendo el Suffix Automaton para la cadena: " << s << endl;
    test_suffix_automaton(s);

    return 0;
}
