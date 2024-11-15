<?php
// 1. Superglobal $_GET
// Suponiendo que tengas una URL como: example.php?nombre=Juan&edad=25
if (isset($_GET['nombre']) && isset($_GET['edad'])) {
    $nombre = $_GET['nombre'];
    $edad = $_GET['edad'];
    echo "<h3>GET: Hola, mi nombre es $nombre y tengo $edad años.</h3>";
} else {
    echo "<h3>GET: No se han recibido parámetros en la URL.</h3>";
}

// 2. Superglobal $_POST
// Asegúrate de tener un formulario con método POST para que funcione
echo "<hr><h3>POST: Recibido desde formulario (si lo enviaste):</h3>";
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    $email = $_POST['email'] ?? "No se proporcionó email.";
    echo "Email recibido: $email";
} else {
    echo '<form method="POST" action="">
            <label for="email">Correo Electrónico: </label>
            <input type="email" name="email" id="email" required>
            <input type="submit" value="Enviar">
          </form>';
}

// 3. Superglobal $_SESSION
session_start(); // Iniciar la sesión
if (!isset($_SESSION['contador'])) {
    $_SESSION['contador'] = 1;
} else {
    $_SESSION['contador']++;
}

echo "<hr><h3>SESSION: Contador de visitas: " . $_SESSION['contador'] . "</h3>";

// 4. Superglobal $_COOKIE
if (!isset($_COOKIE['usuario'])) {
    setcookie("usuario", "Juan", time() + 3600); // Expira en 1 hora
    echo "<hr><h3>COOKIE: Cookie 'usuario' ha sido creada.</h3>";
} else {
    echo "<hr><h3>COOKIE: Hola " . $_COOKIE['usuario'] . ". ¡Bienvenido de nuevo!</h3>";
}

// 5. Superglobal $_FILES
// Asegúrate de tener un formulario con método POST y tipo de archivo `multipart/form-data` para que funcione
echo "<hr><h3>FILES: Subida de archivo:</h3>";
if (isset($_FILES['archivo'])) {
    $archivoNombre = $_FILES['archivo']['name'];
    $archivoTmp = $_FILES['archivo']['tmp_name'];
    echo "Archivo recibido: $archivoNombre";
    // Mover archivo a un directorio (por ejemplo, 'uploads/')
    if (move_uploaded_file($archivoTmp, "uploads/" . $archivoNombre)) {
        echo "<br>El archivo fue subido exitosamente.";
    } else {
        echo "<br>Error al subir el archivo.";
    }
} else {
    echo '<form method="POST" enctype="multipart/form-data">
            <label for="archivo">Selecciona un archivo para subir: </label>
            <input type="file" name="archivo" id="archivo" required>
            <input type="submit" value="Subir archivo">
          </form>';
}

// 6. Superglobal $_SERVER
echo "<hr><h3>SERVER: Información del servidor:</h3>";
echo "Servidor: " . $_SERVER['SERVER_NAME'] . "<br>";
echo "Dirección IP del servidor: " . $_SERVER['SERVER_ADDR'] . "<br>";
echo "Nombre del script: " . $_SERVER['SCRIPT_NAME'] . "<br>";
echo "Método de la solicitud HTTP: " . $_SERVER['REQUEST_METHOD'] . "<br>";
?>
