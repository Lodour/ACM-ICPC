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

    int ans = 0, a, b, m = 8, cnt = 0;
    while (cin >> a >> b) {
        ++cnt;
        if (a + b > m) {
            ans = cnt;
            m = a + b;
        }
    }
    cout << ans << endl;

    return 0;
}
/**************************************************************
    Problem: 1037
    User: 14123090
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1560 kb
****************************************************************/