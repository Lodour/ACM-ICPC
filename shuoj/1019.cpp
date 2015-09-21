#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
using namespace std;
typedef pair<int, int> PII;
#define MP make_pair
#define X first
#define Y second

const int maxn = 1e5;
bool check[maxn + 10];
bool vis[maxn + 10];
void init() {
    check[0] = check[1] = 1;
    for (int i = 2; i < maxn; i++)
        if (!check[i])
            for (int j = i * 2; j < maxn; j += i)
                check[j] = 1;
}

int solve(int a, int b) {
    queue<PII> q;
    q.push(MP(a, 0));
    vis[a] = 1;
    while (!q.empty()) {
        int x = q.front().X;
        int n = q.front().Y;
        q.pop();
        if (x == b) return n;
        int nx;
        for (int i = 0; i < 10; i++) {
            // *aaa
            nx = x + (i - x / 1000) * 1000;
            if (nx > 1000 && !check[nx] && !vis[nx]) {
                vis[nx] = 1;
                q.push(MP(nx, n + 1));
            }
            // a*aa
            nx = x + (i - x / 100 % 10) * 100;
            if (!check[nx] && !vis[nx]) {
                vis[nx] = 1;
                q.push(MP(nx, n + 1));
            }
            // aa*a
            nx = x + (i - x / 10 % 10) * 10;
            if (!check[nx] && !vis[nx]) {
                vis[nx] = 1;
                q.push(MP(nx, n + 1));
            }
            // aaa*
            nx = x + (i - x % 10);
            if (!check[nx] && !vis[nx]) {
                vis[nx] = 1;
                q.push(MP(nx, n + 1));
            }
        }
    }
    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    init();
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        memset(vis, 0, sizeof(vis));
        cin >> a >> b;
        int ans = solve(a, b);
        if (ans == -1) cout << "Impossible" << endl;
        else cout << ans << endl;
    }

    return 0;
}
/**************************************************************
    Problem: 1019
    User: 14123090
    Language: C++
    Result: Accepted
    Time:12 ms
    Memory:1764 kb
****************************************************************/