<?php 

// 1. Definiendo constantes
define("PI", 3.1416);
const GRAVITY = 9.8;

echo "<h2>Ejemplo de Constantes Definidas</h2>";
echo "El valor de PI es: " . PI . "<br>";
echo "El valor de la gravedad es: " . GRAVITY . "<br>";

// Uso práctico: Área de un círculo
$radio = 5;
$area = PI * ($radio ** 2);
echo "El área de un círculo con radio $radio es: $area<br><hr>";

// 2. Constantes predefinidas en PHP
echo "<h2>Ejemplo de Constantes Predefinidas</h2>";
echo "Versión de PHP: " . PHP_VERSION . "<br>";
echo "Sistema operativo: " . PHP_OS . "<br>";
echo "Directorio actual: " . __DIR__ . "<br>";
echo "Nombre del archivo actual: " . __FILE__ . "<br>";
echo "Número de línea: " . __LINE__ . "<br><hr>";

// 3. Funciones útiles para constantes
echo "<h2>Funciones útiles para constantes</h2>";

// Comprobar si una constante está definida
if (defined("PI")) {
    echo "La constante 'PI' está definida y su valor es: " . PI . "<br>";
}

// Obtener todas las constantes definidas
$constantes_definidas = get_defined_constants(true);
echo "Algunas constantes definidas por el usuario:<br>";
print_r($constantes_definidas["user"]);
echo "<br><hr>";

// 4. Uso práctico: Configuración global
define("DB_HOST", "localhost");
define("DB_USER", "root");
define("DB_PASSWORD", "password");

echo "<h2>Uso práctico: Configuración de base de datos</h2>";
echo "Conectando a la base de datos en " . DB_HOST . " con el usuario " . DB_USER . "<br>";
// Aquí iría la lógica para conectar a la base de datos usando estas constantes
?>

