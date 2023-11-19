#include <stdio.h>

int main() {
    const int a = 20;
    int array[a] = {};

    int *p = (int*)&a;
    *p = 30;

    printf("%d %d %d\n", a, *p, *(&a));  //20 30 30

    int b = 20;
    const int c = b;  //这时是常变量了，因为初始值不是立即数，而是一个变量

    // int arr[c] = {};  //error!!!

    int *q = (int*)&c;
    *q = 30;

    printf("%d %d %d\n", c, *q, *(&c));  //30 30 30

    return 0;
}