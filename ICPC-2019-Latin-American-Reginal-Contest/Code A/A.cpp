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
