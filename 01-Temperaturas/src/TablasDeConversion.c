#include <stdio.h>
#include "Conversion.h";

void PrintTablas(int inf, int sup, int inc) {
    PrintTablaCelsius(inf, sup, inc);
    PrintTablaFahrenheit(inf, sup, inc);
}

void PrintTablaCelsius(int inf, int sup, int inc) {
    printf('Tabla de Fahrenheit a Celsius:');
    PrintFilas(inf, sup, inc, fahrToCel);

}

void PrintTablaFahrenheit(int inf, int sup, int inc) {
    printf('Tabla de Celsius a  Fahrenheit:');
    PrintFilas(inf, sup, inc, celToFahr);

}

void PrintFilas(int inf, int sup, int inc, int funcionConversion()) {
    // int const longitudTabla = (sup - inf) / inc;
    double converted = 0;
    for(int i = inf; i < sup; i == inf + inc) {
        converted = funcionConversion(inf);
        PrintFila(inf, converted);
    }
    
}

void PrintFila(double from, double to) {
    printf('-----------------------------');
    printf('| ', from, '   ', to, ' |');
    printf('-----------------------------');
}