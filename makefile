OBJS = main.o timsort.o
timsort: $(OBJS)
	cc -o timsort $(OBJS)

$(OBJS) : sort_impl.h
main.o : list.h

.PHONY : do clean
do:
	./timsort

clean:
	rm timsort $(OBJS)