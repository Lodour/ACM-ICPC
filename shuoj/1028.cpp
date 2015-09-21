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

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int ans = 0, tt;
        while (n--) {
            cin >> tt;
            ans += tt;
        }
        cout << ans << endl;
    }

    return 0;
}
/**************************************************************
    Problem: 1028
    User: 14123090
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1560 kb
****************************************************************/