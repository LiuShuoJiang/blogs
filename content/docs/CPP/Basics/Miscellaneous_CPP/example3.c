#include <stdio.h>

void main() {
    const int a0;
    const int a = 20;
    //int array[a] = {};  //error

    int *p = (int*)&a;
    *p = 30;

    printf("%d %d %d\n", a, *p, *(&a));  //30 30 30
}