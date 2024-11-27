<?php
echo "<h2>Gestión de Inventario con Bucles</h2>";

// Array de productos en inventario
$inventario = [
    ["nombre" => "Manzanas", "cantidad" => 50],
    ["nombre" => "Naranjas", "cantidad" => 30],
    ["nombre" => "Plátanos", "cantidad" => 20],
    ["nombre" => "Uvas", "cantidad" => 15]
];

// Variable para el control del menú
$opcion = 0;

do {
    // Mostrar menú de opciones
    echo "Menú de Opciones:\n";
    echo "1. Ver Inventario\n";
    echo "2. Vender Producto\n";
    echo "3. Salir\n";

    // Leer opción del usuario
    $opcion = readline("Selecciona una opción (1-3): ");

    if ($opcion == 1) {
        // Mostrar inventario actual
        echo "\nInventario Actual:\n";
        foreach ($inventario as $producto) {
            echo $producto["nombre"] . ": " . $producto["cantidad"] . " unidades\n";
        }
        echo "\n";
    } elseif ($opcion == 2) {
        // Procesar venta de producto
        $productoBuscado = readline("Introduce el nombre del producto: ");
        $cantidadVendida = (int) readline("Introduce la cantidad a vender: ");

        // Buscar producto en inventario
        $encontrado = false;
        for ($i = 0; $i < count($inventario); $i++) {
            if (strtolower($inventario[$i]["nombre"]) == strtolower($productoBuscado)) {
                $encontrado = true;

                // Verificar si hay suficiente cantidad
                if ($inventario[$i]["cantidad"] >= $cantidadVendida) {
                    $inventario[$i]["cantidad"] -= $cantidadVendida;
                    echo "\nVenta exitosa: $cantidadVendida unidades de " . $inventario[$i]["nombre"] . " vendidas.\n";
                } else {
                    echo "\nError: No hay suficiente cantidad en inventario.\n";
                }

                break;
            }
        }

        if (!$encontrado) {
            echo "\nError: Producto no encontrado en el inventario.\n";
        }
    } elseif ($opcion == 3) {
        // Salir del sistema
        echo "\nSaliendo del sistema...\n";
    } else {
        echo "\nOpción no válida. Por favor, selecciona una opción válida.\n";
    }

    echo "\n";
} while ($opcion != 3);

?>
