#include <stdio.h>
#include "Conversion.h"

int main(void) {
   double const limiteInferior = 5;
   double const limiteSuperior = 50;
   int const incremento = 1;
   
   PrintTablas(limiteInferior, limiteSuperior, incremento);
   // Para prevenir que se cierre la consola:
   getchar();
}