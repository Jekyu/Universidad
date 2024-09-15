#include <stdio.h>

// Estructura de evento
struct evento {
  int id;
  int inicio;
  int fin;
};

void CompararEventos(struct evento *eventos, int n) 
{
    int lastEvent = 0; // De 0 a n eventos
    bool seltd = false;

    printf("Eventos seleccionados:\n");

    for (int i = 0; i < n; i++) {//Buscar que envento termina primero
        if (eventos[i].fin < lastEvent) {
            lastEvent = eventos[i].fin;
        }
    }

    for (int i = 0; i < n; i++) { //Itera y compara los elementos de la lista
        if (eventos[i].inicio >= lastEvent) {
            printf("( %i, %i, %i )\n", eventos[i].id, eventos[i].inicio, eventos[i].fin);
            lastEvent = eventos[i].fin; // Actualizar el último tiempo de fin
            seltd = true;
        }
    }

    if (!seltd) {
        printf("No hay eventos.\n");
    }
}

void CapturarEventos(struct evento * eventos, int n) {//Lee el archivo
    FILE * archivo;
    archivo = fopen("Horarios.txt", "a+");

    for (int i = 0; i < n; i++) {
        fscanf(archivo, "%i,%i,%i", &eventos[i].id, &eventos[i].inicio, &eventos[i].fin);
    }
    fclose(archivo);
}

 int main() {
  struct evento *eventos;                                                                                          
  int n;

  printf("Ingrese la cantidad de eventos en la lista a analizar: ");
  scanf("%i", &n);
  eventos = new evento[n];
  CapturarEventos(eventos, n);
  CompararEventos(eventos, n);

  delete[] eventos;
  return 0;
}