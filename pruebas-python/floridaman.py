import requests
from bs4 import BeautifulSoup
import pandas as pd
import os

# Función para buscar titulares y enlaces en Google News
def buscar_titulares_y_enlaces(query):
    url = f"https://news.google.com/search?q={query}"
    headers = {"User-Agent": "Mozilla/5.0"}
    titulares_y_enlaces = []

    try:
        response = requests.get(url, headers=headers)
        if response.status_code == 200:
            soup = BeautifulSoup(response.text, "html.parser")
            for item in soup.find_all('a', href=True):
                href = item['href']
                if href.startswith('/articles'):
                    titulo = item.get_text()
                    enlace = f"https://news.google.com{href[1:]}"
                    titulares_y_enlaces.append({"titulo": titulo, "enlace": enlace})
        else:
            print(f"Error al acceder a {url}: Código de estado {response.status_code}")
    except Exception as e:
        print(f"Error al acceder a {url}: {e}")

    return titulares_y_enlaces

# Función principal
def main():
    query = "Florida Man"
    titulares_y_enlaces = buscar_titulares_y_enlaces(query)

    # Nombre del archivo Excel
    nombre_archivo = "titulares_florida_man.xlsx"

    # Crear un DataFrame y guardar en Excel
    if titulares_y_enlaces:
        df = pd.DataFrame(titulares_y_enlaces)
        df.to_excel(nombre_archivo, index=False)
        print(f"Titulares y enlaces guardados en {nombre_archivo}")
    else:
        print("No se encontraron titulares.")

if __name__ == "__main__":
    main()
