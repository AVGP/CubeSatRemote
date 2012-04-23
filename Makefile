qb_tc_data_routing.o:
	gcc -c -Wall lib/qb_tc_data_routing.c -o qb_tc_data_routing.o

lib: qb_tc_data_routing.o util.o
	gcc -shared -W1,-soname,libcubesat.so -o libcubesat.so util.o qb_tc_data_routing.o

util.o:
	gcc -c -Wall -o util.o lib/util.c

db.o:
	gcc -c `mysql_config --libs --cflags` -O3 -Wall -o db.o db/db.c

generator.o:
	gcc -c qb_generator.c `mysql_config --libs --cflags` -Wall -L./ -lcubesat -o generator.o

clean:
	rm *.o

all: lib db.o generator.o
	gcc -o packetgen -L. -lcubesat `mysql_config --libs` db.o generator.o
