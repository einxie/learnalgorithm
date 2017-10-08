prim: main.o prim.o
	g++ $^ -o $@

main.o: prim.h
prim.o: prim.h

.PHONY: clean
clean:
	rm -rf *.o prim
