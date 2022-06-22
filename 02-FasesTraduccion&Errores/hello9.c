#include "studio.h" // Interfaz que importa

int main(void){
    int i=42;
    // prontf("La respuesta es %d\n", i, 8);
    // No compila. Eso es lo bueno de los prototipos. No coincide con la declaracion.
    prontf("La respuesta es %d\n", i);
}