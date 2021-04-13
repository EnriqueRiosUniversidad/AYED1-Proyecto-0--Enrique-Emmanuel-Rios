/*
Este Ejercicio fue hecho por Enrique Emmanuel Rios Chyrnia, 
Canal de Yooutube: Enrique Rios
Su copia y/o edicion esta permitida bajo la condicion de dar credito a mi canal 
de Youtube (Ademas de dejar un link directo a mi canal Enrique Rios).
*/

/*Adivina un numero E[0 ;1 millon]  imaginado por el usuario.*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
int intentos = 0; //Variable global, numero de intentos.

/*Es super ordenado, legible y lindo. Enrique Emmanuel Rios Chyrnia.*/
int dividir(int numero) { //Divide numeros pares e impares, en el segundo caso lo combierte en par.
	int resto = (numero % 2);
	if ( resto == 0) {
		return (numero / 2);
	}
	else {
		return (numero + 1) / 2;
	};
	
}

//Descomenta para ejecurtar  el main
/*
int main()
{	//La cantidad de variables es para una asimilacion directa
	//la base es el menor valor posible.
	//El techo es el valor posible más alto.
	//Basura se encarga de capturar los /n cuando se usa scanf_s();
	int base  = 0, techo = 1000000;
	int rango[] = { base, techo};
	int temp = 0;
	char respuesta = 'n';
	char basura;

	printf("Imagine un numero entre 1.000.000 y 0\n  Se le preguntara si es mayor a tal numero");
	printf("\n y debera respondar con 'y' or 'n', en caso de que se le pregunte si este es su numero \n");
	printf("responda con 'c' de correcto\n");
	
	while (respuesta != 'c') {
	
		temp = base  + dividir(techo - base); //Ej base= 500, techo = 1000.  temp = 500 + 250 -> 750.
		
		printf("\n  -->El numero es mayor a {%i} y/n Si este es el numero adivinado, pon 'c'-->", temp); //numero > 750 or is 750.
		scanf_s("%c", &respuesta);

		switch(respuesta) {
			case 'y':
				base = temp;
				rango[0] = base;
				break;
			case 'n':
				techo = techo - dividir(techo - base); // 1.000.000- 500.000 = 500...
				rango[1] = techo;
				break;
			default:

				break;
		};
		

		//----------Esto permite llevar registro de la base y el techo-----------
		//printf("\ntecho: %i", techo);
		//printf("\nbase : %i", base);


		scanf_s("%c", &basura);//Captura el \n.
		intentos = intentos + 1;

	};

	printf("\n --------> Numero de intentos --> [ %i ]", intentos);
	return 0;
	
}

*/

