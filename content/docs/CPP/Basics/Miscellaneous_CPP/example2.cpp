#include <iostream>
using namespace std;


int main() {
    int *p = (int *)malloc(sizeof(int));
    if (p == nullptr) {
        return -1;
    }
    *p = 20;
    free(p);

    // try {
    //     int *pl = new int(20);
    // } catch(const std::exception& e) {
    //     std::cerr << e.what() << '\n';
    // }
    int *pl = new int(20);
    delete pl;

    int *q = (int *)malloc(sizeof(int) * 20);
    if (q == nullptr) {
        return -1;
    }
    free(q);

    // int *ql = new int[20];
    int *ql = new int[20]();
    delete[] ql;  // 数组内存释放要加[]

    return 0;
}