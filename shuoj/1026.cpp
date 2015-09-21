#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;


int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int a, b;
    while (cin >> a >> b && (a || b)) {
        cout << a + b << endl;
    }

    return 0;
}
/**************************************************************
    Problem: 1026
    User: 14123090
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1560 kb
****************************************************************/