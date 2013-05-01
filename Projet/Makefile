SOURCES=option.c clavier.c plateau.c fichier.c main.c deplacement2.c ia.c game.c
OBJECTS=$(SOURCES:.c=.o)
CFLAGS= -std=c89 -Wall -pedantic -ansi -g
EXECUTABLE=abalone

$(EXECUTABLE): $(OBJECTS)
	gcc -o $(EXECUTABLE) $(OBJECTS)

%.o : %.c
	gcc -c $(CFLAGS) $< -o $@

clean:
	rm -f $(EXECUTABLE) $(OBJECTS)
