<?php 

echo "<h1>Operadores en PHP</h1>";

// 1. Operadores Aritméticos
echo "<h2>1. Operadores Aritméticos</h2>";
$a = 10;
$b = 3;

echo "Suma: \$a + \$b = " . ($a + $b) . "<br>";
echo "Resta: \$a - \$b = " . ($a - $b) . "<br>";
echo "Multiplicación: \$a * \$b = " . ($a * $b) . "<br>";
echo "División: \$a / \$b = " . ($a / $b) . "<br>";
echo "Módulo: \$a % \$b = " . ($a % $b) . "<br>";
echo "Exponenciación: \$a ** \$b = " . ($a ** $b) . "<br>";

// 2. Operadores de Incremento y Decremento
echo "<h2>2. Operadores de Incremento y Decremento</h2>";
$x = 5;

echo "Valor inicial de \$x: $x<br>";
echo "Pre-incremento: ++\$x = " . (++$x) . "<br>";
echo "Post-incremento: \$x++ = " . ($x++) . " (después: $x)<br>";
echo "Pre-decremento: --\$x = " . (--$x) . "<br>";
echo "Post-decremento: \$x-- = " . ($x--) . " (después: $x)<br>";

// 3. Operadores de Asignación
echo "<h2>3. Operadores de Asignación</h2>";
$y = 10;

echo "Valor inicial de \$y: $y<br>";
$y += 5;
echo "Suma y asigna (\$y += 5): $y<br>";
$y -= 3;
echo "Resta y asigna (\$y -= 3): $y<br>";
$y *= 2;
echo "Multiplica y asigna (\$y *= 2): $y<br>";
$y /= 4;
echo "Divide y asigna (\$y /= 4): $y<br>";
$y %= 3;
echo "Módulo y asigna (\$y %= 3): $y<br>";

// 4. Operadores de Comparación
echo "<h2>4. Operadores de Comparación</h2>";
$m = 5;
$n = "5";

echo "Igualdad (\$m == \$n): " . ($m == $n ? "true" : "false") . "<br>";
echo "Identidad (\$m === \$n): " . ($m === $n ? "true" : "false") . "<br>";
echo "Diferente (\$m != \$n): " . ($m != $n ? "true" : "false") . "<br>";
echo "No idéntico (\$m !== \$n): " . ($m !== $n ? "true" : "false") . "<br>";
echo "Mayor que (\$m > 4): " . ($m > 4 ? "true" : "false") . "<br>";
echo "Menor que (\$m < 10): " . ($m < 10 ? "true" : "false") . "<br>";
echo "Mayor o igual que (\$m >= 5): " . ($m >= 5 ? "true" : "false") . "<br>";
echo "Menor o igual que (\$m <= 5): " . ($m <= 5 ? "true" : "false") . "<br>";

// 5. Operadores Lógicos
echo "<h2>5. Operadores Lógicos</h2>";
$p = true;
$q = false;

echo "AND (\$p && \$q): " . ($p && $q ? "true" : "false") . "<br>";
echo "OR (\$p || \$q): " . ($p || $q ? "true" : "false") . "<br>";
echo "NOT (!\$p): " . (!$p ? "true" : "false") . "<br>";
echo "XOR (\$p xor \$q): " . ((($p xor $q) ? "true" : "false")) . "<br>";

?>
