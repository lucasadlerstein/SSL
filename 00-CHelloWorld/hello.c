#include <stdio.h>

int main(void) { 
    // void para no pasar parametros
    FILE *f = freopen("output.txt", "w", stdout);
    printf("Hello World!!\n");
    fclose(f);
}