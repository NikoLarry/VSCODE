#include <iostream>
using namespace std;

int forLoop(int n) {
    int res = 0;
    // 循环求和 1, 2, ..., n-1, n
    for (int i = 1; i <= n; i++) {
        res += i;
    }
    return res;
}


int main()
{
    int a,b;
    a=8092;
    b=32;
    cout<<a%b;
    return 0 ;
}