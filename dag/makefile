dag: main.o dag.o dfs.o
	g++ $^ -o $@

main.o: dag.h dfs.h
dag.o: dag.h
dfs.o: dfs.h

.PHONY: clean
clean:
	rm -rf *.o dag 
