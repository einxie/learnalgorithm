#include <stdio.h>
#include <stdlib.h>

void sort_print(int *, int, char *);
void sort_combine(int *datas, int left, int middle, int right); 
void sort_merge_one(int *datas, int left, int right); 
void sort_merge(int *, int);

int main() {
    int datas[6] = {5, 2, 4, 6, 1, 3};
    sort_print(datas, 6, "tosort");
    sort_merge(datas, 6);
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

void sort_merge(int *datas, int length) {
    sort_merge_one(datas, 0, length - 1);
}

void sort_merge_one(int *datas, int left, int right) {
    if(left >= right) {
        return;
    }
    int middle = (left + right) / 2;
    sort_merge_one(datas, left, middle);
    sort_merge_one(datas, middle + 1, right);
    sort_combine(datas, left, middle, right);
} 

void sort_combine(int *datas, int left, int middle, int right) {
    int n1 = middle - left + 1;
    int n2 = right - middle;
    if(n1 <= 0 || n2 <= 0) {
        return;
    }
    int datas_left[n1], datas_right[n2];
    for(int i = 0; i < n1; i++) {
        datas_left[i] = datas[left + i];
    }
    for(int i = 0; i < n2; i++) {
        datas_right[i] = datas[middle + i + 1];
    }
    for(int i = 0, j = 0, k = 0; k < n1 + n2; k++) {
        if(i < n1 && j < n2) {
            if(datas_left[i] <= datas_right[j]) {
                datas[left + k] = datas_left[i];
                i++;
            } else {
                datas[left + k] = datas_right[j];
                j++;
            }
        } else if(i < n1) {
            datas[left + k] = datas_left[i];
            i++;
        } else {
            datas[left + k] = datas_right[j];
            j++;
        }
    }
}

