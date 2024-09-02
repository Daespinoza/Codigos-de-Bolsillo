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
