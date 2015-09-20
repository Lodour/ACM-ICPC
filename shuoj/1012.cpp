#include <iostream>
#include <cstring>
using namespace std;

bool G[10][10], vis[10];
int a[1000], ans[1000];

int dfs(int n) {
    vis[n] = 1;
    int ret = 1;
    for (int i = 0; i < 10; i++)
        if (!vis[i] && G[n][i])
            ret += dfs(i);
    return ret;
}

void mul(int *a, int m) {
    for (int i = 0; i < 999; i++)
        a[i] *= m;
    for (int i = 0; i < 999; i++) {
        a[i + 1] += a[i] / 10;
        a[i] %= 10;
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    string n;
    int k, x, y;
    int num[10] = {0};
    cin >> n >> k;
    for (int i = 0; i < n.size(); i++)
        num[n[i] - '0']++;
    while (k--) {
        cin >> x >> y;
        G[x][y] = 1;
    }
    ans[0] = 1;
    for (int i = 0; i < 10; i++) {
        memset(vis, 0, sizeof(vis));
        int cnt = dfs(i);
        for (int j = 0; j < num[i]; j++)
            mul(ans, cnt);
    }
    int i = 999;
    while (i >= 0 && ans[i] == 0) i--;
    for (; i >= 0; i--)cout << ans[i];
    cout << endl;
    return 0;
}
/**************************************************************
    Problem: 1012
    User: 14123090
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1568 kb
****************************************************************/