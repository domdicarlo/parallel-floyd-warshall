output: testing.o stopwatch.o floyd_warshall.o import.o
	gcc testing.o floyd_warshall.o import.o stopwatch.o -lpthread -Wall -Werror -O3 -g -I . -o output

main_serial: main_serial.o floyd_warshall.o import.o
	gcc main_serial.o floyd_warshall.o import.o -lpthread -Wall -Werror -O3 -g -I . -o main_serial

main_parallel: main_parallel.o floyd_warshall.o import.o
	gcc main_parallel.o floyd_warshall.o import.o -lpthread -Wall -Werror -O3 -g -I . -o main_parallel

main_serial.o: main_serial.c
	gcc -c main_serial.c

main_parallel.o: main_parallel.c
	gcc -c main_parallel.c

testing.o: testing.c
	gcc -c testing.c

floyd_warshall.o: floyd_warshall.c floyd_warshall.h
	gcc -c floyd_warshall.c

import.o: import.c import.h
	gcc -c import.c

stopwatch.o: stopwatch.c stopwatch.h
	gcc -c stopwatch.c 

clean:
	rm *.o output