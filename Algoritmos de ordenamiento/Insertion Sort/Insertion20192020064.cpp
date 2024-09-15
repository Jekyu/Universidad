#include <stdio.h>
void capturafile(int*,int);
void muestra(int*,int);
void insertion(int*,int);

void insertion(int *datos, int n)
{
	int j;	int key;

	for (int i = 0; i < n; i++)
	{
		key = datos[i];
        j = i - 1;

		while (j >= 0 and datos[j] > key)
		{
			datos[j + 1] = datos[j];
				j = j - 1;
			
			datos[j + 1] = key;
		}  

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
	insertion(datos,n);
	muestra(datos,n);
}