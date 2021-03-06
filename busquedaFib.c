//*****************************************************************
//ALGORITMO:  Busqueda Exponencial
//Autor: Victor Hugo Rios Rebollar
//Escuela Superior de Computo-IPN
//Fecha: 25/03/2021
//Compilacion: "gcc busquedaFib.c tiempo.c -o fib"(LINUX)
//Ejecucion: "./fib n"(LINUX)
//Ejecucion shell: ./fib.sh(LINUX)
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

int busquedaFib(int arr[], int x, int n);
int min(int x, int y);

//*****************************************************************
//DEFINICION DE FUNCIONES DEL PROGRAMA

int main(int argc, char *argv[]){

  double utime0, stime0, wtime0, utime1, stime1, wtime1;  //Variables para medicion de tiempos
	FILE* fichero; 										    //puntero a fichero
	char cadena[LIMITE];                                    //cadena auxiiar para leer linea a linea los registros del archivo
	fichero = fopen("10millones.txt", "rt");         //apertura del archivo de 10 millones
	int *numeros;									//variable apuntador para reservar memoria
	int n;
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

	//Tomar el segundo argumento como tama????o del algoritmo
	n = atoi(argv[1]);
	numeros=(int*)malloc(n*sizeof(int));
	if(numeros!=NULL){
		for(int i=0;i<n;i++){//realiza las iteraciones hasta n veces ingresado como parametro del programa en la ejecucion
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

       for(int i=0;i<20;i++){
        int result=busquedaFib(numeros,arreglo2[i],n);
			if(result==-1){
        printf("no encontrado\n");
    }else{
    printf("Elemento encontrado en la posici??n %d", result);
    uswtime(&utime1, &stime1, &wtime1);

    printf("\n");
    printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
    printf("user (Tiempo de procesamiento en CPU) %.10f s\n", utime1 - utime0);
    printf("sys (Tiempo en acci????nes de E/S)  %.10f s\n", stime1 - stime0);
    printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    printf("\n");

    printf("\n");
    printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
    printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
    printf("sys (Tiempo en acci????nes de E/S)  %.10e s\n", stime1 - stime0);
    printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
    printf("\n");
    }
    }

	//******************************************************************
	//Fin de algoritmo


	//******************************************************************
	//Evaluar los tiempos de ejecucion
	//******************************************************************
    uswtime(&utime1, &stime1, &wtime1);

	//Calculo del tiempo de ejecucion del programa
	printf("\n");
	printf("real (Tiempo total)  %.10f s\n", wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10f s\n", utime1 - utime0);
	printf("sys (Tiempo en acci????nes de E/S)  %.10f s\n", stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");

	//Mostrar los tiempos en formato exponecial
	printf("\n");
	printf("real (Tiempo total)  %.10e s\n", wtime1 - wtime0);
	printf("user (Tiempo de procesamiento en CPU) %.10e s\n", utime1 - utime0);
	printf("sys (Tiempo en acci????nes de E/S)  %.10e s\n", stime1 - stime0);
	printf("CPU/Wall   %.10f %% \n", 100.0 * (utime1 - utime0 + stime1 - stime0) / (wtime1 - wtime0));
	printf("\n");
	//******************************************************************

	//Terminar programa normalmente
	exit(0);
}

int busquedaFib(int arr[], int x, int n)
{
    /* Initialize fibonacci numbers */
    int fibMMm2 = 0; // (m-2)'th Fibonacci No.
    int fibMMm1 = 1; // (m-1)'th Fibonacci No.
    int fibM = fibMMm2 + fibMMm1; // m'th Fibonacci

    /* fibM is going to store the smallest Fibonacci
       Number greater than or equal to n */
    while (fibM < n) {
        fibMMm2 = fibMMm1;
        fibMMm1 = fibM;
        fibM = fibMMm2 + fibMMm1;
    }

    // Marks the eliminated range from front
    int offset = -1;

    /* while there are elements to be inspected. Note that
       we compare arr[fibMm2] with x. When fibM becomes 1,
       fibMm2 becomes 0 */
    while (fibM > 1) {
        // Check if fibMm2 is a valid location
        int i = min(offset + fibMMm2, n - 1);

        /* If x is greater than the value at index fibMm2,
           cut the subarray array from offset to i */
        if (arr[i] < x) {
            fibM = fibMMm1;
            fibMMm1 = fibMMm2;
            fibMMm2 = fibM - fibMMm1;
            offset = i;
        }

        /* If x is greater than the value at index fibMm2,
           cut the subarray after i+1  */
        else if (arr[i] > x) {
            fibM = fibMMm2;
            fibMMm1 = fibMMm1 - fibMMm2;
            fibMMm2 = fibM - fibMMm1;
        }

        /* element found. return index */
        else
            return i;
    }

    /* comparing the last element with x */
    if (fibMMm1 && arr[offset + 1] == x)
        return offset + 1;

    /*element not found. return -1 */
    return -1;
}

 int min(int x, int y)
 {
     return (x <= y) ? x : y;
 }
