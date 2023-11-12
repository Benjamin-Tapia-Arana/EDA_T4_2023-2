# README TAREA 4: Árboles balanceados

**Integrantes**
- Benjamin A. Tapia Arana
- Tomás F. Aspee Carrasco

## Estructura del Proyecto

El proyecto consta de los siguientes directorios:

- **build**: Carpeta donde se generará el ejecutable (debe crearse)
- **include**: Carpeta donde se encuentran todos los archivos HPP, algunos en subcarpetas
- **src**: Carpeta donde se encuentran todos los archivos CPP necesarios para el maze
- **test**: Carpeta donde se encuentra el archivo CPP para testear el funcionamiento de la calculadora
- **test_files**: Carpeta donde se encuentran los archivos de prueba para el test, solo consta de archivos `TXT` que contienen los datos a insertar o buscar en los árboles. No se incluyen los archivos `TXT` que contienen los resultados esperados, ya que estos se generan al ejecutar el test.

## Compilación

Pasos para compilar el proyecto:

1. Asegurece de tener instalado el compilador `g++` y la herramienta `CMake` en su sistema

2. Cree la carpeta `build` en el directorio principal del proyecto

3. Desde el directorio `build` ejecute el siguiente comando `cmake ..`
   
4. Compile el proyecto con `make`


## Ejecución

Una vez compilado el proyecto, puede ejecutar el programa con el siguiente comando: `./test`

## Uso

El uso de este programa es simple, basta con ejecutarlo para que se ejecuten todos los test necesarios, arrojando los resultados en la terminal. Es posible que la carpeta `test_files` no se encuentre en el directorio principal del proyecto, esto no es un problema, ya que el programa la creará automáticamente al ejecutarse, de la misma forma que creará los archivos `TXT` que contienen los resultados esperados. Estos últimos se generan aleatoriamente cada vez que se ejecuta el programa, por lo que no es necesario incluirlos en el repositorio.