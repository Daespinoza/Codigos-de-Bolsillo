let workbook; // Variable global para almacenar el archivo Excel cargado

// 1. Leer un archivo Excel
document.getElementById('fileInput').addEventListener('change', function (e) {
    const file = e.target.files[0];
    if (!file) return;

    const reader = new FileReader();
    reader.onload = function (e) {
        const data = new Uint8Array(e.target.result);
        workbook = XLSX.read(data, { type: 'array' });
        mostrarDatos(workbook);
    };
    reader.readAsArrayBuffer(file);
});

// Función para mostrar los datos en la página
function mostrarDatos(workbook) {
    const sheetName = workbook.SheetNames[0]; // Obtener la primera hoja
    const sheet = workbook.Sheets[sheetName];
    const jsonData = XLSX.utils.sheet_to_json(sheet, { header: 1 });

    document.getElementById('dataOutput').textContent = JSON.stringify(jsonData, null, 2);
}

// 2. Modificar los datos
document.getElementById('modifyBtn').addEventListener('click', function () {
    if (!workbook) {
        alert('Primero carga un archivo Excel.');
        return;
    }

    const sheetName = workbook.SheetNames[0];
    const sheet = workbook.Sheets[sheetName];

    // Convertir la hoja a JSON para modificar los datos
    const jsonData = XLSX.utils.sheet_to_json(sheet, { header: 1 });

    // Ejemplo: Agregar una nueva fila
    jsonData.push(['Nuevo Nombre', 'nuevo@email.com', '123456789']);

    // Convertir el JSON modificado de vuelta a una hoja de Excel
    const modifiedSheet = XLSX.utils.aoa_to_sheet(jsonData);
    workbook.Sheets[sheetName] = modifiedSheet;

    mostrarDatos(workbook); // Mostrar los datos modificados
    alert('Datos modificados correctamente.');
});

// 3. Exportar a un nuevo archivo Excel
document.getElementById('exportBtn').addEventListener('click', function () {
    if (!workbook) {
        alert('No hay datos para exportar.');
        return;
    }

    // Crear un nuevo archivo Excel
    const newFile = XLSX.write(workbook, { bookType: 'xlsx', type: 'binary' });

    // Convertir a un Blob y descargar
    const blob = new Blob([s2ab(newFile)], { type: 'application/octet-stream' });
    const url = URL.createObjectURL(blob);
    const a = document.createElement('a');
    a.href = url;
    a.download = 'archivo_modificado.xlsx';
    a.click();
    URL.revokeObjectURL(url);
});

// Función auxiliar para convertir un string a ArrayBuffer
function s2ab(s) {
    const buf = new ArrayBuffer(s.length);
    const view = new Uint8Array(buf);
    for (let i = 0; i < s.length; i++) view[i] = s.charCodeAt(i) & 0xff;
    return buf;
}