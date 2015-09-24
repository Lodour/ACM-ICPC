#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

char mp[110][110];

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int n, m, cnt = 0;
    while (scanf("%d%d", &n, &m) && n && m) {
        if (cnt++)putchar('\n');
        printf("Field #%d:\n", cnt);
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            for (int j = 0; j < m; j++)
                mp[i][j] = s[j] == '*' ? '*' : '0';
        }
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (mp[i][j] != '*') continue;
                for (int s = -1; s <= 1; s++)
                    for (int t = -1; t <= 1; t++)
                        if (i + s >= 0 && i + s < n && j + t >= 0 && j + t < m)
                            if (mp[i + s][j + t] != '*')
                                mp[i + s][j + t]++;
            }
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++)
                putchar(mp[i][j]);
            putchar('\n');
        }
    }

    return 0;
}


/**************************************************************
    Problem: 1035
    User: 14123090
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1572 kb
****************************************************************/