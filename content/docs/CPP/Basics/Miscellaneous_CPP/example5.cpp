#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    const int a = 10;
    
    /*
    a value of type "const int *" cannot be used to 
    initialize an entity of type "int *"
    int*  <= const int*   is wrong!!!
    */
    //int *p = &a;  // error!!!间接修改常量的值

    const int *p = &a;
    // int *const p = &a;  //error!!!

    int b = 10;
    int *p1 = &b;
    const int *p2 = &b;  // const int* <= int*
    int *const p3 = &b;  //int* <= int*
    int *p4 = p3;  //int* <= int*

    int *q1 = nullptr;
    int *const q2 = nullptr;  //int*类型
    // const的右边如果没有指针*的话，则const是不参与类型的
    cout << typeid(q1).name() << endl;  //int*
    cout << typeid(q2).name() << endl;  //int*

    int m = 10;
    const int *r = &m;
    // int *s = r;  // error!!!  int* <= const int*
    cout << typeid(r).name() << endl;  //const int*

    return 0;
}