CFLAGS=-g -W -Wall

OBJECT=standard-object.o main.o

all: $(OBJECT)
	gcc -g -o sicl $(OBJECT) -lgmp -lm

clean:
	rm -f sicl $(OBJECT)

standard-object.o: standard-object.h
main.o: standard-object.h
