#include <stdio.h>
#include <stdlib.h>
#include "Agenda.h"

void cargarAgenda(Agenda* agenda);

int main()
{
    Agenda agenda;

    agenda = iniciarAgenda();
    cargarAgenda(&agenda);
    listarAgenda(agenda);

    printf("\n");
    buscarNombre(agenda, "Alonso");
    buscarNombre(agenda, "Zurita");
    buscarNombre(agenda, "Gonzalez");
    buscarNombre(agenda, "Alonsito");
    printf("\n");

    return 0;
}


void cargarAgenda(Agenda* agenda){

    agregarContacto(agenda, 12341, "Gonzalez");
    agregarContacto(agenda, 12342, "Avila");
    agregarContacto(agenda, 12343, "Martinez");
    agregarContacto(agenda, 12344, "Alonso");
    agregarContacto(agenda, 12345, "Heraclito");
    agregarContacto(agenda, 12346, "Zurita");
}
