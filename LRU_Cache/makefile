lru_randomtest: lru.h
	gcc -g -Wall lru_randomtest.c -o lru_randomtest -lm

.PHONY : do clean check

check:
	valgrind --tool=cachegrind --log-file=logfile ./lru_randomtest
do:
	./lru_randomtest

clean:
	rm lru_randomtest