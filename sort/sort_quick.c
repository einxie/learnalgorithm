#include <stdio.h>
#include <stdlib.h>

void sort_print(int *datas, int length, char *prestr); 
int partition(int *datas, int left, int right); 
void sort_quick_one(int *datas, int left, int right); 
void sort_quick(int *datas, int length);

int main() {
    int datas[6] = {5, 2, 4, 6, 1, 3};
    sort_print(datas, 6, "tosort");
    sort_quick(datas, 6);
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

void sort_quick(int *datas, int length) {
    sort_quick_one(datas, 0, length - 1);
}

void sort_quick_one(int *datas, int left, int right) {
    if(left < right) {
        int middle = partition(datas, left, right);
        sort_quick_one(datas, left, middle - 1);
        sort_quick_one(datas, middle + 1, right);
    }
}

int partition(int *datas, int left, int right) {
    int pivot = datas[right];
    int i = left - 1;
    for(int j = left; j < right; j++) {
        if(datas[j] <= pivot) {
            ++i;
            int temp = datas[i];
            datas[i] = datas[j];
            datas[j] = temp;
        }
    }
    int temp = datas[i+1];
    datas[i + 1] = datas[right];
    datas[right] = temp;
    return i + 1;
}

