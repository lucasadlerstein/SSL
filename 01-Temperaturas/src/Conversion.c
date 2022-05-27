#include <stdio.h>
#include "Conversion.h"
#include "TablasDeConversion.c"

int main(void) {
   int const limiteInferior = -25;
   int const limiteSuperior = 50;
   int const incremento = 1;
   
   PrintTablas(limiteInferior, limiteSuperior, incremento);
}