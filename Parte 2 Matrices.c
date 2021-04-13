#include <conio.h>
#include <stdio.h> 
#include <stdlib.h> 

// Declaraciones de funciones.
int getNumero(int min, int max);
int** crear_Matriz(int n);
void cargar_matriz(int** matriz, int n);
void imprimir_matriz(int** matriz, int n);
void imprimir_dos_matrices(int** matriz_A, int** matriz_B, int n);
void suma(int** matriz_A, int*** matriz_B, int n);
void resta(int** matriz_A, int** matriz_B, int n);
void producto(int** matriz_A, int** matriz_B, int n);
int suma_elementos_del_array(int* array, int n);

// Función main

int main(){
    srand(getpid()); //obtiene el id del proceso del programa y se lo pasa a srand
    char basura;
    int n=0;
    printf("\n--Introduzca el tamaño de las matrices, N*N \n-->  ");
    scanf_s("%i", &n);
    scanf_s("%c", &basura); //Elimina cualquier \n


    //--------Creacion de matrices-------//
    int** Matriz_A = crear_Matriz(n);
    cargar_matriz(Matriz_A,n);
    int** Matriz_B= crear_Matriz(n);
    cargar_matriz(Matriz_B, n);
  
    imprimir_dos_matrices(Matriz_A, Matriz_B, n);
    
    //---------Operaciones--------------//
    suma(Matriz_A, Matriz_B, n);
    resta(Matriz_A, Matriz_B, n);
    producto(Matriz_A, Matriz_B, n);
    
    
    
}


/*Este funcion crea una matriz de tamaño N por N. 
Osease un puntero de punteros enteros.*/
int** crear_Matriz(int n) {
    int** matriz;
    matriz = malloc(n * sizeof(int *)); //Array de punteros. Array del tamaño de un puntero int.
    for (int i = 0; i < n; i++) {//Cargamos un array de punteros tamaño (N*int) en cada fila.
        matriz[i] = calloc(n,sizeof(int)); //columna del tamaño de N objetos enteros.
    };
    return matriz;
}

// Esta funcion calcula un numero aleatorio en un rango dado.
int getNumero(int min, int max){
    int temp = (RAND_MAX / (max - min + 1) + 1);
   return min + rand() / temp;
}

//Carga valores en un array de tamaño N * N
void cargar_matriz(int** matriz, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz[i][j] = getNumero(0 , 10);
        }
    }
}
//Imprime la linda matriz.
void imprimir_matriz(int** matriz,int n) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("  %i  ",matriz[i][j]);
        }
        printf("\n");
    }
}

//Imprime dos matrices.
void imprimir_dos_matrices(int** matriz_A,int**matriz_B, int n) {
    printf("\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("  %i  ", matriz_A[i][j]);
        }
        printf("<---------------------->");

        for (int j = 0; j < n; j++) {
            printf("  %i  ", matriz_B[i][j]);
        }
        printf("\n");

    }
}


//Suma de matrices//
void suma(int** matriz_A, int** matriz_B, int n) {
    int** matriz_C = crear_Matriz(n);
    cargar_matriz(matriz_C, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz_C[i][j] = matriz_A[i][j] + matriz_B[i][j];
        }
        printf("\n");
    }
    printf("-----------La suma de matrices es: -------\n");
    imprimir_matriz(matriz_C,n);
    
}

//resta 2 matrices.
void resta(int** matriz_A, int** matriz_B, int n) {
    int** matriz_C = crear_Matriz(n);
   // cargar_matriz(matriz_C, n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            matriz_C[i][j] = matriz_A[i][j] - matriz_B[i][j];
        }
        printf("\n");
    }
    printf("-----------La resta de matrices es: -------\n");
    imprimir_matriz(matriz_C, n);

}

/*Les contare una historia, esta historia es la de un programador que demoro un par de horas
creando la representacion algoritmica de un producto matricial.
El joven programador dio vueltas y vueltas al codigo sin conseguir mejora.
Se fui a saltar la cuentar por 8 minutos y tomo una merecida ducha.
Se sento encontes frente a su computadora y buzo en Deezer una playList de FingerStyle
Luego se le vino por la mente, ¿Y si borro todo y comienzo de nuevo?
Asi lo hizo, luego escribio el codigo que tanto habia masticado
la compilacion fue buena y ejecuto el codigo, para el agrado del lector nuestro amigo
Consiguio lo que busco.*/
void producto(int** matriz_A, int** matriz_B, int n) { //n tamaño del cada lado de la matriz.
    int* temp_array = calloc(n, sizeof(int)); //Array donde van las sumas.
    int** matriz_C = crear_Matriz(n);
    int columna = 0;
    int temp;
    cargar_matriz(matriz_C, n);

    for (int i = 0; i < n; i++) {
        //temp_array[j]= matriz_A[i][j] * matriz_B[j][i];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                temp_array[j] = matriz_A[i][j] * matriz_B[j][i];
            }
            matriz_C[i][columna] = suma_elementos_del_array(temp_array, n);
            columna + 1;
            if (columna == n) { columna = 0; }
        }
        
        
    }

    printf("-----------Suuper miltiplicaciones!!! -------\n");
    imprimir_matriz(matriz_C, n);

}


/*Suma todos los elementos de un array*/
int suma_elementos_del_array(int* array, int n) {
    int temp_suma = 0;
    for (int i = 0; i < n; i++) {
        temp_suma += array[i];
    }

    return temp_suma;
}