#include <stdio.h>

int main() {
    int a, b;
    scanf("%d %d", &a, &b);
    int c = a ^ b, res = 0;
    for (int i = 0; i < 32; i++) {
        if ((c & 1)== 1)res++;
        c /= 2;
    }
    printf("%d", res);
}