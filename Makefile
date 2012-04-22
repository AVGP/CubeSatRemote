db.o:
	gcc -c `mysql_config --libs --cflags` -O3 -Wall -o db.o db/db.c

generator.o:
	gcc -c qb_generator.c `mysql_config --libs --cflags` -Wall -L./ -lcubesat -o generator.o

clean:
	rm *.o

all: db.o generator.o
	gcc -o packetgen -L. -lcubesat `mysql_config --libs` db.o generator.o
