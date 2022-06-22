# Trabajo Práctico TP2
## Tp2: Fases de Traducción y Errores

### Objetivo principal:
-> Identificar fases del proceso de traducción o Build y posibles errores asociados a cada fase.
<br/><br/>

### Temas:
• Fases de traducción.
<br/>• Preprocesamiento.
<br/>• Compilación.
<br/>• Ensamblado.
<br/>• Vinculación (Link).
<br/>• Errores en cada fase.
<br/>• Compilación separada.
<br/><br/>

## Secuencia de Pasos:

### 1. Preprocesador
b.  $ gcc -E hello2.c -Wall -o hello2.i -S
<br/>Preprocesa perfectamente. El comentario es reemplazado por un espacio, eso hace que no afecte el programa y no quede intmain.. todo junto. En ese caso no sería reconocido ni “int” ni “main”.
<br/><br/>
d. Consultar. No pude comprender en lo que fui encontrando en diferentes bibliografias.
<br/><br/>
e. La diferencia “numérica” son unas 1033 líneas.
<br/>→ hello2.i tiene 1043 líneas.
<br/>→ hello3.i tiene 10 líneas.
<br/>La versión 3 solo “importa” al .i el encabezado de la función printf mientras que en el la versión 2, se importa toda la biblioteca stdio incluyendo otras funciones como wscanf por ejemplo.
<br/><br/>

### 2. Compilación
a. Presenta un error sintactico, de como escribimos.
<br/><br/>
b.  gcc -S hello3.i -o hello3.s
<br/>
“error: expected declaration or statement at end of input”
<br/>	Se agregó la llave de cierre a la funcion MAIN.
<br/><br/>
c. El código en lenguaje ensamblador lo que hace es en el main pushear usando pushq (q = quad = 64 bits), para guardar lo que había y no perderlo. Mueve ese contenido de rbp a rsp.Luego llama al main, mueve el 42 que es del int  i a una posición de memoria con MOVL. Luego llama a prontf e imprime el texto guardado que fue convertido a ascii.
<br/><br/>
d.  as -o hello4.o hello4.s -Wall

<br/>

### 3. Vinculación
a. Ejecutando "gcc hello4.o" devuelve un error: "undefined reference to `prontf'
collect2: error: ld returned 1 exit status". No encuentra la referencia de prontf, esto es porque no encuentra la referencia de donde buscarlo... no sabe lo que es porque no puede encontrarlo (por no saber donde buscar).
<br/><br/>
b. Cambiando el prOntf por un prIntf se soluciona. Ahí si sabe donde encontrarlo.
<br/><br/>
c. Se general el hello5.exe y funciona, devuelve el texto esperado.
<br/><br/>

### 4. Corrección de BUG
a. El avast se manifiesta :), pero la consola devuelve "La respuesta es 42", así que funciona perfecto.
<br/><br/>

### 5. Remoción del Prototipo
a. 
<br/>
```
$ gcc hello7.c -o hello7.exe
hello7.c: In function ‘main’:
hello7.c:3:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
    3 |     printf("La respuesta es %d\n", i);
      |     ^~~~~~
hello7.c:1:1: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
  +++ |+#include <stdio.h>
    1 | int main(void){
hello7.c:3:5: warning: incompatible implicit declaration of built-in function ‘printf’ [-Wbuiltin-declaration-mismatch]
    3 |     printf("La respuesta es %d\n", i);
      |     ^~~~~~
hello7.c:3:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
```

<br/><br/>
b. Funciona ya que printf es conocido y sabe donde ser encontrado aunque no aclaremos que debe buscarlo en stdio. De hecho, sabe y nos pide que INCLUYAMOS <stdio.h> o que declaremos printf. Eso hace cuando hay una declaración implicita que es conocida.
<br/><br/>

### 6. Compilación Separada: Contratos y Módulos

Hay warning. No hay error de compilacion. Hay error de linkeo. El tema es con el linker (LD). El error es que no esta definida prontf. Se busca dentro del mismo directorio, cual es esa declaración que falta, donde está y la incorpora. Ese warning que hay, es un aviso de que no fue declarada de antemano.
<br/>
gcc es permisivo. Llama a una funcion que no esta declarada sin ningun problema.
<br/><br/>
c. El error es el mismo en ambos casos:
```
Lucas@MyLaptop MSYS /d/Lucas/Documents/UTN - Ingenieria en Sistemas/Sintaxis y Semantica de los Lenguajes/TPs/Individual/02-FasesTraduccion&Errores
$ gcc studio1.c -o studio1.exe
studio1.c: In function ‘prontf’:
studio1.c:2:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
    2 |     printf("La respuesta es %d\n", i);
      |     ^~~~~~
studio1.c:1:1: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
  +++ |+#include <stdio.h>
    1 | void prontf(const char* s, int i) {
studio1.c:2:5: warning: incompatible implicit declaration of built-in function ‘printf’ [-Wbuiltin-declaration-mismatch]
    2 |     printf("La respuesta es %d\n", i);
      |     ^~~~~~
studio1.c:2:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
/usr/lib/gcc/x86_64-pc-msys/11.3.0/../../../../x86_64-pc-msys/bin/ld: /usr/lib/gcc/x86_64-pc-msys/11.3.0/../../../../lib/libmsys-2.0.a(libcmain.o): in function `main':
/c/S/msys2-runtime/src/msys2-runtime/winsup/cygwin/lib/libcmain.c:37: undefined reference to `WinMain'
collect2: error: ld returned 1 exit status
```

<br/><br/>

d. Usar un contrato permite al programador, indicar al preprocesador donde buscar la función, donde está declarada para poder ser usada. Si lo declaramos, podemos indicar "exactamente" como usarse y que no sea confundido con otra función.
<br/><br/> 

## Bibliografía adicional utilizada:
--> https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html
<br/><br/>