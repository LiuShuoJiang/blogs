#include <iostream>
using namespace std;

int gdata1 = 10;  //.data
int gdata2 = 0;  //.bss
int gdata3;  //.bss

static int gdata4 = 11;  //.data
static int gdata5 = 0;  //.bss
static int gdata6;  //.bss

int main() {
    // 指令：mov dword ptr[a], 0Ch
    // .text
    // 生成的指令在.text段，指令运行时在stack上开辟空间给整数12
    int a = 12;
    int b = 0;
    int c;  //(undefined number)

    static int d = 13;  //.data
    static int e = 0;  //.bss
    static int f;  //.bss  initialized as 0

    return 0;
}