<?php
// Ejemplo con if, else if, y operadores de comparación
$edad = 25;

echo "<h2>Condicionales con if, else if, y else</h2>";

if ($edad < 18) {
    echo "Eres menor de edad. No puedes acceder.<br>";
} elseif ($edad >= 18 && $edad < 60) {
    echo "Eres adulto. Bienvenido al sistema.<br>";
} else {
    echo "Eres mayor de 60. Tienes beneficios especiales.<br>";
}

// Operadores lógicos combinados con operadores de comparación
echo "<h2>Operadores lógicos</h2>";

$usuarioActivo = true;
$esAdmin = false;

if ($usuarioActivo && $esAdmin) {
    echo "Tienes acceso completo como administrador.<br>";
} elseif ($usuarioActivo && !$esAdmin) {
    echo "Tienes acceso limitado como usuario.<br>";
} else {
    echo "Tu cuenta está inactiva. Contacta al soporte.<br>";
}

// Ejemplo con switch
echo "<h2>Condicional con switch</h2>";

$opcionMenu = "B";

switch ($opcionMenu) {
    case "A":
        echo "Has seleccionado la opción A: Ver perfil.<br>";
        break;
    case "B":
        echo "Has seleccionado la opción B: Configuración.<br>";
        break;
    case "C":
        echo "Has seleccionado la opción C: Cerrar sesión.<br>";
        break;
    default:
        echo "Opción no válida. Por favor, elige A, B o C.<br>";
        break;
}

// Ejemplo con goto
echo "<h2>Ejemplo con goto</h2>";

$salto = 2;
if ($salto == 1) {
    goto salto1;
} elseif ($salto == 2) {
    goto salto2;
}

echo "Esta línea nunca se ejecutará si usas goto.<br>";

salto1:
echo "Saltaste a la etiqueta salto1.<br>";
goto fin; // Salta al final del script para evitar ejecutar lo siguiente

salto2:
echo "Saltaste a la etiqueta salto2.<br>";

fin:
echo "Has llegado al final del script.<br>";

?>
