OBJS = main.o timsort.o
timsort: $(OBJS)
	cc -o timsort $(OBJS)

$(OBJS) : sort_impl.h
main.o : list.h

.PHONY : do clean check

check:
	valgrind --tool=cachegrind --log-file=logfile ./timsort
do:
	./timsort

clean:
	rm timsort $(OBJS)