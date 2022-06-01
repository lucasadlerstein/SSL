#include <stdio.h>
#include "Conversion.h"
#include "TablasDeConversion.h"

int main(void) {
   double const limiteInferior = 5;
   double const limiteSuperior = 50;
   int const incremento = 1;
   
   PrintTablas(limiteInferior, limiteSuperior, incremento);
   // Para prevenir que se cierre la consola en caso de abrir desde fileExplorer.
   getchar();
}

double Fahrenheit(double cel) {
   double fahr = (cel * (9.0/5.0)) + 32; 
   return fahr;
}

double Celsius(double fahr) {
   double cel = (fahr - 32) * (5.0/9.0);
   return cel;
}