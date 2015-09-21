#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;
/*******************************/
/*            并查集            */
/*******************************/
/* 需头文件:    None               */
/* 修改变量:    MAXN(点数最大值)     */
/*******************************/
const int maxn = 2020;
int pa[maxn << 1];
int ra[maxn << 1];
void init(int n) {
    for (int i = 0; i <= n; i++) {
        pa[i] = i;
        ra[i] = 0;
    }
}
int find(int x) {
    if (pa[x] != x)pa[x] = find(pa[x]);
    return pa[x];
}
int unite(int x, int y) {
    x = find(x);
    y = find(y);
    if (x == y)return 0;
    if (ra[x] < ra[y]) {
        pa[x] = y;
    } else {
        pa[y] = x;
        if (ra[x] == ra[y])ra[x]++;
    }
    return 1;
}
bool same(int x, int y) {
    return find(x) == find(y);
}
/*******************************/


int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int t, cnt = 0;
    scanf("%d", &t);
    while (t--) {
        int n, m, a, b;
        scanf("%d%d", &n, &m);
        init(n << 1);
        int ans = 0;
        while (m--) {
            scanf("%d%d", &a, &b);
            if (ans) continue;
            unite(a, b + n);
            unite(b, a + n);
            ans = same(a, a + n) || same(b, b + n);
        }
        if (cnt++) puts("");
        printf("Scenario #%d:\n", cnt);
        if (ans) puts("Suspicious bugs found!");
        else puts("No suspicious bugs found!");
    }
    return 0;
}
/**************************************************************
    Problem: 1020
    User: 14123090
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1592 kb
****************************************************************/