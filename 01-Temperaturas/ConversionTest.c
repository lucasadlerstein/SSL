#include <assert.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "Conversion.h"

bool testearConversiones(double fst, double snd, double pres);

int main(void){
    assert(testearConversiones(Fahrenheit(10.0),50.0,0.1) == true);
    puts("CelToFahr funciona correctamente");
    assert(testearConversiones(Celsius(50.0),10.0,0.1) == true);
    puts("FahrToCel funciona correctamente");
}

bool testearConversiones(double fst, double snd, double pres){
    return abs(fst - snd) < pres;
}
