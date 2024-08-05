# General Information

Unless otherwise stated, the following conditions hold for all problems.

## Program Name

1. Your solution must be called `codename.c`, `codename.cpp`, `codename.java`, `codename.kt`, `codename.py2` or `codename.py3` where `codename` is the capital letter which identifies the problem.

## Input

1. The input must be read from standard input.
2. The input consists of a single test case, which is described using a number of lines that depends on the problem. No extra data appear in the input.
3. When a line of data contains several values, they are separated by single spaces. No other spaces appear in the input. There are no empty lines.
4. The English alphabet is used. There are no letters with tildes, accents, diaereses or other diacritical marks.
5. Every line, including the last one, has the usual end-of-line mark.

## Output

1. The output must be written to standard output.
2. The result of the test case must appear in the output using a number of lines that depends on the problem. No extra data should appear in the output.
3. When a line of results contains several values, they must be separated by single spaces. No other spaces should appear in the output. There should be no empty lines.
4. The English alphabet must be used. There should be no letters with tildes, accents, diaereses or other diacritical marks.
5. Every line, including the last one, must have the usual end-of-line mark.
6. To output real numbers, round them to the closest rational with the required number of digits after the decimal point. Test cases are such that there are no ties when rounding as specified.

# Problem A - Algorithm Teaching

The Latin American Beginners Regional Contest is coming, and the University of Byteland wants to prepare a team of newly-admitted students to compete. The university has N teachers that can instruct students in the topic of algorithms. Each candidate student must be trained by a single teacher, in a non-empty subset of algorithms that the teacher knows. For example, if a given teacher knows the two algorithms PRIM and KRUSKAL, then the teacher can train a student just on PRIM, just on KRUSKAL, or on both PRIM and KRUSKAL. As you can see, in this case there are three different options for this particular teacher to train a student. In general, a given teacher that knows A different algorithms can train a student in 2**A - 1 different ways. All these 2**A - 1 options can be carried out, because the university has a lot of new students, and there is no limit on the number of students a teacher can train.

The university would like to form a team having as many students as possible. However, each pair of students in the final team must be able to cooperate, which means that each one of them must have been trained on an algorithm that the other hasn't. For example, a student trained on BFS and DFS can cooperate with another student trained on DFS and DIJKSTRA, because the first student is trained on BFS while the second isn't, and the second student is trained on DIJKSTRA while the first student isn't. On the other hand, a student trained on BFS and DFS cannot cooperate with another student trained just on BFS, or just on DFS, or on both BFS and DFS, among others.

Given the set of algorithms that each teacher knows, you must determine the maximum number of students in a team in which every student can cooperate with each other. Recall that each student must be trained by a single teacher, while each teacher can train as many students as needed. For example, if there is just one teacher who knows the algorithms DFS, BFS and DIJKSTRA, it is possible to prepare a team with up to three students: a first student trained on DFS and BFS, a second student trained on DFS and DIJKSTRA, and a third student trained on BFS and DIJKSTRA.

## Input

The first line contains an integer N (1 <= N <= 100) indicating the number of teachers. Each of the next N lines describes a teacher with an integer A (1 <= A <= 10) representing the number of algorithms the teacher knows, followed by A different non-empty strings of at most 10 uppercase letters each, indicating the names of the algorithms that teacher knows.

## Output

Output a single line with an integer indicating the maximum number of students in a team in which every student can cooperate with each other.

### Sample Input 1
1
3 DFS BFS DIJKSTRA

### Sample Output 1
3

### Sample Input 2
2
4 BFS DFS LCA RMQ
2 PRIM KRUSKAL

### Sample Output 2
8

### Sample Input 3
4``
3 BFS DFS DIJKSTRA``
4 BFS DFS LCA RMQ
3 DIJKSTRA BFT DFS
3 FLOYD DFS BFS

### Sample Output 3
10

### Sample Input 4
1
1 HAVEFUN

### Sample Output 4
1

### Sample Input 5
3
4 FFEK DANTZING DEMOUCRON FFT
4 PRIM KRUSKAL LCA FLOYD
4 DFS BFS DIJKSTRA RMQ

### Sample Output 5
18
