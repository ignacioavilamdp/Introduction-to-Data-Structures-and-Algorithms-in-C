#define N 100

typedef struct{
    int num;
    char* nombre;
} Contacto;

typedef struct{
    Contacto contactos[N];
    int n;
} Agenda;

Agenda iniciarAgenda();
void listarAgenda(Agenda agenda);
void agregarContacto(Agenda* agenda, int telefono, char* nombre);
void buscarNombre(Agenda agenda, char* nombre);
