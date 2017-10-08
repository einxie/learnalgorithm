kruskal: main.o kruskal.o disjointset.o
	g++ $^ -o $@

main.o: kruskal.h
kruskal.o: kruskal.h disjointset.h
disjointset.o: disjointset.h

.PHONY: clean
clean:
	rm -rf *.o kruskal
