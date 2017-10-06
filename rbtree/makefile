rbtree: main.o rbprint.o rbdelete.o rbdelete_fixup.o rbinsert.o rbinsert_fixup.o rbquery.o rbrotate.o rbtransplant.o
	gcc $^ -o $@

main.o: rbtree.h
rbprint.o: rbtree.h
rbdelete.o: rbtree.h
rbdelete_fixup.o: rbtree.h
rbinsert.o: rbtree.h
rbinsert_fixup.o: rbtree.h
rbquery.o: rbtree.h
rbrotate.o: rbtree.h
rbtransplant.o: rbtree.h

.PHONY: clean
clean:
	rm -rf *.o rbtree 
