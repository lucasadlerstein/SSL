#include <stdio.h>

double CelToFahr(double cel);
double FahrToCel(double fahr);

double CelToFahr(double cel) {
    double fahr = (cel * (9.0/5.0)) + 32; 
    return fahr;
}

double FahrToCel(double fahr) {
    double cel = (fahr - 32) * (5.0/9.0);
    return cel;
}