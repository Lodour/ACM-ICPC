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

    int n;
    while (cin >> n && n) {
        int t, ans = 0;
        while (n--) {
            cin >> t;
            ans += t;
        }
        cout << ans << endl;
    }

    return 0;
}
/**************************************************************
    Problem: 1027
    User: 14123090
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1560 kb
****************************************************************/