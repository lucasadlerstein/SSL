#include <stdio.h>
#include <stdlib.h>
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
    // int const longitudTabla = (sup - inf) / inc;
    double converted = 0;
    double longitud = abs(sup - inf);
    double gradoActual = inf;
    // for(double i = inf; i <= sup; i == i + inc) {
    for(double i = 0; i <= longitud; i) {
        converted = funcionConversion(gradoActual);
        PrintFila(gradoActual, converted);
        gradoActual = gradoActual + inc;
        i = i + inc;
    }
}

void PrintFila(double from, double to) {
    // printf("| ", "%6.1f", from, "  ->  ", "%6.1f", to, " |\n");
    printf("\n %6.1f %6.1f", from, to);
}

double Fahrenheit(double cel) {
    double fahr = (cel * (9.0/5.0)) + 32; 
    return fahr;
}

double Celsius(double fahr) {
    double cel = (fahr - 32) * (5.0/9.0);
    return cel;
}