//*****************************************************************
//ALGORITMO:  ARBOL DE BUSQUEDA BINARIO
//Autor: Victor Hugo Rios Rebollar
//Escuela Superior de Computo-IPN
//Fecha: 25/03/2021
//Compilacion: "gcc abb.c tiempo.c -o abb"(LINUX)
//Ejecucion: "./abb n"(LINUX)
//Ejecucion shell: ./abb.sh(LINUX)
//*****************************************************************

//*****************************************************************
//LIBRERIAS INCLUIDAS
//*****************************************************************
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//*****************************************************************
//DEFINICION DE CONSTANTES DEL PROGRAMA
#define REGISTROS 10000000
#define LIMITE 50 // limite de caracteres leidos por linea del archivo de 10 millones de numeros
//*****************************************************************
//*****************************************************************
//DEFINICION DE FUNCIONES DEL PROGRAMA

//funcion para buscar, regresa 0 si no lo encontro, 1 si si lo encontro
int buscar (int arreglo[], int num, int n){ //recibe arreglo 
	for(int i=0; i<n; i++){
	//printf("%d",arreglo[i]);
		if(arreglo[i]==num){
			return num;
			}
	}
}

int main(int argc, char *argv[]){
	
	double utime0, stime0, wtime0, utime1, stime1, wtime1;  //Variables para medicion de tiempos
	FILE* fichero; 										    //puntero a fichero
	char cadena[LIMITE];                                    //cadena auxiiar para leer linea a linea los registros del archivo
	fichero = fopen("numeros10millones.txt", "rt");         //apertura del archivo de 10 millones
	int *numeros;  											//variable apuntador para reservar memoria
	int n,i;
	int arreglo2[20] = {322486, 14700764, 3128036, 6337399, 61396, 10393545, 2147445644, 1295390003, 450057883, 187645041, 1980098116, 152503, 5000, 1493283650, 214826, 1843349527, 1360839354, 2109248666 , 2147470852, 0};
	int impr;
	//******************************************************************
	//Recepcion y decodificacion de argumentos
	//******************************************************************

	//Si no se introducen exactamente 2 argumentos (Cadena de ejecucion y cadena=n)
	if (argc != 2)
	{
		printf("\nIndique el tamanio del algoritmo - Ejemplo: [user@equipo]$ %s 100\n", argv[0]);
		exit(1);
	}
	
	//Tomar el segundo argumento como tamaÃ±o del algoritmo
	n = atoi(argv[1]);
	numeros=(int*)malloc(n*sizeof(int));
	
	if(numeros!=NULL){
		for(i=0;i<n;i++){//realiza las iteraciones hasta n veces ingresado como parametro del programa en la ejecucion
			fgets (cadena,LIMITE, fichero);//lectura linea a linea del archivo txt
			*(numeros+i)=atoi(cadena); //asignacion de la variable temporal cadena a las posiciones del arreglo
		}
	}else
		exit(1);
			

    //******************************************************************
	//Iniciar el conteo del tiempo para las evaluaciones de rendimiento
	//******************************************************************
	uswtime(&utime0, &stime0, &wtime0);
	
	//******************************************************************
	//Algoritmo
	//******************************************************************
	for(i=0; i<20; i++){
        impr = buscar(numeros, arreglo2[i], n);		
		if (impr==arreglo2[i]){
			printf("Encontrado: %d\n",impr);
			
			uswtime(&utime1, &stime1, &wtime1);	
			//Calculo del tiempo de ejecucion del programa
			printf("\n");
			printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
			printf("user (Tiempo de procesamiento en CPU) %.10f s\n", utime1 - utime0);
			printf("sys (Tiempo en acciÃ³nes de E/S)  %.10f s\n", stime1 - stime0);
			printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
			printf("\n");

			//Mostrar los tiempos en formato exponecial
			printf("\n");
			printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
			printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
			printf("sys (Tiempo en acciÃ³nes de E/S)  %.10e s\n", stime1 - stime0);
			printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
			printf("\n");
		}
	
	}	
	//******************************************************************
	//Fin de algoritmo
	
	//******************************************************************
	//Evaluar los tiempos de ejecucion
	//******************************************************************
    
	//******************************************************************
	
	//Terminar programa normalmente
	exit(0);
}
