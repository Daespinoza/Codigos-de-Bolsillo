// Alertas
// alert("hola soy Victor Robles WEB");

// Variables
let nombre = "David Espinoza"
nombre = "David Espinoza web"

// Mostrar por consola
console.log(nombre);

// Constantes
// las constantes no se pueden actualizar
const altura = 187;

console.log(altura);

let concetenacion = nombre + " : " + altura;

// Seleccionar elemetos de la pagina
let datos = document.querySelector("#datos");
datos.innerHTML = `
    <hr/>
    <h1> Soy la caja de datos</h1>
    <h2>Mi nombre es: ${nombre} </h2>
`

// condiciones
if(altura >= 185){
    datos.innerHTML += "<h1> Eres una persoa alta </h1>";
}
else{
    datos.innerHTML += "<h1> Eres una persona baja </h1>";
}

//bucles
for(let year = 2000; year <= 2023; year++){
    datos.innerHTML += `<h2>Estamos en el anno: ${year}</h2>`
}

// arrays
let nombres = ["Victor", "Francisco", "Pepe"];

let divNombres = document.querySelector("#nombres");

divNombres.innerHTML = nombres[0];

divNombres.innerHTML = "<h1>Listado de nombres</h1><ul>";

nombres.forEach(nombre => {
    divNombres.innerHTML += "<li>" + nombre +"<li>";
});

divNombres.innerHTML += "</ul>"

// funciones

const miInformacion = (nombre, altura) => {
    let misDatos = `
        <hr/>
        <h1> Soy la caja de datos</h1>
        <h2>Mi nombre es: ${nombre} </h2>
        <h2>Mi nombre es: ${altura} </h2>
    `
    return misDatos;
}