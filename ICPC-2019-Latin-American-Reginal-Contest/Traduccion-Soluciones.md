# Información General

A menos que se indique lo contrario, las siguientes condiciones se aplican a todos los problemas.

## Nombre del Programa

1. Tu solución debe llamarse `codename.c`, `codename.cpp`, `codename.java`, `codename.kt`, `codename.py2` o `codename.py3`, donde `codename` es la letra mayúscula que identifica el problema.

## Entrada

1. La entrada debe leerse de la entrada estándar.
2. La entrada consiste en un único caso de prueba, que se describe usando un número de líneas que depende del problema. No aparecerán datos adicionales en la entrada.
3. Cuando una línea de datos contiene varios valores, están separados por espacios simples. No aparecen otros espacios en la entrada. No hay líneas vacías.
4. Se utiliza el alfabeto inglés. No hay letras con tildes, acentos, diéresis u otros signos diacríticos.
5. Cada línea, incluida la última, tiene la marca de fin de línea habitual.

## Salida

1. La salida debe escribirse en la salida estándar.
2. El resultado del caso de prueba debe aparecer en la salida utilizando un número de líneas que depende del problema. No deben aparecer datos adicionales en la salida.
3. Cuando una línea de resultados contiene varios valores, deben estar separados por espacios simples. No deben aparecer otros espacios en la salida. No debe haber líneas vacías.
4. Se debe utilizar el alfabeto inglés. No debe haber letras con tildes, acentos, diéresis u otros signos diacríticos.
5. Cada línea, incluida la última, debe tener la marca de fin de línea habitual.
6. Para la salida de números reales, redondearlos al racional más cercano con el número requerido de dígitos después del punto decimal. Los casos de prueba son tales que no hay empates al redondear como se especifica.

# Problema A - Enseñanza de Algoritmos

El Concurso Regional para Principiantes de América Latina se acerca, y la Universidad de Byteland quiere preparar a un equipo de estudiantes recién admitidos para competir. La universidad cuenta con N profesores que pueden instruir a los estudiantes en el tema de algoritmos. Cada estudiante candidato debe ser entrenado por un solo profesor, en un subconjunto no vacío de algoritmos que el profesor conozca. Por ejemplo, si un profesor conoce los algoritmos **PRIM** y **KRUSKAL**, puede entrenar a un estudiante solo en **PRIM**, solo en **KRUSKAL** o en ambos algoritmos. Como puedes ver, en este caso hay tres opciones diferentes para que este profesor entrene a un estudiante. En general, un profesor que conoce A algoritmos distintos puede entrenar a un estudiante de $$2^A - 1$$ maneras diferentes. Todas estas $$2^A - 1$$ opciones son posibles porque la universidad cuenta con muchos nuevos estudiantes y no hay límite en la cantidad de estudiantes que un profesor puede entrenar.

La universidad desea formar un equipo con la mayor cantidad de estudiantes posible. Sin embargo, cada par de estudiantes del equipo final debe poder cooperar, lo que significa que cada uno de ellos debe haber sido entrenado en un algoritmo que el otro no conoce. Por ejemplo, un estudiante entrenado en **BFS** y **DFS** puede cooperar con otro estudiante entrenado en **DFS** y **DIJKSTRA**, ya que el primero conoce **BFS** y el segundo no, mientras que el segundo conoce **DIJKSTRA** y el primero no. Por otro lado, un estudiante entrenado en **BFS** y **DFS** no puede cooperar con otro estudiante entrenado solo en **BFS**, solo en **DFS** o en ambos **BFS** y **DFS**, entre otros.

Dado el conjunto de algoritmos que cada profesor conoce, debes determinar el máximo número de estudiantes en un equipo en el que cada estudiante pueda cooperar con los demás. Recuerda que cada estudiante debe ser entrenado por un único profesor, mientras que cada profesor puede entrenar a tantos estudiantes como sea necesario. Por ejemplo, si hay solo un profesor que conoce los algoritmos **DFS**, **BFS** y **DIJKSTRA**, es posible formar un equipo con hasta tres estudiantes: el primero entrenado en **DFS** y **BFS**, el segundo entrenado en **DFS** y **DIJKSTRA**, y el tercero entrenado en **BFS** y **DIJKSTRA**.

## Entrada

La primera línea contiene un entero N (1 ≤ N ≤ 100) que indica el número de profesores. Cada una de las siguientes N líneas describe a un profesor con un entero A (1 ≤ A ≤ 10) que representa la cantidad de algoritmos que el profesor conoce, seguido de A cadenas no vacías y diferentes, de como máximo 10 letras mayúsculas cada una, que indican los nombres de los algoritmos que el profesor conoce.

## Salida

Imprime una sola línea con un entero que indique el número máximo de estudiantes en un equipo en el que todos puedan cooperar entre sí.

## Casos de Prueba

<table>
  <thead>
    <tr>
      <th style="text-align: left; vertical-align: top;">Sample Input</th>
      <th style="text-align: left; vertical-align: top;">Sample Output</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align: left; vertical-align: top;">
        1<br>3 DFS BFS DIJKSTRA
      </td>
      <td style="text-align: left; vertical-align: top;"> <br> 3</td>
    </tr>
    <tr>
      <td style="text-align: left; vertical-align: top;">
         2<br>4 BFS DFS LCA RMQ<br>2 PRIM KRUSKAL
      </td>
      <td style="text-align: left; vertical-align: top;"> 8</td>
    </tr>
    <tr>
      <td style="text-align: left; vertical-align: top;">
        4<br>3 BFS DFS DIJKSTRA<br>4 BFS DFS LCA RMQ<br>3 DIJKSTRA BFT DFS<br>3 FLOYD DFS BFS
      </td>
      <td style="text-align: left; vertical-align: top;">10</td>
    </tr>
    <tr>
      <td style="text-align: left; vertical-align: top;">
       1<br>1 HAVEFUN
      </td>
      <td style="text-align: left; vertical-align: top;">1</td>
    </tr>
    <tr>
      <td style="text-align: left; vertical-align: top;">
        3<br>4 FFEK DANTZING DEMOUCRON FFT<br>4 PRIM KRUSKAL LCA FLOYD<br>4 DFS BFS DIJKSTRA RMQ
      </td>
      <td style="text-align: left; vertical-align: top;">18</td>
    </tr>
  </tbody>
</table>

## Explicación del Problema

El problema se centra en formar un equipo de estudiantes que pueda cooperar eficazmente en un concurso de algoritmos. Aquí está la idea explicada de forma sencilla:

1. Profesores y algoritmos:
    - Cada profesor conoce un conjunto de algoritmos.
    - Un profesor puede entrenar a un estudiante en cualquier combinación de los algoritmos que conoce. Por ejemplo, si conoce DFS y BFS, puede entrenar a un estudiante en:
      - Solo DFS.
      - Solo BFS.
      - Ambos, DFS y BFS.
2. Cooperación entre estudiantes:
    - Dos estudiantes pueden cooperar si tienen al menos un algoritmo que el otro no conoce. Por ejemplo:
      - Estudiante A conoce BFS y DFS.
      - Estudiante B conoce DFS y DIJKSTRA.
      - Pueden cooperar porque A conoce BFS y B no, mientras que B conoce DIJKSTRA y A no.
    - Sin embargo, no pueden cooperar si conocen exactamente los mismos algoritmos o si uno conoce solo algoritmos que ya conoce el otro.
3. Objetivo:
    - Determinar el número máximo de estudiantes que se pueden entrenar, de forma que todos en el equipo puedan cooperar entre sí.
    - Los estudiantes pueden ser entrenados por diferentes profesores, y cada profesor puede entrenar a varios estudiantes.
4. Restricciones:
    - Hay un máximo de 100 profesores.
    - Cada profesor puede conocer hasta 10 algoritmos diferentes.
    - El número total de combinaciones posibles que cada profesor puede generar está limitado por $$2^A - 1$$, donde A es la cantidad de algoritmos que el profesor conoce.
5. Ejemplo simple:
    - Si un profesor conoce DFS, BFS, y DIJKSTRA, puede entrenar hasta 7 combinaciones distintas de estudiantes. Estas combinaciones son:
      - DFS
      - BFS
      - DIJKSTRA
      - DFS + BFS
      - DFS + DIJKSTRA
      - BFS + DIJKSTRA
      - DFS + BFS + DIJKSTRA
    - Pero no todas las combinaciones pueden cooperar entre sí. Debemos seleccionar un subconjunto máximo de combinaciones donde todos los estudiantes puedan cooperar.

En resumen, el problema consiste en identificar el máximo número de estudiantes con diferentes combinaciones de algoritmos que puedan cooperar entre sí, usando los conocimientos de los profesores disponibles.

## Estrategia General
1. Generar combinaciones:
    - Para cada profesor, calcular todas las posibles combinaciones de algoritmos que puede entrenar a los estudiantes.
    - Representar cada combinación como un conjunto (por ejemplo, {DFS, BFS}).
2. Unificar combinaciones:
    - Combinar todas las combinaciones posibles de todos los profesores en un único conjunto global para eliminar duplicados.
3. Verificar cooperación:
    - Dos combinaciones cooperan si tienen al menos un algoritmo único que el otro no conoce. Es decir, si el conjunto de algoritmos de una combinación no es un subconjunto del otro.
4. Encontrar el conjunto máximo de combinaciones:
    - Usar una técnica de búsqueda como backtracking o un algoritmo de máxima independencia en grafos para encontrar el mayor subconjunto de combinaciones donde todas puedan cooperar.

## Pseudocódigo

```plaintext
1. Entrada:
   - Número de profesores N.
   - Para cada profesor, una lista de algoritmos que conoce.

2. Inicializar un conjunto vacío llamado "CombinacionesGlobales".

3. Para cada profesor:
     a. Obtener el conjunto de algoritmos que conoce.
     b. Generar todas las combinaciones posibles no vacías de esos algoritmos.
     c. Agregar cada combinación al conjunto "CombinacionesGlobales".

4. Convertir "CombinacionesGlobales" en una lista para poder iterar sobre ella.

5. Construir un grafo:
     a. Cada combinación es un nodo del grafo.
     b. Dos nodos están conectados si no pueden cooperar:
        - Verificar que cada combinación tenga al menos un algoritmo que la otra no conozca.

6. Resolver el problema de máximo conjunto independiente en el grafo:
     a. Usar una técnica como búsqueda exhaustiva (backtracking) o un algoritmo especializado.
     b. Encontrar el mayor grupo de nodos donde ninguno esté conectado.

7. Imprimir el tamaño del conjunto independiente máximo como resultado.
```

## Detalle de las Funciones
1. Generar combinaciones de algoritmos:
    - Dados los algoritmos de un profesor, generar todas las combinaciones posibles de 1 a A algoritmos.
    - Esto se puede hacer iterando sobre cada tamaño de combinación (1 a A) y creando subconjuntos.
2. Verificar si dos combinaciones pueden cooperar:
    - Dadas dos combinaciones, comprobar si ambas tienen al menos un algoritmo que la otra no conoce.
    - Esto asegura que los estudiantes entrenados en esas combinaciones puedan trabajar juntos.
3. Máximo conjunto independiente:
    - En el grafo, buscar el grupo más grande de nodos donde ninguno esté conectado.
    - Se puede implementar con búsqueda exhaustiva, técnicas de programación dinámica o algoritmos de teoría de grafos.

## Complejidad
- Generación de combinaciones: $$O (2^A * N)$$ donde A es el número máximo de algoritmos por profesor.
- Construcción del grafo: $$O (K^2)$$, donde K es el número total de combinaciones únicas.
- Máximo conjunto independiente: Puede ser exponencial en el peor caso, pero funciona bien para grafos pequeños o moderados.

Este enfoque debería ser suficiente para los límites dados (N ≤ 100, A ≤ 10).

# Problema B - Construye la Casa Perfecta

Alicia y Bob tienen ahora 45 años y han disfrutado de cinco años de jubilación manteniendo su campo de vegetales. Ir y venir del campo a su casa en la ciudad se ha vuelto una tarea agotadora, por lo que decidieron mudarse permanentemente al campo. Actualmente tienen una cerca perfecta que rodea todas las plantas de vegetales (con perímetro y área mínimos), pero derribarán la cerca vieja y construirán una nueva casa perfecta para vivir.

¿Qué es una casa perfecta? Bueno, debe cumplir con algunos requisitos. El área de la casa debe ser un cuadrado centrado en el punto del campo con la vista más hermosa. Además, la casa no puede construirse sobre ningún vegetal, aunque se permite que los vegetales estén justo en el borde de la casa.

Dado que a Alicia y Bob les encantan los espacios amplios, tu tarea es calcular el máximo perímetro que puede tener una casa perfecta.

## Entrada

La primera línea contiene un entero N (1 ≤ N ≤ $$10^4$$) que indica el número de plantas de vegetales en el campo de Alicia y Bob. Las plantas de vegetales se representan como puntos en un plano bidimensional, siendo (0,0) el punto del campo con la vista más hermosa. Cada una de las siguientes N líneas describe una planta de vegetales con dos enteros X y Y ($$-10^9$$ ≤ X, Y ≤ $$10^9$$) que indican las coordenadas de la planta. No hay dos plantas en la misma ubicación y ninguna está en el punto (0,0).

## Salida

Imprime una sola línea con un número que indique el máximo perímetro que puede tener una casa perfecta. El resultado debe mostrarse como un número racional con exactamente cuatro dígitos decimales, redondeado si es necesario. Nota que los lados de la casa no necesitan estar alineados con los ejes de coordenadas.

## Casos de Prueba

<table>
  <thead>
    <tr>
      <th style="text-align: left; vertical-align: top;">Sample Input</th>
      <th style="text-align: left; vertical-align: top; background-color: gray;">Sample Output</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align: left; vertical-align: top;">
        1<br>
        0 1
      </td>
      <td style="text-align: left; vertical-align: top;">8.0000</td>
    </tr>
    <tr>
      <td style="text-align: left; vertical-align: top;">
        2<br>
        10 4<br>
        -5 -8
      </td>
      <td style="text-align: left; vertical-align: top;">74.9634</td>
    </tr>
  </tbody>
</table>

## Explicación del Problema

El problema plantea la situación de Alicia y Bob, quienes desean construir una casa perfecta en su campo de vegetales. La casa debe cumplir con las siguientes condiciones:

1. Forma y ubicación de la casa:
    - La casa debe tener forma cuadrada y estar centrada en el punto (0,0), que es el lugar con la mejor vista en el campo.
2. Restricciones por los vegetales:
    - Ninguna parte de la casa puede ocupar el espacio donde hay vegetales. Es decir, los vértices y lados del cuadrado deben evitar las ubicaciones donde haya vegetales. Sin embargo, se permite que los vegetales estén justo en el borde de la casa.
3. Objetivo principal:
    - El objetivo es maximizar el perímetro de la casa, es decir, construir el cuadrado más grande posible que cumpla con las restricciones anteriores.
4. Coordenadas del problema:
    - Los vegetales se representan como puntos en un plano cartesiano, donde cada punto tiene coordenadas enteras (x,y). Estos puntos pueden estar dispersos en un rango muy amplio $$( -10^9 ≤ x ,y ≤ 10^9)$$.
5. Resultado esperado:
    - Se debe calcular y reportar el máximo perímetro de la casa como un número decimal con exactamente cuatro dígitos decimales.

En resumen, el problema combina conceptos de geometría y optimización: encontrar el cuadrado más grande que pueda construirse alrededor de un conjunto de restricciones espaciales.

## Estrategia General

Para resolver el problema de maximizar el perímetro de una casa cuadrada que cumpla las restricciones dadas, seguimos los siguientes pasos generales:

1. Entender la relación entre los vegetales y el cuadrado:
    - Un cuadrado centrado en (0,0) tiene lados de longitud 𝐿 y un perímetro de 4𝐿.
    - Para garantizar que la casa no interfiera con ningún vegetal, sus bordes deben evitar cualquier punto ocupado por vegetales.
    - Los vértices del cuadrado y las ubicaciones de los vegetales determinan qué tan grande puede ser el cuadrado.
2. Reformulación del problema:
    - Maximizar el perímetro es equivalente a maximizar la longitud del lado 𝐿 del cuadrado.
    - Esto implica encontrar el mayor cuadrado que pueda crecer en todas las direcciones sin cubrir ningún vegetal.
3. Uso de distancias:
    - Para garantizar que el cuadrado no ocupe el espacio de ningún vegetal, usamos la distancia euclidiana desde el centro (0,0) hasta cada vegetal para calcular las restricciones.
    - Los puntos más cercanos determinan el tamaño máximo del cuadrado. Específicamente, debemos verificar las distancias mínimas desde el origen a los bordes que podrían contener vegetales.
4. Propiedades geométricas:
    - Un cuadrado rotado en el plano tiene sus lados alineados a ángulos específicos respecto al origen. Esto significa que sus vértices están determinados por la orientación y la distancia máxima que podemos usar para un lado.
    - Por lo tanto, calcular el cuadrado más grande implica encontrar la distancia máxima permitida desde el origen que no viole las restricciones de los vegetales.
5. Algoritmo general:
    - Determinar las restricciones impuestas por los vegetales.
    - Utilizar las coordenadas de cada vegetal para calcular el lado máximo permitido para el cuadrado.
    - Maximizar 𝐿 asegurándonos de que todos los vegetales estén fuera del área cubierta por el cuadrado.
6. Resultado final:
    - Una vez calculada la longitud 𝐿, se multiplica por 4 para obtener el perímetro máximo.
    - Se redondea el resultado a cuatro dígitos decimales como lo solicita el problema.

## Pseudocódigo

```plaintext
INICIO

    // Paso 1: Leer entrada
    Leer N  // Número de vegetales
    Inicializar lista_vegetales como vacía
    Para i desde 1 hasta N:
        Leer X, Y  // Coordenadas del vegetal
        Agregar (X, Y) a lista_vegetales

    // Paso 2: Inicializar la distancia mínima
    distancia_minima ← infinito

    // Paso 3: Calcular la distancia mínima desde el origen
    Para cada vegetal (X, Y) en lista_vegetales:
        distancia_actual ← sqrt(X^2 + Y^2)
        Si distancia_actual < distancia_minima:
            distancia_minima ← distancia_actual

    // Paso 4: Calcular lado máximo del cuadrado
    lado_maximo ← distancia_minima * sqrt(2)

    // Paso 5: Calcular perímetro máximo
    perimetro_maximo ← 4 * lado_maximo

    // Paso 6: Formatear resultado
    perimetro_formateado ← Redondear(perimetro_maximo, 4 dígitos decimales)

    // Paso 7: Imprimir resultado
    Imprimir perimetro_formateado

FIN
```

## Detalle de las Funciones

1. Leer la entrada del problema:
    - Recibir 𝑁, el número de vegetales.
    - Para cada vegetal, guardar sus coordenadas (X,Y) en una lista o conjunto.
2. Inicializar variables necesarias:
    - Crear una variable distancia_minima con un valor inicial infinito (∞).
3. Calcular la distancia mínima de cada vegetal al origen (0,0):
    - Para cada vegetal (X,Y) en la lista:
      - Calcular la distancia euclidiana desde el origen: $$d = sqrt(X^2 + Y^2)$$
      - Actualizar distancia_minima como el menor valor entre distancia_minima y 𝑑.
4. Calcular el lado máximo del cuadrado:
    - La distancia mínima encontrada $$( 𝑑^{min} )$$ representa la distancia desde el origen hasta el borde más cercano permitido para el cuadrado.
    - Usar esta distancia para calcular el lado máximo del cuadrado: $$ L = 𝑑^{min} * sqrt(2)$$ (porque en un cuadrado rotado, la distancia de un vértice al centro es mayor por un factor sqrt(2) ).
5. Calcular el perímetro máximo:
    - Calcular el perímetro del cuadrado como: Perímetro = 4 * L
6. Formatear el resultado:
    - Redondear el perímetro a 4 dígitos decimales.
7. Imprimir el resultado:
    - Mostrar el perímetro calculado.

## Complejidad

1. Lectura de los datos de entrada
    - Leer 𝑁 puntos del campo y almacenarlos en una lista o conjunto.
    - Complejidad: 𝑂(𝑁), ya que se recorren las 𝑁 coordenadas una vez para procesarlas.
2. Calcular la distancia mínima al origen
    - Para cada punto (𝑋,𝑌), se calcula la distancia euclidiana al origen usando la fórmula: $$ d = sqrt(X^2 + Y^2)$$ y se compara con la distancia mínima encontrada hasta ese momento.
    - Complejidad: 𝑂(𝑁), ya que hay que recorrer los 𝑁 puntos y realizar una operación constante (suma, multiplicación, raíz cuadrada y comparación) para cada uno.
3. Cálculo del lado máximo y del perímetro
    - Usando la distancia mínima calculada, se derivan el lado máximo y el perímetro de forma directa.
    - Complejidad: 𝑂(1), ya que se trata de un cálculo constante.
4.  Formateo e impresión del resultado
    - Redondear el perímetro y formatearlo con 4 decimales.
    - Complejidad: 𝑂(1), ya que el redondeo e impresión son operaciones constantes.

### Complejidad Total
- La etapa dominante en términos de tiempo es el cálculo de la distancia mínima, que recorre los 𝑁 puntos.
- Por lo tanto, la complejidad temporal total es: 𝑂(𝑁)

### Complejidad Espacial
- Almacenamos los 𝑁 puntos en una lista o conjunto.
- Espacio adicional usado: 𝑂(𝑁).
Por lo tanto, la complejidad espacial total es: 𝑂(𝑁)

### Resumen de Complejidades
- Temporal: 𝑂(𝑁)
- Espacial: 𝑂(𝑁)
La solución es eficiente, dado que el algoritmo procesa cada punto una sola vez, y esto es fundamental para garantizar un buen desempeño incluso con $$𝑁 = 10^4$$.

# Problema C - Reducir la Desigualdad

Complejidonia no siempre ha sido la tierra pacífica e igualitaria que conocemos hoy. Los ricos Constantones eran dueños de los medios locales y sumieron a Complejidonia en la tiranía de su despiadado sistema económico: el Nlogonialismo, un sistema que promovía una extrema desigualdad, que curiosamente siempre beneficiaba a los Constantones.

Todo cambió tras el Congreso Internacional Colectivista y Popular (CICP), que derrocó a los Constantones y estableció un nuevo sistema económico que busca la equidad, considerando que cada habitante puede atravesar buenos y malos períodos económicos en su vida.

En el nuevo sistema, se establecieron un límite superior U sobre cuánto puede acumular una persona y un límite inferior L que representa la riqueza mínima necesaria para mantener un estilo de vida digno. Al final de cada mes, quienes posean más de U donarán lo que exceda del límite al CICP, mientras que quienes posean menos de L recibirán lo necesario para alcanzar el límite inferior.

Dado un registro de ingresos netos mensuales de un agricultor, debes ayudarlo a calcular, dado un escenario inicial, cuánto tendrá al final de un período determinado, considerando las reglas del sistema.

## Entrada

La primera línea contiene tres enteros N (1 ≤ N ≤ $$10^5$$), L y U (1 ≤ L ≤ U ≤ $$2 * 10^6$$), que indican respectivamente la cantidad de meses con registros, el límite inferior de riqueza y el límite superior de riqueza. La segunda línea contiene N enteros $$A^1, A^2, ..., A^n$$ ( $$-10^6$$ ≤ $$A^i$$ ≤ $$10^6$$) que representan los ingresos netos mensuales. La tercera línea contiene un entero Q (1 ≤ Q ≤ $$10^5$$) que representa el número de escenarios de interés. Cada una de las siguientes Q líneas describe un escenario con tres enteros B, E (1 ≤ B ≤ E ≤ N) y X (L ≤ X ≤ U), que indican el mes inicial, el mes final y la riqueza inicial del agricultor.

## Salida

Imprime Q líneas, cada una con un entero que indique cuánto tendrá el agricultor al final del período descrito en el escenario correspondiente.

## Casos de Prueba

<table>
  <thead>
    <tr>
      <th style="text-align: left; vertical-align: top;">Sample Input</th>
      <th style="text-align: left; vertical-align: top; background-color: gray;">Sample Output</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align: left; vertical-align: top;">
        5 1 41 <br>
        -10 10 1 -1 -70 <br>
        10 <br>
        2 5 31 <br>
        2 4 30 <br>
        2 4 29 <br>
        2 4 28 <br>
        1 2 20 <br>
        1 2 10 <br>
        1 4 11 <br>
        1 4 10 <br>
        1 4 40 <br>
        1 4 41
      </td>
      <td style="text-align: left; vertical-align: top;">
        1 <br>
        40 <br>
        39 <br>
        38 <br>
        20 <br>
        11 <br>
        11 <br>
        11 <br>
        40 <br>
        40 
      </td>
    </tr>
  </tbody>
</table>

En el primer escenario, los ingresos netos del granjero serían [10,1,-1,-70] y comienzan con una riqueza de 31:
 - Al final del primer mes, su riqueza es 41. Como 1 ≤ 41 ≤ 41, no donarán ni recibirán dinero.
 - Al final del segundo mes, su riqueza es 42 > 41, por lo que donan 1, terminando el mes con una riqueza de 41.
 - Al final del tercer mes, su riqueza es 40. Como 1 ≤ 40 ≤ 41, nuevamente no donarán ni recibirán dinero.
 - Finalmente, al final del cuarto mes, su riqueza es -30. Como -30 < 1, reciben una donación del ICPC terminando el mes con una riqueza de 1.

Por lo tanto, en este escenario, el granjero termina teniendo una riqueza de 1.

# Problema D - Estrellas Deslumbrantes

A Bernie le encanta observar las estrellas en el cielo. Su constelación favorita es la Constelación de la Bola de Papel, por su forma distintiva e inconfundible de... una bola de papel arrugada. Bernie descargó una imagen de la constelación de internet y ahora quiere imprimirla para pegarla en su pared. A Bernie también le gusta ver cómo las hojas de papel van saliendo gradualmente de la impresora, y para esta ocasión tomó una decisión: quiere que las estrellas se impriman en orden no creciente de brillo.

La constelación tiene N estrellas. Para cada una, Bernie conoce su nivel de brillo B, así como sus coordenadas X e Y en la imagen, donde la dirección X apunta hacia la derecha y la dirección Y hacia arriba. Sabe que las imágenes se imprimen de arriba hacia abajo (es decir, en orden decreciente de la coordenada Y) y que todo en una misma línea horizontal se imprime simultáneamente.

El plan de Bernie puede describirse así: para cualesquiera dos estrellas S y T, si S es más brillante que T, entonces S debe imprimirse antes o al mismo tiempo que T. Antes de imprimir la imagen, Bernie puede rotarla en cualquier ángulo alrededor de un punto dado, pero no puede escalarla, reflejarla ni distorsionarla. Ahora Bernie necesita tu ayuda para determinar si existe alguna rotación que permita imprimir las estrellas en el orden que desea.

## Entrada
La primera línea contiene un número entero N (3 ≤ N ≤ 1000) que indica el número de estrellas en la constelación. Cada una de las siguientes N líneas describe una estrella con tres enteros X, Y ($$-10^4$$ ≤ X, Y ≤ $$10^4$$) y B (1 ≤ B ≤ 1000), donde X e Y son las coordenadas de la estrella en la imagen, y B es su nivel de brillo. No hay dos estrellas en la misma ubicación.

## Salida
Imprime una sola línea con la letra mayúscula "Y" si existe alguna rotación que permita imprimir las estrellas en orden no creciente de brillo, y la letra mayúscula "N" en caso contrario.

## Casos de Prueba

<table>
  <thead>
    <tr>
      <th style="text-align: left; vertical-align: top;">Sample Input</th>
      <th style="text-align: left; vertical-align: top; background-color: gray;">Sample Output</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align: left; vertical-align: top;">
        4 <br>
        0 2 1 <br>
        1 -1 2 <br>
        3 3 5 <br>
        4 0 2
      </td>
      <td style="text-align: left; vertical-align: top;">
         Y
      </td>
    </tr>
    <tr>
      <td style="text-align: left; vertical-align: top;">
        5 <br>
        0 4 6 <br>
        2 4 5 <br>
        3 7 2 <br>
        4 4 6 <br>
        3 0 8
      </td>
      <td style="text-align: left; vertical-align: top;">
         Y
      </td>
    </tr>
    <tr>
      <td style="text-align: left; vertical-align: top;">
         4 <br>
       -1 2 5 <br>
        0 0 2 <br>
        3 4 1 <br>
        4 2 4
      </td>
      <td style="text-align: left; vertical-align: top;">
         N
      </td>
    </tr>
  </tbody>
</table>

# Problema E - Pastel de Fruta Huevo

Hoy es el cumpleaños de Jaime y, para celebrarlo, sus amigos ordenaron un pastel decorado con frutas huevo y caquis. Cuando llegó el pastel, para su sorpresa, notaron que la pastelería no usó cantidades iguales de frutas huevo y caquis, sino que simplemente distribuyeron las frutas al azar por el borde del pastel.

Jaime come caquis todos los días, así que estaba ansioso por probar algunas frutas huevo en su cumpleaños. Sin embargo, como no quiere comer demasiado, su porción de pastel debe estar decorada con como máximo S frutas. Dado que a Jaime no le gusta que una fruta sea cortada en partes, cada fruta debe estar completamente en su porción o completamente en el resto del pastel. El problema es que, con las frutas distribuidas de manera tan caótica, a sus amigos les está costando cortar una porción adecuada para él.

Jaime está a punto de quejarse de que sus amigos están tardando demasiado en cortar su porción, pero para hacerlo necesita saber cuántas porciones diferentes con al menos una fruta huevo y con como máximo S frutas existen. Una porción se define únicamente con base en el conjunto de frutas que contiene. Como Jaime presta mucha atención a los detalles, puede distinguir cualquier par de frutas, incluso si ambas son del mismo tipo. Por lo tanto, dos porciones se consideran diferentes cuando no contienen exactamente el mismo conjunto de frutas.

## Entrada
La primera línea contiene una cadena circular B (3 ≤ |B| ≤ $$10^5$$) que describe el borde del pastel. Cada carácter de B es una letra mayúscula "E" o "P", indicando respectivamente que hay una fruta huevo o un caqui en el borde del pastel. La segunda línea contiene un número entero S (1 ≤ S ≤ |B|) que representa el número máximo de frutas que una porción puede contener.

## Salida
Imprime una sola línea con un número entero que indique el número de porciones diferentes con al menos una fruta huevo y con como máximo S frutas.

## Casos de Prueba

<table>
  <thead>
    <tr>
      <th style="text-align: left; vertical-align: top;">Sample Input</th>
      <th style="text-align: left; vertical-align: top; background-color: gray;">Sample Output</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align: left; vertical-align: top;">
        PEPEP <br>
        2
      </td>
      <td style="text-align: left; vertical-align: top;">
         6
      </td>
    </tr>
    <tr>
      <td style="text-align: left; vertical-align: top;">
        EPE <br>
        1
      </td>
      <td style="text-align: left; vertical-align: top;">
        2
      </td>
    </tr>
    <tr>
      <td style="text-align: left; vertical-align: top;">
        PPPP <br>
        1
      </td>
      <td style="text-align: left; vertical-align: top;">
         0
      </td>
    </tr>
    <tr>
      <td style="text-align: left; vertical-align: top;">
        EPEP <br>
        2
      </td>
      <td style="text-align: left; vertical-align: top;">
         6
      </td>
    </tr>
  </tbody>
</table>

# Problema F - Fabricando Esculturas

Miguel Angelo es un gran escultor, ampliamente reconocido por sus esculturas al aire libre. En su ciudad natal, es muy común encontrar una de sus creaciones en plazas y jardines. La gente ama sus esculturas, no solo por su belleza, sino también porque parecen nuevas incluso después de décadas. Las esculturas no se degradan fácilmente gracias al material y la técnica desarrollada por Miguel y su equipo a lo largo de los años.

Para construir las esculturas, Miguel primero crea su base apilando bloques de yeso impermeable (su material secreto), formando varias pilas de bloques en una línea recta. Siempre utiliza bloques idénticos, y cada pila tiene al menos un bloque. Para estabilizar la estructura, la rodea con dos grandes paneles de vidrio, uno detrás de las pilas y otro frente a ellas. Luego, espera la lluvia el tiempo que sea necesario. Si la estructura es tal que no acumula agua durante este procedimiento, Miguel está seguro de que la base puede usarse para obtener una obra de arte duradera. Nota que el agua se acumulará en un bloque si hay obstáculos (otros bloques) a ambos lados (a la izquierda y a la derecha).

La siguiente imagen muestra la vista frontal de varias bases diferentes. Todas consisten en tres pilas hechas con un total de seis bloques, con cada pila teniendo al menos un bloque como se requiere. Sin embargo, las ocho bases de la izquierda generarán obras de arte duraderas, mientras que las dos bases de la derecha no.

<table>
  <thead>
    <tr>
      <th style="text-align: left; vertical-align: top;"> </th>
      <th style="text-align: left; vertical-align: top; background-color: gray;"> </th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align: left; vertical-align: top;">
        114 123 132 141 |
      </td>
      <td style="text-align: left; vertical-align: top;">
        213
      </td>
    </tr>
    <tr>
      <td style="text-align: left; vertical-align: top;">
        222 231 321 411 |
      </td>
      <td style="text-align: left; vertical-align: top;">
        312 
      </td>
    </tr>
  </tbody>
</table>

Miguel Angelo está recibiendo muchas solicitudes de esculturas. Aunque tiene total libertad para crear las obras de arte, quiere ser justo y usar el mismo número de pilas y el mismo número de bloques en cada una de las esculturas. Como no quiere vender esculturas idénticas a diferentes clientes, construirá una base distinta cada vez.

Miguel está preocupado por no poder cumplir con todas las solicitudes. Ayúdalo a calcular el número de bases diferentes que puede construir, dado el número de pilas y bloques que debe tener la base, asegurándote de que no acumulen agua.

## Entrada
La entrada consiste en una sola línea que contiene dos enteros S y B (1 ≤ S ≤ B ≤ 5000) que indican respectivamente el número de pilas y el número de bloques que debe tener la base.

## Salida
Imprime una sola línea con un número entero que indique el número de bases diferentes que no acumulan agua que Miguel puede construir. Debido a que este número puede ser muy grande, imprime el resto de dividirlo por $$10^9 + 7$$.

## Casos de Prueba

<table>
  <thead>
    <tr>
      <th style="text-align: left; vertical-align: top;">Sample Input</th>
      <th style="text-align: left; vertical-align: top; background-color: gray;">Sample Output</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align: left; vertical-align: top;">
         3 6
      </td>
      <td style="text-align: left; vertical-align: top;">
         8
      </td>
    </tr>
    <tr>
      <td style="text-align: left; vertical-align: top;">
         3 7
      </td>
      <td style="text-align: left; vertical-align: top;">
         12
      </td>
    </tr>
  </tbody>
</table>

# Problema G - Pegando Imágenes

Enzo recientemente viajó a la ciudad de Montevideo, donde vio un gran cartel con el nombre de la ciudad. Decidió tomar fotos del cartel para hacer un collage y enviárselo a su amigo Demonio. Enzo quiere formar el nombre de su amigo tomando una o varias fotos de secciones del cartel. Por ejemplo, con la cadena "MONTEVIDEO", podría formar el nombre de su amigo juntando "DE-MON-I-O", usando cuatro fotos para formar todo el nombre. Es fácil demostrar que el resultado no puede lograrse con menos fotos.

Se te dará el nombre de una ciudad y una lista de nombres de amigos. Devuelve el número mínimo de fotos necesarias para formar el nombre de cada amigo. Al formar los nombres, las fotos no pueden rotarse, reflejarse ni modificarse de ninguna manera.

## Entrada
La primera línea contiene una cadena C que indica el nombre de la ciudad. La segunda línea contiene un entero positivo N que representa el número de amigos. Cada una de las siguientes N líneas contiene una cadena que indica el nombre de un amigo. Todas las cadenas no están vacías y consisten únicamente de letras mayúsculas. La suma de las longitudes de todas las cadenas es como máximo $$2 * 10^5$$.

## Salida
Imprime N líneas, cada una con un número entero que indica el número mínimo de fotos necesarias para formar el nombre correspondiente en la entrada, o el valor "-1" si no es posible generarlo.

## Caso de Prueba

<table>
  <thead>
    <tr>
      <th style="text-align: left; vertical-align: top;">Sample Input</th>
      <th style="text-align: left; vertical-align: top; background-color: gray;">Sample Output</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align: left; vertical-align: top;">
         MONTEVIDEO <br>
         4 <br>
         DEMONIO <br>
         MONTE <br>
         EDIT <br>
         WON
      </td>
      <td style="text-align: left; vertical-align: top;">
         4 <br>
         1 <br>
         4 <br>
        -1
      </td>
    </tr>
    <tr>
      <td style="text-align: left; vertical-align: top;">
        SANTIAGO <br>
        3 <br>
        TITA <br>
        SANTIAGO <br>
        NAS
      </td>
      <td style="text-align: left; vertical-align: top;">
        3 <br>
        1 <br>
        3
      </td>
    </tr>
  </tbody>
</table>

# Problema H - ¿Guardar o Continuar?

Pig es un juego simple de dados para dos o más jugadores. En cada turno, un jugador lanza repetidamente un dado hasta que se obtiene un 1 o el jugador decide "guardar":
- Si el jugador lanza un 1, no obtiene puntos en su turno y es el turno del siguiente jugador.
- Si el jugador lanza cualquier otro número, este se suma al total de puntos de su turno, y el jugador puede decidir entre "guardar" o "continuar".
- Si el jugador elige "guardar", el total de puntos de su turno se suma a su puntaje y es el turno del siguiente jugador. Si decide continuar, lanza nuevamente el dado.

El primer jugador en alcanzar exactamente 75 puntos gana el juego. Si el puntaje de un jugador más el total de su turno excede 75, no obtiene puntos en ese turno y es el turno del siguiente jugador.

Catelyn Tully está jugando Pig con su padre Hoster. Si Catelyn comienza su turno lanzando un 5, podría guardar y sumar 5 puntos en su turno. Si elige continuar y lanza un 2, podría guardar y sumar 7 puntos. Si elige continuar nuevamente y lanza un 1, debe terminar su turno sin sumar puntos. Si en su turno Hoster lanza la secuencia 4-5-3-5-5 y luego decide guardar, suma 22 puntos a su puntaje actual (a menos que la suma exceda 75). Luego Catelyn lanza nuevamente el dado, y así sucesivamente, hasta que uno de ellos alcance exactamente 75 puntos.

Hoster encuentra el juego muy didáctico y se ha convertido en un jugador bastante bueno. Después de jugar varias veces con Catelyn, se dio cuenta de que ella es muy impulsiva y lanza los dados más veces de las que debería. Catelyn desea mejorar su forma de jugar, pero desafortunadamente Hoster no tiene mucha paciencia para enseñarle, por lo que necesita tu ayuda. Mientras juega con su padre, Catelyn debe decidir varias veces si guardar o continuar, y a veces no está segura de qué hacer. ¿Puedes aconsejarle para que cada decisión maximice su probabilidad de ganar?

## Entrada

La primera línea contiene un entero Q (1 ≤ Q ≤ 1000) indicando el número de preguntas en las que Catelyn necesita tu consejo. Cada una de las siguientes Q líneas describe una pregunta con tres enteros C, H y X (0 ≤ C, H ≤ 73, X ≥ 2, C + X ≤ 75), que representan respectivamente el puntaje actual de Catelyn, el puntaje actual de Hoster y el total acumulado de Catelyn en su turno (suma de los lanzamientos de los dados durante su turno).

## Salida

Imprime Q líneas, cada una con un carácter que indique la decisión que debe tomar Catelyn para la pregunta correspondiente de la entrada, de modo que se maximice su probabilidad de ganar si tanto Catelyn como Hoster juegan de manera óptima. Para cada pregunta, el carácter debe ser la letra mayúscula "H" si la decisión óptima es guardar, o la letra mayúscula "C" si la decisión óptima es continuar. Se garantiza que la decisión óptima puede diferenciarse claramente; esto significa que $$| p^h - p^c | > 10^{-5}$$, donde $$p^h$$ es la probabilidad de ganar si Catelyn decide guardar, y $$p^c$$ es la probabilidad de ganar si decide continuar $$(0 ≤ p^h, p^c ≤ 1)$$.

## Caso de Prueba 

<table>
  <thead>
    <tr>
      <th style="text-align: left; vertical-align: top;">Sample Input</th>
      <th style="text-align: left; vertical-align: top; background-color: gray;">Sample Output</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align: left; vertical-align: top;">
         3 <br>
         15 0 3 <br>
         35 50 40 <br>
         15 0 30
      </td>
      <td style="text-align: left; vertical-align: top;">
         C <br>
         H <br>
         H
      </td>
    </tr>
  </tbody>
</table>

# Problema I - Mejorar SPAM

Después del increíble trabajo que hiciste eliminando usuarios duplicados de la base de datos de clientes, tu jefe está ansioso por impresionarse con tus mejoras al sistema SPAM (Sistema para Publicar Asombroso Marketing).

A pesar de que las campañas de marketing son extremadamente útiles para los clientes, se han recibido quejas en el servicio de atención al cliente indicando que se envían demasiados mensajes, y que algunos clientes incluso reciben el mismo mensaje varias veces.

SPAM está basado en listas de correo. Cada lista de correo está compuesta por correos electrónicos de clientes y/o otras listas de correo. Los correos electrónicos de los clientes pueden agregarse a listas de correo existentes en cualquier momento, mientras que una lista de correo solo puede ser agregada a otras listas en el momento en que se crea. Nota que no es posible crear varias listas de correo al mismo tiempo.

Cuando se envía un mensaje a una lista de correo, el sistema envía el mensaje a cada dirección en la lista. Si la dirección en la lista es un correo electrónico de cliente, el mensaje se envía a ese correo. Si la dirección es otra lista de correo, entonces el proceso se inicia nuevamente para esa lista.

Por razones de privacidad, en el siguiente ejemplo las listas de correo y los correos de clientes se representan por enteros. Supón que 1, 2 y 3 son listas de correo, mientras que 4 y 5 son correos de clientes. Además, la lista de correo 1 contiene las listas de correo 2 y 3, la lista 2 contiene los correos de cliente 4 y 5, mientras que la lista 3 contiene el correo 4 y la lista 2. Ahora supón que se envía un mensaje a la lista 1. Esto significa que la lista es procesada como se describió anteriormente, y luego se procesan las listas 2 y 3. Cuando se procesa la lista 2, el mensaje se envía a los correos 4 y 5. Cuando se procesa la lista 3, se envía un segundo mensaje al correo 4, y la lista 2 se procesa nuevamente, lo que genera un tercer mensaje enviado al correo 4 y un segundo mensaje enviado al correo 5. En total, se envían cinco mensajes a los correos de clientes.

Tu tarea es optimizar SPAM de tal forma que ningún cliente reciba el mismo mensaje más de una vez. Como primer paso, tu jefe quiere saber el número de mensajes enviados antes y después de tus mejoras. En el ejemplo anterior, después de tu trabajo, solo deberían enviarse dos mensajes a los correos de clientes.

## Entrada
La primera línea contiene dos enteros N y L (2 ≤ N ≤ 2000, 1 ≤ L ≤ min(N - 1, 1000)), que representan respectivamente el número de direcciones en el sistema y el número de direcciones que son listas de correo. Las direcciones se identifican mediante enteros únicos del 1 al N. Las direcciones del 1 al L son listas de correo, mientras que las demás son correos de clientes. 

Para i = 1, 2, ..., L, las siguientes L líneas describen la lista de correo i con un entero K (1 ≤ K < N) seguido de K enteros diferentes $$ M^1, M^2, ..., M^K (1 ≤ M^i$$ ≤ N para i = 1, 2, ..., K), indicando que la lista de correo contiene las K direcciones $$ M^1, M^2, ..., M^K $$. Cada dirección de cliente aparece al menos en una lista de correo.

## Salida
Imprime una sola línea con dos enteros B y A, que indican respectivamente el número de mensajes enviados a los correos de clientes antes y después de tus mejoras, si se envía un mensaje a la lista de correo 1. Como estos números pueden ser muy grandes, imprime el residuo de dividirlos entre $$ 10^9 + 7 $$.

## Casos de Prueba

<table>
  <thead>
    <tr>
      <th style="text-align: left; vertical-align: top;">Sample Input</th>
      <th style="text-align: left; vertical-align: top; background-color: gray;">Sample Output</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align: left; vertical-align: top;">
        5 3 <br>
        2 2 3 <br>
        2 4 5 <br>
        2 4 2
      </td>
      <td style="text-align: left; vertical-align: top;">
        5 2
      </td>
    </tr>
    <tr>
      <td style="text-align: left; vertical-align: top;">
         15 6 <br>
         1 6 <br>
         7 10 11 12 13 9 7 8 <br>
         5 6 14 4 5 15 <br>
         2 14 15 <br>
         2 4 14 <br>
         2 5 4
      </td>
      <td style="text-align: left; vertical-align: top;">
         5 2
      </td>
    </tr>
    <tr>
      <td style="text-align: left; vertical-align: top;">
         10 5 <br>
         4 8 9 10 3 <br>
         3 9 10 6 <br>
         3 8 9 7 <br>
         6 2 3 6 7 8 10 <br>
         5 9 10 3 1 7
      </td>
      <td style="text-align: left; vertical-align: top;">
         6 4
      </td>
    </tr>
  </tbody>
</table>

# Problema J - El Saltamontes Saltarín

Jazmín tiene un jardín frente a su casa, con N plantas formando una línea en dirección de izquierda a derecha. Está muy orgullosa de sus plantas y mide con gran precisión sus alturas mientras crecen, porque piensa que cada planta es diferente y debe tener una altura distinta.

Un día, Jazmín encontró un saltamontes en su jardín, y tras observarlo un tiempo, notó un comportamiento peculiar. Durante cada salto, el saltamontes se mueve hacia la primera planta más alta que su planta actual, en la dirección hacia la que está mirando. Además, antes de aterrizar en la nueva planta, el saltamontes realiza un giro hacia atrás que cambia su dirección. Es decir, si antes del salto el saltamontes mira hacia la izquierda, una vez completado el salto estará mirando hacia la derecha, y viceversa. El saltamontes sigue saltando hasta que no hay una planta más alta en la dirección hacia la que está mirando.

Jazmín decidió registrar sus observaciones del saltamontes. Cada vez que lo veía, anotaba en qué planta estaba y en qué dirección estaba mirando. También registró cómo estaban creciendo sus plantas, como siempre hace. Ahora Jazmín se pregunta, para cada avistamiento del saltamontes, ¿en qué planta se detuvo después de saltar? Sin embargo, su cuaderno está roto y no puede escribir su propio programa. ¿Puedes ayudarla?

## Entrada
La primera línea contiene dos enteros N y M (1 ≤ N, M ≤ $$2 * 10^5$$), que representan respectivamente el número de plantas y el número de registros. Las plantas se identifican con enteros distintos del 1 al N según sus posiciones frente a la casa, comenzando con la planta más a la izquierda. 

La segunda línea contiene N enteros diferentes $$H^1, H^2, ..., H^n$$ (0 ≤ $$H_i$$ ≤ $$10^9$$ para i = 1, 2, ..., N), donde $$H_i$$ es la altura inicial de la planta i. 

Las siguientes M líneas describen los registros de Jazmín en orden cronológico, una línea por registro:
- Si un registro representa el crecimiento de una planta, la línea contiene la letra mayúscula "U" seguida de dos enteros I (1 ≤ I ≤ N) y H (H ≤ $$10^9$$), indicando que la nueva altura de la planta I es H. La nueva altura H es mayor que la altura anterior de la planta I y diferente de la altura actual de cualquiera de las otras plantas.
- Si un registro representa un avistamiento del saltamontes, la línea contiene la letra mayúscula "L" o "R" seguida de un entero J (1 ≤ J ≤ N), indicando que el saltamontes comienza a saltar desde la planta J; el saltamontes comienza mirando hacia la izquierda si la letra es "L" y mirando hacia la derecha si la letra es "R".

Al menos un registro es un avistamiento del saltamontes.

## Salida
Imprime una línea por cada avistamiento del saltamontes. La línea debe contener un entero que indique la planta donde el saltamontes se detiene después de saltar. Escribe los resultados en orden cronológico, es decir, en el mismo orden en que aparecen en la entrada.

## Casos de Prueba

<table>
  <thead>
    <tr>
      <th style="text-align: left; vertical-align: top;">Sample Input</th>
      <th style="text-align: left; vertical-align: top; background-color: gray;">Sample Output</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align: left; vertical-align: top;">
         10 4 <br>
         1 8 5 6 10 20 12 15 2 4 <br>
         L 2 <br>
         R 3 <br>
         U 10 16 <br>
         L 9
      </td>
      <td style="text-align: left; vertical-align: top;">
         2 <br>
         5 <br>
         6
      </td>
    </tr>
  </tbody>
</table>

# Problema K - Conoce a tus Alienígenas

Nuestro mundo ha sido invadido por alienígenas cambiaformas que secuestran personas y roban sus identidades. Eres un inspector de una fuerza especial dedicada a detectarlos y capturarlos. Para ello, se te han dado herramientas especiales para detectar alienígenas y diferenciarlos de humanos reales. 

Tu misión actual es visitar una ciudad que se sospecha ha sido invadida, inspeccionar en secreto a cada persona allí para saber quiénes son alienígenas y quiénes no lo son, y reportar todo esto a la central. Luego, podrán enviar fuerzas a la ciudad por sorpresa y capturar a todos los alienígenas a la vez.

Los alienígenas están al tanto del trabajo de inspectores como tú y están monitoreando todos los canales de radio para detectar la transmisión de estos reportes y anticipar cualquier represalia. Por eso, ha habido varios intentos de encriptar los reportes, y el método más reciente utiliza polinomios.

La ciudad que debes visitar tiene N ciudadanos, cada uno identificado por un número entero par distinto que va desde el 2 hasta el 2N. Quieres encontrar un polinomio P tal que, para cada ciudadano i:

- $P^i > 0$ si el ciudadano i es humano  
- $P^i < 0$ si el ciudadano i es alienígena  

Este polinomio se transmitirá a la central. Con el objetivo de minimizar el ancho de banda, el polinomio debe cumplir algunos requisitos adicionales:

1. Cada raíz y coeficiente debe ser un número entero.
2. El coeficiente del término de mayor grado debe ser 1 o -1.
3. El grado del polinomio debe ser lo más bajo posible.

Para cada ciudadano, sabes si es humano o alienígena. Con esta información, debes encontrar un polinomio que cumpla con las restricciones mencionadas.

## Entrada

La entrada consiste en una sola línea que contiene una cadena S de longitud N (1 ≤ N ≤ 10^4), donde N es la población de la ciudad. Para i = 1,2,...,N, el i-ésimo carácter de S es la letra mayúscula "H" o "A", lo que indica, respectivamente, que el ciudadano 2i es humano o alienígena.

## Salida

La primera línea debe contener un entero D que indica el grado del polinomio que cumple con las restricciones descritas. La segunda línea debe contener D + 1 enteros que representan los coeficientes del polinomio, en orden decreciente para los términos correspondientes. 

Se garantiza que existe al menos una solución tal que el valor absoluto de cada coeficiente es menor que $2^63$.

## Casos de Prueba

<table>
  <thead>
    <tr>
      <th style="text-align: left; vertical-align: top;">Sample Input</th>
      <th style="text-align: left; vertical-align: top; background-color: gray;">Sample Output</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align: left; vertical-align: top;">
         HHH
      </td>
      <td style="text-align: left; vertical-align: top;">
         0 <br>
         1
      </td>
    </tr>
    <tr>
      <td style="text-align: left; vertical-align: top;">
        AHHA
      </td>
      <td style="text-align: left; vertical-align: top;">
         2 <br>
        -1 10 -21
      </td>
    </tr>
    <tr>
      <td style="text-align: left; vertical-align: top;">
         AHHHAH
      </td>
      <td style="text-align: left; vertical-align: top;">
        3 <br>
        1 -23 159 -297
      </td>
    </tr>
  </tbody>
</table>

# Problema L - Aprovechando el MDT

El reino de Nlogonia es muy próspero. Su rey, Constantourist, expandió el reino conquistando ciudades cercanas. Sin embargo, ahora que la vida de Constantourist está llegando a su fin, sus dos hijos, Javasar y Golangsar, deben decidir el futuro del reino.

En lugar de luchar una guerra innecesaria para elegir al próximo rey, los dos hijos intentan negociar un acuerdo para dividir la jurisdicción del reino en dos partes. Nlogonia es una tierra con forma rectangular que tiene N kilómetros en la dirección Norte-Sur y M kilómetros en la dirección Oeste-Este. Durante la etapa inicial de las negociaciones, los dos hijos lograron dividir la tierra en N * M parcelas cuadradas de un kilómetro en cada lado, utilizando líneas divisorias paralelas a los límites del reino. 

El siguiente paso es distribuir las parcelas entre los dos hijos. Antes de que las negociaciones puedan continuar, Javasar necesita decidir qué parcelas quiere reclamar para sí mismo. Él ya ha categorizado cada parcela como buena o mala, según la calidad del suelo. Javasar quiere que su jurisdicción sea reconocida como la mejor en Nlogonia, por lo que planea elegir solo parcelas con buena calidad de suelo. 

Además, siendo perfeccionista, Javasar decidió que las parcelas que reclame deben formar un cuadrado.

Javasar está preocupado porque estos requisitos podrían hacer que obtenga solo unas pocas parcelas. Por suerte, durante una de sus aventuras en Byteland, encontró una antigua Herramienta Mágica Divina (MDT) que, cuando está activa, puede invertir la calidad del suelo de la parcela en la que Javasar se encuentra actualmente. En otras palabras, si está activa, la MDT convierte una parcela de mala calidad en buena, y viceversa.

Con esta herramienta a su disposición, Javasar ideó el plan perfecto. Él viajará fuera del reino, al oeste de la parcela que está en la esquina noroeste, y luego visitará cada parcela exactamente una vez siguiendo la ruta que muestra la imagen adjunta. De esta manera, Javasar evitará activar o desactivar la MDT mientras está dentro del reino, y así nadie lo verá manipulando la herramienta. Aunque la MDT es mágica y avanzada, no se activa ni desactiva por sí misma.

Como el principal asesor de Javasar, tu tarea es decirle cuántas parcelas puede obtener como máximo, cumpliendo con sus requisitos, si utiliza la MDT de manera óptima.

## Entrada

La primera línea contiene dos enteros N y M (1 ≤ N, M ≤ 1000), que indican la longitud (en kilómetros) del reino Nlogonia en las direcciones Norte-Sur y Oeste-Este, respectivamente. Las siguientes N líneas contienen una cadena de M caracteres, donde cada carácter es la letra mayúscula "G" o "B", representando que la calidad del suelo de la parcela es buena o mala, respectivamente. La descripción de las parcelas del reino está hecha de norte a sur y de oeste a este.

## Salida

La salida debe contener una sola línea con un entero que indica el número máximo de parcelas que Javasar puede obtener, cumpliendo con sus requisitos, si utiliza la MDT de manera óptima.

## Casos de Prueba

<table>
  <thead>
    <tr>
      <th style="text-align: left; vertical-align: top;">Sample Input</th>
      <th style="text-align: left; vertical-align: top; background-color: gray;">Sample Output</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align: left; vertical-align: top;">
         2 2 <br>
         GG <br>
         GG
      </td>
      <td style="text-align: left; vertical-align: top;">
         4
      </td>
    </tr>
    <tr>
      <td style="text-align: left; vertical-align: top;">
         5 5 <br>
         GGGGG <br>
         GBBBG <br>
         GBBBG <br>
         GBBBG <br>
         GGGGG
      </td>
      <td style="text-align: left; vertical-align: top;">
         9
      </td>
    </tr>
  </tbody>
</table>

# Problema M - Cordilleras

Famosa por sus cordilleras, Nlogonia atrae a millones de turistas cada año. El gobierno cuenta con un presupuesto dedicado al mantenimiento continuo de los senderos de montaña que se extienden por todo el país, y la mayoría de ellos están llenos de miradores escénicos, accesibles mediante pasarelas y escaleras de madera.

Actualmente en un viaje por Nlogonia, con la esperanza de regresar a casa con muchas fotos impresionantes, Lola y su esposo quieren visitar la mayor cantidad de miradores posible. Su plan es recorrer un sendero diferente cada día y explorar sus miradores. Sin embargo, para evitar quedar exhaustos al final del día, si pasar de un mirador al siguiente requiere subir más de X metros, simplemente terminan su recorrido del día y regresan a su hotel para descansar. Afortunadamente, cada sendero en Nlogonia está equipado con modernos teleféricos, por lo que la pareja puede comenzar su recorrido en cualquier mirador que decidan. Una vez que inician el recorrido, la pareja solo se mueve en dirección hacia la cima de la montaña.

Para asegurarse de no desperdiciar un día, Lola solo quiere recorrer senderos donde pueda llegar a un número razonable de miradores. Dadas las altitudes de los miradores escénicos en un sendero de montaña, debes determinar el número máximo de miradores que la pareja puede visitar.

## Entrada

La primera línea contiene dos enteros N (1 ≤ N ≤ 1000) y X (0 ≤ X ≤ 8848), que indican respectivamente el número de miradores escénicos en el sendero de montaña y el número máximo de metros que Lola y su esposo están dispuestos a subir de un mirador al siguiente. La segunda línea contiene N enteros $$A^1, A^2, ..., A^n (1 ≤ A^i ≤ 8848 \; \text{para} \; i = 1, 2, ..., N)$$, donde $$A^i$$ es la altitud (en metros) del i-ésimo mirador. Los miradores están dados en el orden en que aparecen en el sendero, y sus altitudes son no decrecientes, es decir, $$A^i ≤ A^{i+1} \; \text{para} \; i = 1, 2, ..., N - 1$$.

## Salida

La salida debe contener una sola línea con un entero que indique el número máximo de miradores escénicos que se pueden visitar sin subir más de X metros de un mirador al siguiente, considerando que el recorrido puede iniciarse en cualquier mirador.

## Casos de Prueba

<table>
  <thead>
    <tr>
      <th style="text-align: left; vertical-align: top;">Sample Input</th>
      <th style="text-align: left; vertical-align: top; background-color: gray;">Sample Output</th>
    </tr>
  </thead>
  <tbody>
    <tr>
      <td style="text-align: left; vertical-align: top;">
        9 2 <br>
        3 14 15 92 653 5897 5897 5898 5900
      </td>
      <td style="text-align: left; vertical-align: top;">
         4
      </td>
    </tr>
    <tr>
      <td style="text-align: left; vertical-align: top;">
        9 0 <br>
        3 14 15 92 653 5897 5897 5898 5900
      </td>
      <td style="text-align: left; vertical-align: top;">
        2
      </td>
    </tr>
    <tr>
      <td style="text-align: left; vertical-align: top;">
        9 8848 <br>
        3 14 15 92 653 5897 5897 5898 5900
      </td>
      <td style="text-align: left; vertical-align: top;">
        9
      </td>
    </tr>
  </tbody>
</table>
