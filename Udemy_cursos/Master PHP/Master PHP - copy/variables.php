<?php 

// Ejemplo de uso de diferentes tipos de variables en PHP

// 1. Variables de tipo string
$cadena = "Hola, mundo";
echo "<h2>Ejemplo de String</h2>";
echo "Esto es una cadena: $cadena<br>";
echo "Longitud de la cadena: " . strlen($cadena) . "<br>";
echo "Cadena en mayúsculas: " . strtoupper($cadena) . "<br><hr>";

// 2. Variables de tipo entero
$entero = 42;
echo "<h2>Ejemplo de Entero</h2>";
echo "Esto es un entero: $entero<br>";
echo "Es número? " . (is_int($entero) ? "Sí" : "No") . "<br>";
echo "Suma: " . ($entero + 8) . "<br><hr>";

// 3. Variables de tipo flotante
$flotante = 3.1416;
echo "<h2>Ejemplo de Flotante</h2>";
echo "Esto es un flotante: $flotante<br>";
echo "Es flotante? " . (is_float($flotante) ? "Sí" : "No") . "<br>";
echo "Redondeado: " . round($flotante, 2) . "<br><hr>";

// 4. Variables de tipo booleano
$verdadero = true;
echo "<h2>Ejemplo de Booleano</h2>";
echo "Esto es un booleano: " . ($verdadero ? "Verdadero" : "Falso") . "<br>";
echo "Negación: " . (!$verdadero ? "Verdadero" : "Falso") . "<br><hr>";

// 5. Variables de tipo NULL
$nulo = null;
echo "<h2>Ejemplo de NULL</h2>";
echo "Valor nulo: " . var_export($nulo, true) . "<br>";
echo "¿Es NULL? " . (is_null($nulo) ? "Sí" : "No") . "<br><hr>";

// 6. Variables tipo Array
$array = ["PHP", "JavaScript", "Python"];
echo "<h2>Ejemplo de Array</h2>";
echo "Contenido del array:<br>";
foreach ($array as $indice => $valor) {
    echo "Índice $indice: $valor<br>";
}
echo "Longitud del array: " . count($array) . "<br>";
array_push($array, "Java"); // Agregar un elemento
echo "Nuevo contenido del array:<br>";
print_r($array);
echo "<br><hr>";

// 7. Variables tipo Objeto
class Persona {
    public $nombre;
    public $edad;

    public function __construct($nombre, $edad) {
        $this->nombre = $nombre;
        $this->edad = $edad;
    }

    public function saludar() {
        return "Hola, mi nombre es $this->nombre y tengo $this->edad años.";
    }
}

$persona = new Persona("David", 30);
echo "<h2>Ejemplo de Objeto</h2>";
echo $persona->saludar() . "<br><hr>";

// 8. Variables de tipo Resource
echo "<h2>Ejemplo de Resource</h2>";
$archivo = fopen("archivo_ejemplo.txt", "w");
if ($archivo) {
    fwrite($archivo, "Esto es un ejemplo de resource en PHP.\n");
    fclose($archivo);
    echo "Archivo creado y cerrado correctamente.<br>";
} else {
    echo "No se pudo abrir el archivo.<br>";
}
echo "<hr>";

?>
