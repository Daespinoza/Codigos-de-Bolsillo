fun maxCooperatingStudents(teachers: List<List<String>>): Int {
    val sets = mutableListOf<Set<String>>()
    
    // Crear subconjuntos de algoritmos que cada profesor puede enseñar
    for (teacher in teachers) {
        val A = teacher.size
        for (i in 1 until (1 shl A)) {
            val subset = mutableSetOf<String>()
            for (j in 0 until A) {
                if ((i and (1 shl j)) != 0) {
                    subset.add(teacher[j])
                }
            }
            sets.add(subset)
        }
    }
    
    var maxStudents = 0
    // Encontrar el número máximo de estudiantes que pueden cooperar
    for (i in sets.indices) {
        var count = 1
        for (j in i + 1 until sets.size) {
            val cooperative = sets[i].none { it in sets[j] }
            if (cooperative) count++
        }
        maxStudents = maxOf(maxStudents, count)
    }
    
    return maxStudents
}

fun main() {
    val input = generateSequence(::readLine).toList()
    val N = input[0].toInt()
    val teachers = input.drop(1).map { it.split(" ").drop(1) }
    println(maxCooperatingStudents(teachers))
}
