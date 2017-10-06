#include <stdio.h>
#include <stdlib.h>

struct sub_info {
    int min;
    int max;
    int sum;
};

struct sub_info find_max_crossing_subarray(int *datas, int length, int low, int mid, int high);
struct sub_info find_maximum_subarray(int *datas, int length, int low, int high);

int main() {
    int datas[16] = {13, -3, -25, 20, -3, -16, -23, 18, 20, -7, 12, -5, -22, 15, -4, 7};
    struct sub_info max_info;
    max_info = find_maximum_subarray(datas, 16, 0, 15);
    printf("low:%d, high:%d, sum:%d\n", max_info.min, max_info.max, max_info.sum);
    return 0;
}

struct sub_info find_max_crossing_subarray(int *datas, int length, int low, int mid, int high) {
    int left_sum = datas[mid], max_left = mid;
    int right_sum = datas[mid+1], max_right = mid+1;
    int sum;
    sum = 0;
    for(int i = mid; i >= low; i--) {
        sum = sum + datas[i];
        if(sum > left_sum) {
            left_sum = sum;
            max_left = i;
        }
    }
    sum = 0;
    for(int j = mid+1; j <= high; j++) {
        sum = sum + datas[j];
        if(sum > right_sum) {
            right_sum = sum;
            max_right = j;
        }
    }
    struct sub_info max_info;
    max_info.min = max_left;
    max_info.max = max_right;
    max_info.sum = left_sum + right_sum;
    return max_info;
}

struct sub_info find_maximum_subarray(int *datas, int length, int low, int high) {
    struct sub_info max_info, max_info_left, max_info_right, max_info_cross;
    if(high == low) {
        max_info.min = low;
        max_info.max = high;
        max_info.sum = datas[low];
    } else {
        int mid = (low + high) / 2;
        max_info_left = find_maximum_subarray(datas, length, low, mid);
        max_info_right = find_maximum_subarray(datas, length, mid+1, high);
        max_info_cross = find_max_crossing_subarray(datas, length, low, mid, high);
        if(max_info_left.sum >= max_info_right.sum && max_info_left.sum >= max_info_cross.sum) {
            max_info = max_info_left;
        } else if(max_info_right.sum >= max_info_left.sum && max_info_right.sum >= max_info_cross.sum) {
            max_info = max_info_right;
        } else {
            max_info = max_info_cross;
        }
    }
    return max_info;
}

