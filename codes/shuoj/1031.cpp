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

    int t, cnt = 0;
    cin >> t;
    while (t--) {
        if (cnt++)cout << endl;
        int n, s = 0, t;
        cin >> n;
        while (n--) {
            cin >> t;
            s += t;
        }
        cout << s << endl;
    }

    return 0;
}
/**************************************************************
    Problem: 1031
    User: 14123090
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1560 kb
****************************************************************/