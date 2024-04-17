LRU_unitest: lru.h

.PHONY : do clean check

check:
	valgrind --tool=cachegrind --log-file=logfile ./LRU_unitest
do:
	./LRU_unitest

clean:
	rm LRU_unitest 