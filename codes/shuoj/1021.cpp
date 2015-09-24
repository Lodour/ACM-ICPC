#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
#define MP make_pair
int n, m, st;
char mp[110][110];
bool vis[110][110];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int solve() {
    memset(vis, 0, sizeof(vis));
    queue<PII> q;
    q.push(MP(st, 0));
    while (!q.empty()) {
        PII t = q.front(); q.pop();
        int tx = t.first / m;
        int ty = t.first % m;
        int cnt = t.second;
        vis[tx][ty] = 1;
        if (mp[tx][ty] == 'E') return cnt;
        for (int i = 0; i < 4; i++) {
            int nx = tx + dx[i];
            int ny = ty + dy[i];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
            if (vis[nx][ny] || mp[nx][ny] == '#') continue;
            q.push(MP(nx * m + ny, cnt + 1));
        }
    }
    return -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &n, &m);
        string s;
        for (int i = 0; i < n; i++) {
            cin >> s;
            for (int j = 0; j < m; j++) {
                mp[i][j] = s[j];
                if (s[j] == 'S') st = i * m + j;
            }
        }
        printf("%d\n", solve());
    }

    return 0;
}
/**************************************************************
    Problem: 1021
    User: 14123090
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1592 kb
****************************************************************/
