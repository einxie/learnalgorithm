#include <stdio.h>
#include <stdlib.h>

void sort_print(int *, int, char *);
void sort_insert(int *, int);

int main() {
    int datas[6] = {5, 2, 4, 6, 1, 3};
    sort_print(datas, 6, "tosort");
    sort_insert(datas, 6);
    sort_print(datas, 6, "sorted");
}

void sort_print(int *datas, int length, char *prestr) {
    printf("%s: ", prestr);
    for(int i = 0; i < length; i++) {
        if(i < length - 1) {
            printf("%d, ", datas[i]);
        } else {
            printf("%d\n", datas[i]);
        }
    }
}

void sort_insert(int *datas, int length) {
    int i, j, key;
    for(j = 1; j < length; j++) {
        key = datas[j];
        i = j - 1;
        while(i >= 0 && datas[i] > key) {
            datas[i+1] = datas[i];
            i--;
        }
        datas[i+1] = key;
    }
}
        
