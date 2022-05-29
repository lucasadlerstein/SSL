BIN = TablasDeConversion.exe
OBJ = TablasDeConversion.o Conversion.o
BIN2 = ConversionTest.exe
OBJ2 = ConversionTest.o Conversion.o
CC = gcc
CFLAGS = -std=c18
RM = rm -f
$(BIN): $(OBJ)	
	$(CC) $(OBJ) -o $(BIN) $(CFLAGS)

$(BIN2): $(OBJ2)	
	$(CC) $(OBJ2) -o $(BIN2) $(CFLAGS)

TablasDeConversion.o: TablasDeConversion.c Conversion.h
	$(CC) -c TablasDeConversion.c -o TablasDeConversion.o $(CFLAGS)

ConversionTest.o: ConversionTest.c Conversion.h
	$(CC) -c ConversionTest.c -o ConversionTest.o $(CFLAGS)

Conversion.o: Conversion.h Conversion.c
	$(CC) -c Conversion.c -o Conversion.o $(CFLAGS)

clean:
	rm -rf *.o TablasDeConversion.exe ConversionTest.exe