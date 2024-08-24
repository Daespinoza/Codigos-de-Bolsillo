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
4

3 BFS DFS DIJKSTRA

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

# Problem B - Build the Perfect House
 
 Alice and Bob are now 45 years old and have enjoyed a long five-years retirement maintaining their vegetable field. Going back and forth to the field from their house in the city has become a really exhausting task, so they decided to move to the field permanently. They currently have a perfect fence surrounding all the vegetable plants (it has minimum perimeter and area), but they will tear down the old fence and build a new perfect house to live in.
 So what is a perfect house? Well, you know, there are some requirements. The area of the house must be a square centered at the point of the field that has the most beautiful view. Besides, the house cannot be built over any vagetables, although vegetables are allowed rigth on the border of the house.
 Since Alice and love spacious rooms, your task is to the maximum perimeter a perfect house can have.
 
 ## Input
 The first line contains an integer N ( 1 <= N <= 10**4) indicating the number of vegetable plants in Alice and Bob`s field. Vegetable plants are represented as points in the two dimensional plane, being (0,0) the point of the field that has most beautiful view. Each of the next N lines describes a vegetable plant with two integer X and Y (-10**9 <= X, Y <= 10**9) indicating the coordinates of the plant. No two vegetable plants have the same location and none of them is at point (0,0).
 
## Output
 Output a single line with a number indicating the maximum perimeter a perfect house can have. The result must be output as a rational number with exactly four digits after the decimal point, rounded if necessary. Notice that the sides of the house don`t need to be aligned with the coordinate axes.
 
 ### Sample input 1
 1
 
 0 1
 
 ### Sample output 1
 8.0000
 
 ### Sample input 2
 2
 
 10 4
 
 -5 -8
 
 ### Sample output 2
 74.9634
 
# Ploblem C - Cut Inequality Down
 
 Complejidonia has not always been the peaceful and egalitarian land we all know today. The wealthy Constantones were the owners of the local media and plunged Complejidonia into the tyranny of their ruthless economic system: Nlogonialism, a system that promoted extreme unfairness which, strangely enough, always benefited the Constantones.
 While the Constantones owned most of the wealth, Cuadradones lived in extreme poverty, and inequality was justified by tagging Cuadradones as lazy and inefficient. The Nlogones would usually look down on Cuadradones, despite working as much as they did, believing they were better off thanks to their mix of hard work and cunning. For the Cubiones and Cuaterniones it was even worse, coming form neighboring countries they were seen as criminals and, at same time, accused of stealing Complejidonia jobs.
 Everything changed after the International Collectivist and Popular Congress (ICPC) managed to overthrown the Constantones and put a new economic system in place, a system which strives for fairness and takes into account that each inhabitant might go through good and bad economic periods in life.
 In the new system an upper limit U on how much wealth an individual can accumulate and a lower bound L representing the minimum wealth required in order for an individual to keep a decent lifestyle were established. At the end of each month every inhabitant will evaluate their wealth. Those with more that U will donate what they own above the upper limit to the ICPC while the one who sadly have less than L will receive enough from ICPC to reach the established lower bound.
 The Cuadradones, which are very good farmers, need your help managing their finance. The long era of Nlogonialism has seriously harmed the environment and now the weather in Complejidonia is very volatile. This has a big impact on its agriculture that fluctuantes between good and bad periods.
 A farmer keeps a long record A1, A2, ..., An of their net income (income minus expenses) on a sequence of N months. Based on this data the farmer wants to plan how to invest their wealth in order to avoid being a burden to the ICPC in the future. The farmer wants to be able to know, given an initial wealth X at the beginning of a month B, how much they would own at the end of a month E (considering that at the end of each month they might either donate or receive a donation to ensure their wealth is between L and U, inclusive)
 
## Input
 The first line contains three integers N (1 <= N <= 10**5), L and U (1 <= L <= U <= 2 * 10**6), indicating respectively the number of months for which the farmer has net income records, the wealth lower bound and the wealth upper bound. The second line contains N integers A1, A2, ..., An ( -10**6 for i = 1,2,...,N), where Ai is the net income on the i-th month. The third line contains an integer Q (1 <= Q <= 10**5) representing the number of scenarios the farmer is interested in. Each of the next Q lines describes a scenario with three integers B, E (1 <= B <= E <= N) and X (L <= X <= U), indicating that the farmer would like to know how much they would own at the end of month E if they start owning X at the beginning of month B, and each month j = B, B + 1, ..., E their net income Aj.
 
## Output
 Output Q lines, each line with an integer indicating how much the farmer would own at the end of the period descibed in the corresponding scenario.
 
### Sample input 1
 5 1 41
 
 -10 10 1 -1 -70
 
 10
 
 2 5 31
 
 2 4 30
 
 2 4 29
 
 2 4 28
 
 1 2 20
 
 1 2 10
 
 1 4 11
 
 1 4 10
 
 1 4 40
 
 1 4 41
 
### Sample output 1
 1
 
 40
 
 39
 
 38
 
 20
 
 11
 
 11
 
 11
 
 40
 
 40
 
 On the first scenario the farmer`s net incomes would be [10,1,-1,-70] and they start with a wealth of 31:
 - At the end of first month their wealth is 41. As 1 <= 41 <= 41 they won`t donate nor receive money.
 - At the end of second month their wealth is 42 > 41 they donate 1, ending the month with a wealth of 41.
 - At the end of thrid month their wealth is 40. As 1 <= 40 <= 41 once again they won`t donate nor receive money.
 - Finally, at the end of fourth month their wealth is -30. As -30 < 1 they receive a donation from the ICPC ending the month with a wealth of 1.
 
 Hence, on this scenario, the farmer ends up owning a wealth of 1.
