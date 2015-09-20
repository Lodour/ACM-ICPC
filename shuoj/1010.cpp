#include <iostream>
using namespace std;

int f(int x) {return x * x * x;}

int main()
{
    int n = 0, k;
    double s = 0;
    cin >> k;
    while (s <= k)
        s += 1.0 / ++n;
    cout << n << endl;
    return 0;
}
/**************************************************************
    Problem: 1010
    User: 14123090
    Language: C++
    Result: Accepted
    Time:4 ms
    Memory:1560 kb
****************************************************************/