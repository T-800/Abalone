SOURCES=plateau.c fichier.c main.c
OBJECTS=$(SOURCES:.c=.o)
CFLAGS= -std=c89 -Wall -pedantic
EXECUTABLE=abalone

$(EXECUTABLE): $(OBJECTS)
	gcc -o $(EXECUTABLE) $(OBJECTS)

%.o : %.c
	gcc -c $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
