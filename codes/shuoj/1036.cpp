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
    while (cin >> n) {
        int fi = 1;
        for (int i = n; i > 0; i--) {
            int cnt = 0;
            fi += n - i;
            int fii = fi;
            for (int j = 0; j < i; j++) {
                if (j)cout << " ";
                cout << fii;
                fii += j + n + 2 - i;
            }
            cout << endl;
        }
    }


    return 0;
}
/**************************************************************
    Problem: 1036
    User: 14123090
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1560 kb
****************************************************************/