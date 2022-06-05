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

<br/><br/>

### 3. Vinculación
--> Comenzaremos la próxima clase con Vinculación.
<br/><br/>

## Bibliografía adicional utilizada:
--> https://www3.ntu.edu.sg/home/ehchua/programming/cpp/gcc_make.html
<br/><br/>