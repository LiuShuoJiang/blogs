#include <iostream>
using namespace std;

/*
问题1：main函数调用sum，sum执行完以后，怎么知道回到哪个函数中？
问题二：sum函数执行完，回到main一行，怎么知道从哪一行指令继续运行的？
*/

/*
push ebp
mov ebp, esp
sub esp, 4Ch  //给sum函数开辟栈帧空间
rep stos  //windows系统会执行此指令(栈帧初始化)

mov dword ptr[ebp - 4], 0
mov eax, dword ptr[ebp + 0Ch]
add eax, dword ptr[ebp + 8]  //a + b
mov dword ptr[ebp - 4], eax
mov eax, dword ptr[ebp - 4]  //return temp;

mov esp, ebp
pop ebp
ret  //出栈操作，把出栈的内容放入CPU的PC寄存器中
*/
int sum(int a, int b) {
    int t = 0;
    t = a + b;
    return t;
}

int main() {
    // mov dword ptr[ebp - 4], 0Ah
    int a = 10;  //mov dword ptr[a], 0Ah
    // mov dword ptr[ebp - 8], 14h
    int b = 20;

    /*
    mov eax, dword ptr[ebp - 8]
    push eax
    mov eax, dword ptr[ebp - 4]
    push eax
    */
    /*
    call sum  //下一行指令的地址入栈
    add esp, 8
    mov dword ptr[ebp - 0Ch], eax
    */
    int ret = sum(a, b);
    cout << ret << endl;
    return 0;
}