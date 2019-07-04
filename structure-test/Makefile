.PHONY: clean

test: struct_buffer_copy.o
	gcc -Wall -o $@ $^

struct_buffer_copy.o: struct_buffer_copy.c

clean:
	rm -rf *.o test
