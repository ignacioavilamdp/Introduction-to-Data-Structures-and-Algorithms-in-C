#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Agenda.h"

Agenda iniciarAgenda(){
    Agenda agenda;
    agenda.n = 0;
    return agenda;
}

void listarAgenda(Agenda agenda){
    int i;
    for (i = 0; i < agenda.n; i++){
        printf("%d) %s:  %d \n", i + 1, agenda.contactos[i].nombre, agenda.contactos[i].num);
    }
}

void agregarContacto(Agenda* agenda, int telefono, char* nombre){
    char* p;
    int tamano = 0, posicion = 0;
    int n = agenda->n;

    tamano = strlen(nombre);
    if (tamano != 0){
        p = (char*) malloc(sizeof(char) * (tamano + 1));
        strcpy(p, nombre);
        while (posicion < n && strcmp(p, agenda->contactos[posicion].nombre) > 0){
            posicion++;
        }
        for (int i = n - 1; i >= posicion; i--){
            agenda->contactos[i + 1].nombre = agenda->contactos[i].nombre;
            agenda->contactos[i + 1].num = agenda->contactos[i].num;
        }
        agenda->contactos[posicion].num = telefono;
        agenda->contactos[posicion].nombre = p;
        agenda->n++;
    }
}

void buscarNombre(Agenda agenda, char* nombre){
    int min, max, med, encontrado, comparacion;

    encontrado = 0;
    min = 0;
    max = agenda.n - 1;
    while (min <= max && !encontrado){
        med = (min + max) / 2;
        comparacion = strcmp(nombre, agenda.contactos[med].nombre);
        if (comparacion == 0)
            encontrado = 1;
        else if (comparacion < 0)
            max = med - 1;
        else
            min = med + 1;
    }

    if (encontrado)
        printf("%d) %s: %d\n", med + 1, agenda.contactos[med].nombre, agenda.contactos[med].num);
    else
        printf("No se encontro %s\n", nombre);
}
