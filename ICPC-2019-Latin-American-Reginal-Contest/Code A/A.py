def max_cooperating_students(teachers):
    from itertools import combinations
    
    sets = []
    
    # Crear subconjuntos de algoritmos que cada profesor puede enseñar
    for teacher in teachers:
        algorithms = teacher[1:]
        A = len(algorithms)
        for i in range(1, 1 << A):
            subset = set()
            for j in range(A):
                if i & (1 << j):
                    subset.add(algorithms[j])
            sets.append(subset)
    
    max_students = 0
    # Encontrar el número máximo de estudiantes que pueden cooperar
    for combo in combinations(sets, len(sets)):
        all_pairs_cooperate = True
        for i in range(len(combo)):
            for j in range(i + 1, len(combo)):
                if not (combo[i] - combo[j] and combo[j] - combo[i]):
                    all_pairs_cooperate = False
                    break
            if not all_pairs_cooperate:
                break
        if all_pairs_cooperate:
            max_students = max(max_students, len(combo))
    
    return max_students

if __name__ == "__main__":
    import sys

    # Leer la entrada línea por línea
    data = []
    for line in sys.stdin:
        data.append(line.strip())

    # Imprimir la entrada completa leída
    print("Entrada completa leída:")
    print(data)

    N = int(data[0])
    print(f"Número de profesores (N): {N}")

    teachers = []

    for i in range(1, N + 1):
        line = data[i].split()
        A = int(line[0])
        algorithms = line[1:]
        teachers.append((A, *algorithms))
        
        # Imprimir el número de algoritmos y la lista de algoritmos para cada profesor
        print(f"Profesor {i}: A = {A}, Algoritmos = {algorithms}")

    # Imprimir la lista completa de profesores y algoritmos
    print("Lista de profesores y sus algoritmos:")
    print(teachers)
    
    # Finalmente, imprimir el resultado de la función
    resultado = max_cooperating_students(teachers)
    print(f"Máximo número de estudiantes que pueden cooperar: {resultado}")
