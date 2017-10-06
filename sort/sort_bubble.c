#include <stdio.h>
#include <stdlib.h>

void sort_print(int *, int, char *);
void sort_bubble(int *, int);

int main() {
    int datas[6] = {5, 2, 4, 6, 1, 3};
    sort_print(datas, 6, "tosort");
    sort_bubble(datas, 6);
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

void sort_bubble(int *datas, int length) {
    int i, j, key;
    for(i = 0; i < length; i++) {
        for(j = i + 1; j < length; j++) {
            if(datas[i] > datas[j]) {
                key = datas[i];
                datas[i] = datas[j];
                datas[j] = key;
            }
        }
    }
}
