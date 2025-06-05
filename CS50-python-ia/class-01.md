# Resumen Técnico: Inteligencia Artificial con Python (Brian Yu)

## 1. Introducción a la IA
- **Definición**:  
  Simulación de inteligencia humana en máquinas mediante:
  - Algoritmos de búsqueda.
  - Toma de decisiones bajo incertidumbre.
  - Aprendizaje automático (ej: redes neuronales).

## 1.1 Definición Formal
La **Inteligencia Artificial (IA)** es un campo interdisciplinario que busca desarrollar sistemas capaces de realizar tareas que, de ser ejecutadas por humanos, requerirían inteligencia. Estos sistemas se basan en:

- **Algoritmos deterministas/no deterministas**  
- **Modelos matemáticos**  
- **Aprendizaje a partir de datos**  

### 1.1.1 Componentes Clave
| Componente               | Descripción                                                                 | Ejemplo                          |
|--------------------------|-----------------------------------------------------------------------------|----------------------------------|
| **Percepción**           | Interpretación de entradas sensoriales (datos)                              | Reconocimiento de imágenes       |
| **Razonamiento**         | Inferencia lógica para resolver problemas                                   | Diagnóstico médico               |
| **Toma de decisiones**   | Selección de acciones óptimas dado un estado                                | Jugadas en ajedrez               |
| **Aprendizaje**          | Adaptación basada en experiencia                                            | Filtrado de spam                 |

## 1.2 Enfoques Principales
### 1.2.1 Búsqueda y Optimización
- **Problemas abordados**:  
  - Encontrar caminos en grafos (ej: GPS).  
  - Solución de puzzles (ej: Cubo de Rubik).  
- **Algoritmos representativos**:  
  ```python
  def búsqueda_óptima(problema):
      frontera = Frontera()
      frontera.agregar(problema.estado_inicial)
      while not frontera.vacía():
          estado = frontera.eliminar()
          if problema.es_solución(estado):
              return estado
          for acción in problema.acciones(estado):
              frontera.agregar(problema.resultado(estado, acción))
  ```
### 1.2.2 Toma de Decisiones bajo Incertidumbre

#### Fundamentos Matemáticos
- **Espacio de estados probabilísticos**:
  - Representado como tupla `(S, A, P, R)` donde:
    - `S`: Conjunto de estados
    - `A`: Conjunto de acciones
    - `P(s'|s,a)`: Función de transición (probabilidad de llegar a s' desde s tomando a)
    - `R(s,a,s')`: Función de recompensa
- **Ecuación de Bellman** (para valor óptimo): `V*(s) = maxₐ Σₛ' P(s'|s,a)[R(s,a,s') + γV*(s')]`
  - Donde:
  - `V*(s)`: Valor óptimo del estado `s`
  - `γ`: Factor de descuento (0 ≤ γ ≤ 1)
  - `P(s'|s,a)`: Probabilidad de transición (probabilidad de llegar a s' desde s tomando a)
  - `R(s,a,s')`: Función de recompensa

#### Técnicas Clave

1. **Procesos de Decisión Markovianos (MDPs)**:
   - Propiedad Markoviana: El futuro solo depende del estado presente
   - Algoritmo de iteración de valores:

     ```python
     def value_iteration(mdp, ε, γ=0.99):
        V = {s: 0 for s in mdp.states}  # Inicialización de valores
        while True:
            Δ = 0
            for s in mdp.states:
                v_old = V[s]
                # Cálculo de valores Q para todas las acciones
                Q = {}
                for a in mdp.actions(s):
                    Q[a] = sum(p * (r + γ * V[s_]) 
                           for (p, s_, r) in mdp.transitions(s, a))
                V[s] = max(Q.values()) if Q else 0
                Δ = max(Δ, abs(v_old - V[s]))
            if Δ < ε:  # Criterio de convergencia
                break
        
        # Extracción de política óptima
        π = {}
        for s in mdp.states:
            Q = {a: sum(p * (r + γ * V[s_]) 
                 for (p, s_, r) in mdp.transitions(s, a)) 
                 for a in mdp.actions(s)}
            π[s] = max(Q, key=Q.get) if Q else None
        return π
     ```

   - **Parámetros clave**:
     - `ε`: Umbral de convergencia (ej: 1e-6)
     - `γ`: Factor de descuento (típicamente 0.9-0.99)

2. **Redes Bayesianas**:
   - Representación gráfica de dependencias probabilísticas mediante:
     - Nodos: Variables aleatorias
     - Aristas: Dependencias probabilísticas
   - Métodos de inferencia:
     - Eliminación de variables
     - Eliminación de variables
     - Muestreo de Gibbs
     - Algoritmo de propagación de creencias

#### Aplicaciones Prácticas
  - Robótica: Navegación en entornos desconocidos
  - Finanzas: Modelado de riesgos de mercado
  - Diagnóstico médico: Interpretación de pruebas con incertidumbre

## 2. Problemas de Búsqueda en IA

### 2.1 Componentes Fundamentales

#### 2.1.1 Estado
- **Definición formal**:
  - Representación completa del entorno en un instante dado
  - Codificado como estructura de datos (ej: matriz, grafo, vector)
  
- **Ejemplos avanzados**:
  ```python
    # Representación de estado para 8-puzzle
    estado = {
        'tablero': [[1, 2, 3], [4, 0, 5], [6, 7, 8]],
        'pos_vacía': (1, 1),
        'costo_acumulado': 0
    }
  ```

#### 2.1.2 Acciones
- **Propiedades clave**:
  - **Completitud**: ∀s ∈ S, A(s) ≠ ∅ (siempre existe al menos una acción disponible)
  - **Reversibilidad**: Algunos problemas requieren ∀a ∃a⁻¹ | T(T(s,a),a⁻¹) = s

- **Ejemplo avanzado (15-puzzle)**:
  ```python
   def acciones_15puzzle(estado):
        x, y = estado.pos_vacía
        acciones = []
        if x > 0: acciones.append('arriba')
        if x < 3: acciones.append('abajo')
        if y > 0: acciones.append('izquierda')
        if y < 3: acciones.append('derecha')
        return acciones
  ```

#### 2.1.3 Modelo de Transición (Continuación)

**Propiedades avanzadas**:
- **Consistencia**:  
  Para todo estado `s` y acción `a`, debe cumplirse:  
  `resultado(s,a) ∈ S` (cerradura del espacio de estados)

- **Eficiencia computacional**:  
  La función debe evaluarse en tiempo constante (`O(1)`) para problemas complejos

**Ejemplo formal para el 8-puzzle**:
```python
 def transición_8puzzle(estado, acción):
      nuevo = deepcopy(estado)
      i, j = nuevo.pos_vacía
      if acción == 'arriba' and i > 0:
          nuevo.tablero[i][j], nuevo.tablero[i-1][j] = nuevo.tablero[i-1][j], nuevo.tablero[i][j]
          nuevo.pos_vacía = (i-1, j)
      # Implementar resto de acciones (abajo, izquierda, derecha)
      nuevo.costo_acumulado += 1  # Costo uniforme
      return nuevo
```

#### 2.1.4 Costo de Ruta 
**Análisis de complejidad**:
- **Cálculo del costo mínimo**: `C(s) = minₐ [c(s,a) + C(resultado(s,a))]`
(Ecuación recursiva basada en optimalidad de Bellman)

**Ejemplo implementado**:
```python
 def calcular_costo(ruta):
    costo = 0
    for i in range(len(ruta)-1):
        estado = ruta[i]
        accion = obtener_accion(estado, ruta[i+1])
        costo += estado.costo_accion(accion)
    return costo + heuristica(ruta[-1])  # Para A*
```

#### 2.1.5 Función Heurística (h(n)) (Continuación)

**Implementaciones avanzadas**:
```python
 def heuristica_manhattan(estado, meta):
      distancia = 0
      for valor in range(1, 9):  # Para 8-puzzle
          x_actual, y_actual = encontrar_posicion(estado.tablero, valor)
          x_meta, y_meta = encontrar_posicion(meta.tablero, valor)
          distancia += abs(x_actual - x_meta) + abs(y_actual - y_meta)
      return distancia


  def heuristica_euclidiana(estado, meta):
      distancia = 0
      for valor in range(1, 9):
          x_actual, y_actual = encontrar_posicion(estado.tablero, valor)
          x_meta, y_meta = encontrar_posicion(meta.tablero, valor)
          distancia += math.sqrt((x_actual-x_meta)**2 + (y_actual-y_meta)**2)
      return distancia
```

### 2.2 Clasificación de Problemas de Búsqueda

#### 2.2.1 Por Complejidad del Espacio de Estados
| Tipo                | Características                  | Complejidad Típica   | Ejemplo                 |
|---------------------|----------------------------------|----------------------|-------------------------|
| **Discreto Finito** | Espacio enumerable               | O(b^d)               | 8-puzzle                |
| **Continuo**        | Espacio no numerable             | NP-Hard              | Navegación robótica      |
| **Relacional**      | Estados definidos por predicados | EXPTIME              | Planificación automática |

#### 2.2.2 Por Disponibilidad de Información
1. **Búsqueda No Informada**:
   - Sin conocimiento del dominio
   - Estrategias:
     ```python
       estrategias = {
           'DFS': StackFrontier(),
           'BFS': QueueFrontier(),
           'UCS': PriorityFrontier(costo=True)
       }
     ```

2. **Búsqueda Informada**:
   - Utiliza heurísticas
   - Algoritmos clave:
     - A* (óptimo con h(n) admisible)
     - IDA* (versión iterativa profunda)
     - Beam Search (búsqueda local)

#### 2.2.3 Por Naturaleza de la Solución
- **Óptima Global**:
  `argmin_{π ∈ Π} C(π)`
- **Satisfactorias**:
  - Soluciones dentro de umbral aceptable
  - Ej: Algoritmos voraces

### 2.3 Métricas de Rendimiento
| Métrica               | Fórmula                  | Aplicación           |
|-----------------------|--------------------------|----------------------|
| **Completitud**       | P(solucion) = 1          | Entornos deterministas |
| **Optimalidad**       | C(π) = C*(π)             | Sistemas críticos     |
| **Eficiencia**        | Nodos expandidos/sol     | Comparación algoritmos|

### 2.4 Casos de Estudio Avanzados

#### 2.4.1 Planificación Automática
- **Representación STRIPS**:
  ```python
    class Acción:
        def __init__(self, nombre, precond, efectos):
            self.nombre = nombre
            self.precond = precond
            self.efectos = efectos
  ```

#### 2.4.2 Búsqueda en Espacios Continuos
- **Algoritmo RRT***:
  ```python
     def expandir_rrt(grafo, espacio, meta, ε=0.1):
        q_rand = muestra_aleatoria(espacio)
        q_near = vecino_más_cercano(grafo, q_rand)
        q_new = paso(q_near, q_rand, ε)
        if colisión_libre(q_near, q_new):
            grafo.add_edge(q_near, q_new)
        return grafo
  ```

## 3. Algoritmos de Búsqueda
### DFS vs. BFS:
| **Criterio**       | **DFS**               | **BFS**               |
|--------------------|-----------------------|-----------------------|
| Optimalidad        | No garantizada        | Sí (costo uniforme)   |
| Complejidad espacial | O(bm)                | O(b^d)                |

### A* (A Estrella):
- **Función de evaluación**: `f(n) = g(n) + h(n)`.
  - `g(n)`: Costo real desde inicio.
  - `h(n)`: Heurística admisible (ej: distancia Manhattan).
- **Teorema de optimalidad**:  
  Si `h(n)` es admisible, A* encuentra la solución óptima.

## 4. Búsqueda Adversarial (Minimax)
### Pseudocódigo:
```python
def minimax(estado, profundidad, maximizando):
    if estado_terminal(estado) or profundidad == 0:
        return evaluar(estado)
    if maximizando:
        return max(minimax(sucesor, profundidad-1, False) for sucesor en sucesores(estado))
    else:
        return min(minimax(sucesor, profundidad-1, True) for sucesor en sucesores(estado))
```
### Poda Alfa-Beta:
- **Condición de poda**:  
  Si `α ≥ β`, descarta subárbol.
- **Mejor caso**: Reduce complejidad a `O(b^(d/2))`.

## 5. Demostraciones Técnicas
### Optimalidad de A*:
1. Sea `C*` costo óptimo al objetivo.
2. Para todo nodo `n` en frontera:  
   `f(n) = g(n) + h(n) ≤ C*` (por admisibilidad).
3. A* expande nodos en orden de `f(n)` → primer objetivo alcanzado es óptimo.

### Consistencia en Heurísticas:
- **Definición**:  
  `h(n) ≤ c(n, n') + h(n')` para todo `n'` sucesor de `n`.
- **Implicación**:  
  Garantiza que `f(n)` sea no decreciente en cualquier trayectoria.

## 6. Aplicaciones Críticas
- **Google Maps**: A* con heurística de tiempo real.
- **DeepBlue (Ajedrez)**: Minimax + poda alfa-beta + evaluación de 8M posiciones/segundo.
