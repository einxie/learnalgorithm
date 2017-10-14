bellmanford: main.o bellmanford.o
	g++ $^ -o $@

main.o: bellmanford.h
bellmanford.o: bellmanford.h

.PHONY: clean
clean:
	rm -rf *.o bellmanford 
