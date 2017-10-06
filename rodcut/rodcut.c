#include <stdio.h>
#include <stdlib.h>

int cut_rod(int* p, int n) {
    if(n == 0) {
        return 0;
    }
    int q = 0;
    for(int i = 1; i <= n; i++) {
        int qn = p[i - 1] + cut_rod(p, n - i);
        if(n == 10) {
            //printf("i:%d rev:%d\n", i, qn);
        }
        if(q < qn) {
            q = qn;
        }
    }
    return q;
}

int memorized_cut_rod(int* p, int* r, int n) {
    if(n == 0) {
        return 0;
    }
    if(r[n - 1] > 0) {
        return r[n - 1];
    }
    int q = 0;
    for(int i = 1; i <= n; i++) {
        int qn = p[i - 1] + memorized_cut_rod(p, r, n - i);
        if(n == 10) {
            //printf("i:%d rev:%d\n", i, qn);
        }
        if(q < qn) {
            q = qn;
        }
    }
    r[n - 1] = q;
    return q;
}

int bottom_up_memorized_cut_rod(int* p, int* r, int n) {
    if(n == 0) {
        return 0;
    }
    for(int j = 1; j <= n; j++) {
    int q = 0;
    for(int i = 1; i <= j; i++) {
        int qn;
        if(i + 1 > j) {
            qn = p[i - 1];
        } else {
            qn = p[i - 1] + r[j - i - 1];
        }
        if(q < qn) {
            q = qn;
        }
    }
    r[j - 1] = q;
    }
    return r[n-1];
}

int extend_bottom_up_memorized_cut_rod(int* p, int* r, int* s, int n) {
    if(n == 0) {
        return 0;
    }
    for(int j = 1; j <= n; j++) {
    int q = 0;
    for(int i = 1; i <= j; i++) {
        int qn;
        if(i + 1 > j) {
            qn = p[i - 1];
        } else {
            qn = p[i - 1] + r[j - i - 1];
        }
        if(q < qn) {
            q = qn;
            s[j - 1] = i;
        }
    }
    r[j - 1] = q;
    }
    return r[n-1];
}

int main() {
    int p[10] = {1,5,8,9,10,17,17,20,24,26};
    int r[10] = {0};
    int s[10] = {0};
    int q = cut_rod(p, 10);
    printf("cut 10 max rev:%d\n", q);
    q = memorized_cut_rod(p, r, 10);
    printf("cut 10 max rev:%d\n", q);
    printf("array r: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", r[i]);
    }
    printf("\n");
    q = bottom_up_memorized_cut_rod(p, r, 10);
    printf("cut 10 max rev:%d\n", q);
    printf("array r: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", r[i]);
    }
    printf("\n");
    q = extend_bottom_up_memorized_cut_rod(p, r, s, 10);
    printf("cut 10 max rev:%d\n", q);
    printf("array r: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", r[i]);
    }
    printf("\n");
    printf("array p: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", p[i]);
    }
    printf("\n");
    printf("array s: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", s[i]);
    }
    printf("\n");
    printf("array last: ");
    for(int i = 10; i > 0; ) {
        printf("%d ", s[i - 1]);
        i = i - s[i - 1];
    }
    printf("\n");
    return 0;
}
