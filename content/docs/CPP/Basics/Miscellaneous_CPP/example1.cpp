#include <iostream>
using namespace std;

// 定义处可以给形参默认值，声明也可以给形参默认值
// 形参给默认值的时候，不管是定义处给，还是声明处给，形参默认值只能出现一次
// 给默认值的时候从右向左给
int sum(int a, int b = 20);
int sum(int a = 10, int b);

int main() {
    int a = 10;
    int b = 20;

    int ret = sum(a, b);
    /*
    mov eax, dword ptr[ebp - 8]
    push eax
    mov ecx, dword ptr[ebp - 4]
    push ecx
    call sum
    */
    cout << "ret: " << ret << endl;
    
    /*
    push 14H
    mov ecx, dword ptr[ebp - 4]
    push ecx
    call sum
    */
    ret = sum(a);

    return 0;
}

int sum(int a, int b) {
    return a + b;
}
