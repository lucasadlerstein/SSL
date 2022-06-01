#include <stdio.h>
#include <stdlib.h>
#include "TablasDeConversion.h"
#include "Conversion.h"

void PrintTablas(double inf, double sup, double inc) {
   PrintTablaCelsius(inf, sup, inc);
   PrintTablaFahrenheit(inf, sup, inc);
}

void PrintTablaCelsius(double inf, double sup, double inc) {
    printf("\n\nTabla de Fahrenheit a Celsius:");
    PrintFilas(inf, sup, inc, Celsius);
}

void PrintTablaFahrenheit(double inf, double sup, double inc) {
    printf("\n\nTabla de Celsius a  Fahrenheit:");
    PrintFilas(inf, sup, inc, Fahrenheit);
}

void PrintFilas(double inf, double sup, double inc, double(*funcionConversion)()) {
    double converted = 0;
    double gradoActual = inf;
    for(double i = inf; i <= sup; i += inc) {
        converted = funcionConversion(gradoActual);
        PrintFila(gradoActual, converted);
        gradoActual = gradoActual + inc;
    }
}

void PrintFila(double from, double to) {
    printf("\n | %6.1f -> %6.1f |", from, to);
}