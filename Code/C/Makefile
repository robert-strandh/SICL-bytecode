CFLAGS=-g -W -Wall

OBJECT=object.o main.o

all: $(OBJECT)
	gcc -g -o sicl $(OBJECT) -lgmp -lm

clean:
	rm -f sicl $(OBJECT)

object.o: object.h
main.o: object.h
