lru_randomtest: lru.h

.PHONY : do clean check

check:
	valgrind --tool=cachegrind --log-file=logfile ./lru_randomtest
do:
	./lru_randomtest

clean:
	rm lru_randomtest