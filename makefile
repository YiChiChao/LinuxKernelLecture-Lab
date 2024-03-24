timsort: main.o timsort.o
	gcc -o timsort main.o timsort.o

main.o: main.c sort_impl.h list.h
	gcc -c main.c

timsort.o: timsort.c sort_impl.h
	gcc -c timsort.c

do:
	./timsort

clean:
	rm timsort main.o timsort.o 