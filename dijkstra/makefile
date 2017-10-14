dijkstra: main.o dijkstra.o
	g++ $^ -o $@

main.o: dijkstra.h
dijkstra.o: dijkstra.h

.PHONY: clean
clean:
	rm -rf *.o dijkstra
