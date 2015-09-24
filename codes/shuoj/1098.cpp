#include <iostream>
using namespace std;

int f(int x) {return x * x * x;}

int main()
{
    int n;
    cin >> n;
    if (f(n / 100) + f(n / 10 % 10) + f(n % 10) == n) cout << 1 << endl;
    else cout << 0 << endl;
    return 0;
}
/**************************************************************
    Problem: 1098
    User: 14123090
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1560 kb
****************************************************************/