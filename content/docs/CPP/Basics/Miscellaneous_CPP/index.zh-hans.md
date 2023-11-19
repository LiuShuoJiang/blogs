---
# type: docs 
title: C++杂项
date: 2023-11-17T23:34:23-05:00
featured: false
draft: true
comment: true
toc: true
reward: true
pinned: false
carousel: false
series:
categories: []
tags: []
images: []
---

C++杂项知识点

<!--more-->

## 形参带默认值的函数

## new和delete

`new`和`malloc`的区别是什么？
`delete`和`free`的区别是什么？

`malloc`和`free`是C语言的 ***库函数***，而`new`和`delete`属于 ***运算符***。

`new`不仅可以完成内存开辟，还可以完成内存初始化操作。

`malloc`开辟内存失败，是通过返回值和`nullptr`比较而判断的；而`new`开辟内存失败，是通过抛出`bad_alloc`类型的异常来判断的。

`malloc`返回值类型为`void*`，可能需要进行强制类型转换；而`new`不需要。

`new`有多少种？

- `int *p1 = new int(20);`
- 不抛出异常的`new`：`int *p2 = new (nothrow) int;`
- `const int *p3 = new const int(40);`
- 定位`new`(placement new)：`int data = 0; int *p4 = new (&data) int(50);`

## const的用法

### 概念

如何理解`const`？C和C++中`const`的区别是什么？

`const`修饰的变量不能再作为左值，初始化完成后值不能被修改。

C语言中`const`修饰的量，可以不用初始化，它被称为“常变量”。

```C
void main() {
    const int a = 20;
    //int arr[a] = {};  //error!
    int *p = (int*)&a;
    *p = 30;
    printf("%d %d %d\n", a, *p, *(&a));  //30 30 30
}
```

而C++中的`const`必须被初始化，被称为“常量”。

```C++
int main() {
    const int a = 20;
    int array[a] = {};
    int *p = (int*)&a;
    *p = 30;
    printf("%d %d %d\n", a, *p, *(&a));  //20 30 30 或 20 30 20
    return 0;
}
```

C和C++中`const`的编译方式不同：在C中，`const`就是被当作一个变量来编译生成指令的；而C++中，所有出现`const`常量名字的地方，都被常量的初始化值替换了。

```C++
int b = 20;
// 这时和C语言一样是常变量了，因为初始值不是立即数，而是一个变量
const int c = b;
```

### const和指针的结合

`const`修饰的量叫常量，它和普通变量有何区别？编译方式不同；不能作为左值。

`const`修饰的量(常量)经常出现的错误是：

- 常量不能再作为左值(直接修改常量的值)；
- 不能把常量的地址泄露给一个普通的指针或者普通的引用变量(间接修改常量的值)。

#### `const`和一级指针的结合

`const`修饰的是离它最近的类型。我们通常关心`const`修饰的是什么表达式。

```C++
const int *p;
int const *p;
int *const p;
const int *const p;
```

`const int *p = &a;`：此处`const`修饰的表达式是`*p`。指针指向的内容不能被修改(`*p = 20`是错误的)，但`p`值可以被修改(`p = &b`是正确的)。也就是说该指针可以任意指向不同的`int`类型的内存，但是不能通过指针间接修改指向的内存的值。

`int const *p;`和`const int *p;`一样。

`int *const p;`：此处`const`修饰的表达式是`p`。`p = &b`是错误的，但`*p = 20`可以操作。也就是说这个指针`p`现在是常量，不能再指向其他内存，但是可以通过指针解引用修改指向内存的值。

`const int *const p;`：此处`const`一个修饰的表达式是`*p`，一个修饰的表达式是`p`。该指针既不能修改指针值，也不能修改指向的值。

`const`和指针的类型转换公式：
`int*  <=  const int*`是错误的！
`const int*  <=  int*`是正确的！

`const`的右边如果没有指针`*`的话，则`const`是不参与类型的。

#### `const`和二级指针的结合

```C++
int a = 10, b = 20;
int *p = &a;
int **q = &p;
*p = 20;
**q = 40;
*q = &b;
```

```C++
const int **q;  //**q
int *const* q;  //*q
int **const q;  //q
```

`const int**  <=  int**`是错误的！`int**  <=  const int**`也是错误的！`int**  <=  int *const*`是错误的！

`int *const*  <=  int**`是正确的！
