#include <stdio.h>

double celToFahr(double cel) {
    // To convert temperatures in degrees Celsius to Fahrenheit
    // multiply by 9/5 and add 32.
    double fahr = (cel * (9/5)) + 32; 
    return fahr;
}

double fahrToCel(double fahr) {
    // To convert temperatures in degrees Fahrenheit to Celsius
    // subtract 32 and multiply by 5/9.
    double cel = (fahr - 32) * (5/9);
    return cel;
}

