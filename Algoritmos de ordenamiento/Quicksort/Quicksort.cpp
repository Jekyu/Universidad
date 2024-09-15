/*
    JUAN OVIEDO - 20192020064
 */

#include <stdio.h>
void capturafile(int*,int);
void muestra(int*,int);
void insertion(int*,int);

void swap(int *datos, int i, int j){
    int aux;
    aux = datos[i];
    datos[i] = datos[j];
    datos[j] = aux;
}

void quicksort(int *datos, int ini, int fin)
{
    int i,j, pivote;
    i=ini; j = fin; //Van a llevar la casilla 
    
        pivote = datos[(ini+fin)/2];
    
    do{ 
        while(datos[i]<pivote and i<fin){ 
            i++;
        }
        
        while(datos[j]>pivote and j>ini){
            j--;
        }
        
        if(i<=j){
            swap(datos,i,j);
            i++;
            j--;
        }
    }while(i<=j);

    
    if(ini<=j){
        quicksort(datos,ini,j);
    }
    
    if(fin>i){
        quicksort(datos,i,fin);
    }
	
}
void capturafile(int *datos, int n)
{
	FILE * archivo;
	archivo=fopen("Datos.txt","a+");
	for(int i=0;i<n;i++)//Captura datos
	{
		fscanf(archivo,"%i",&datos[i]);
	}	
}
void muestra(int *datos, int n)
{
	for(int i=0;i<n;i++)//Muestra datos 
	{
		printf("%i - ",datos[i]);
	}
	printf("\n");
}


int main()
{
	int * datos;int n;
	printf("Ingrese cuantos datos:");
	scanf("%i",&n);
	datos = new int[n];//Habilitamos la memoria n datos
	capturafile(datos,n);
	muestra(datos,n);
    printf("\nQuickSort:\n");
	quicksort(datos,0, n-1);
	muestra(datos,n);	
}