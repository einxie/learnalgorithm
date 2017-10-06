#include <stdio.h>
#include <stdlib.h>

void sort_print(int *datas, int length, char *prestr); 
void sort_count(int *datas, int *result, int length, int *counts, int c_length);

int main() {
    int datas[8] = {2, 5, 3, 0, 2, 3, 0, 3};
    int result[8] = {0};
    int counts[6] = {0};
    sort_print(datas, 8, "tosort");
    sort_count(datas, result, 8, counts, 6);
    sort_print(result, 8, "sorted");
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

void sort_count(int *datas, int *result, int length, int *counts, int c_length) {
   for(int j = 0; j < length; j++) {
       counts[datas[j]] = counts[datas[j]] + 1;
   }
   for(int i = 1; i < c_length; i++) {
       counts[i] = counts[i] + counts[i - 1];
   }
   for(int j = length - 1; j >= 0; j--) {
       result[counts[datas[j]] - 1] = datas[j];
       counts[datas[j]] = counts[datas[j]] - 1;
   }
}
