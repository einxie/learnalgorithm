#include <stdio.h>
#include <stdlib.h>

void sort_print(int *datas, int length, char *prestr);
void max_heapify(int *datas, int length, int i); 
void build_max_heap(int *datas, int length);
void heap_sort(int *datas, int length);

int main() {
    int datas[10] = {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
    sort_print(datas, 10, "tosort");
    heap_sort(datas, 10);
    sort_print(datas, 10, "sorted");
    /*
    int datas[1] = {4};
    sort_print(datas, 1, "tosort");
    heap_sort(datas, 1);
    sort_print(datas, 1, "sorted");
    */
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

void max_heapify(int *datas, int length, int i) {
    if(length <= 1) {
        return;
    }
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int largest = 0;
    if(left < length && datas[left] > datas[i]) {
        largest = left;
    } else {
        largest = i;
    }
    if(right < length && datas[right] > datas[largest]) {
        largest = right;
    }
    if(largest != i) {
        int temp = datas[i];
        datas[i] = datas[largest];
        datas[largest] = temp;
        max_heapify(datas, length, largest);
    }
}

void build_max_heap(int *datas, int length) {
    if(length <= 1) {
        return;
    }
    for(int i = length / 2 - 1; i >= 0; i--) {
        max_heapify(datas, length, i);
    }
}

void heap_sort(int *datas, int length) {
    int heap_size = length;
    build_max_heap(datas, length);
    for(int i = length - 1; i >= 1; i--) {
        int temp = datas[0];
        datas[0] = datas[i];
        datas[i] = temp;
        heap_size--;
        max_heapify(datas, heap_size, 0);
    }
}

