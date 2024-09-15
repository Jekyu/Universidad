#include <stdio.h>
void capturafile(int*,int);
void muestra(int*,int);
void insertion(int*,int);

void swap(int *datos, int i, int j){
    int aux;
    aux = datos[i];
    datos[i] = datos[j];
    datos[j] = aux;
    printf("Swap\n");
}

void recorrer(int *datos, int ini , int fin){
    for(int i=ini;i<fin;i++)//Muestra datos 
        {
            printf("%i - ",datos[i]);
        }
        printf("\n");
}

void merge(int *datos, int ini, int fin){
    recorrer(datos, ini, fin);

    

   /* int i = ini, j = fin/2;
    do
    {
        printf("[j] - j: %i, %i | [i] - i: %i, %i\n",datos[j], j,datos[i], i);

        if(datos[i]<datos[j]){
            i++;
        }else{
            swap(datos, i, j);
            j++;
        }

    } while (i<fin/2 and j<fin);*/
}

void mergesort(int *datos, int ini, int fin)
{
    if(fin<1){
        return;
    }

    recorrer(datos,ini,fin-1);
    printf("\nfin/2: %i, [fin/2]: %i\n",fin/2,datos[fin/2]);
    printf("\nfin-1: %i - %i\n",fin-1, datos[fin-1]);
    //Izq
    //mergesort(datos, ini, fin/2);
    //Der
    mergesort(datos, fin/2,  fin-1);
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
    printf("\nMergesort:\n");
	mergesort(datos,0, n);
	muestra(datos,n);	
}