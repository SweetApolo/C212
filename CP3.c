//Preprocesador con las librerias necesarias
#define Pro(numeroDatos, valoresDatos) valoresDatos/numeroDatos //Definimos la funcion para el Promedio 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int size = 20; //Definir tamaño

int main(){
    FILE *fuente = fopen("numeross.txt", "r" /*r = abrir un archivo solo para leerlo */); //Flujo para acceder al archivo donde tenemos los numeros (LECTURA 15)
    //Uso del codigo TOKEN que nos dio el profe Franco
    char numeros[size]; //Arreglo char con el size
    fgets(numeros, size, fuente); //Los numeros del archivo van a ser los valores del arreglo
    char *token = strtok(numeros, " "); //Espacio para dividir el arreglo
    int *arr = malloc(sizeof(int) * size); //Arreglo en memoria dinamica
    int numeroDatos = 0; //Numeros que tiene el archivo de numeros.txt (6)

    while (token != NULL){
        sscanf(token, "%d", &arr[numeroDatos]); //Utilizando el ejercicio 6 (Caracteres a numeros)
        token = strtok(NULL, " ");
        numeroDatos++;
    }
    
    //Funciones Maximo Minimo y Promedio

    //Rango MAX y MIN de una variable tipo int
    int MAX = -32768;
    int MIN = 32767;

    //Promedio
    float TOT; //Sumatoria del valor de los numeros en el archivo

    //Funcion Maximo y pasamos la direccion de memoria del arreglo 
    for(int i = 0; i < numeroDatos; i++){
        if(arr[i] > MAX){
            MAX = arr[i];
        }
    }

    //Funcion Minimo y pasamos la direccion de memoria del arreglo 
    for(int i = 0; i < numeroDatos; i++){
        if(arr[i] < MIN){
            MIN = arr[i];
        }
    }

    //Funcion Promedio y pasamos la direccion de memoria del arreglo
    for(int i = 0; i < numeroDatos; i++){
        TOT += arr[i];
    }
    float PRO = Pro(numeroDatos, TOT); //Flotante por que el promedio puede tener decimales

    //Creacion del archivo de salida con los resultados
    FILE *MAXMINPRO = fopen("./MAXMINPRO.out", "w"/*w = Crear el archivo*/); //Flujo para crear el archivo de salida(LECTURA 15)
    fprintf(MAXMINPRO, "MAX= %i, MIN= %i, PRO= %.1f", MAX, MIN, PRO);

}