#include <stdio.h>
void capturafile(int*,int);
void muestra(int*,int);
void insertion(int*,int);

void intercambiar(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}

bool criterio(int a, int b) {

    if (a % 2 == 0 && b % 2 != 0) return true;   // a es múltiplo de 2
    if (a % 2 != 0 && b % 2 == 0) return false;  // b es múltiplo de 2
    if (a % 3 == 0 && b % 3 != 0) return true;   // a es múltiplo de 3
    if (a % 3 != 0 && b % 3 == 0) return false;  // b es múltiplo de 3

    return a < b;  // Si ninguno es múltiplo, ordenar por valor
}

void bubble(int *datos, int n)
{
    bool swapped;

    do {
        swapped = false;
        for (int i = 0; i < n - 1; i++) {
            if (!criterio(datos[i], datos[i + 1])) {
                intercambiar(datos[i], datos[i + 1]);
                swapped = true;
            }
        }
        n--;
    } while (swapped);
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
	bubble(datos,n);
	muestra(datos,n);
}