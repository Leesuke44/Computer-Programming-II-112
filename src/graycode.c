#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define SIZE 1025

int* grayCode(int n, int size) {
    int* res = malloc(sizeof(int) * size), gray = 0;
    bool flag = false, isExist[SIZE];

    for (int i = 0; i < size; i++)isExist[i] = false;
    res[0] = 0, isExist[0] = true;

    for (int i = 1; i < size; i++) {
        int mask = 1;
        while (mask < size) {
            int temp = gray;
            gray ^= mask;

            if (!isExist[gray])break;

            gray = temp;
            mask = mask << 1;
        }
        res[i] = gray;
        isExist[gray] = true;
    }
    return res;
}

int main() {
    int N, *ans, size;

    scanf("%d", &N);

    size = 1 << N;
    ans = grayCode(N, size);

    for (int i = 0; i < size; i++) {
        printf("%d ", ans[i]);
    }
}