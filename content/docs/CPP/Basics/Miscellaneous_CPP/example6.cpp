#include <iostream>
using namespace std;

int main() {
    int a = 10;
    int *p = &a;
    
    // error!!!
    // error: invalid conversion from 'int**' to 'const int**'
    // const int **q = &p;  // const int**  <=  int**
    /*
        *q  <=> p
    */

    return 0;
}