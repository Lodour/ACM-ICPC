#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;
#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef pair<int, int> PII;

const int MAXN = 100010;
int fa[MAXN], ra[MAXN];
void init(int n) {
    for (int i = 0; i <= n; i++) {
        fa[i] = i; ra[i] = 0;
    }
}
int find(int x) {
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}
void unite(int x, int y) {
    x = find(x); y = find(y); if (x == y) return;
    if (ra[x] < ra[y]) fa[x] = y;
    else {
        fa[y] = x; if (ra[x] == ra[y]) ra[x]++;
    }
}
bool same(int x, int y) {
    return find(x) == find(y);
}

vector<pair<int, PII> > G;
void add_edge(int u, int v, int d) {
    G.pb(mp(d, mp(u, v)));
}
int Kruskal(int n) {
    init(n);
    sort(G.begin(), G.end());
    int m = G.size();
    int num = 0, ret = 0;
    for (int i = 0; i < m; i++) {
        pair<int, PII> p = G[i];
        int x = p.Y.X;
        int y = p.Y.Y;
        int d = p.X;
        if (!same(x, y)) {
            unite(x, y);
            num++;
            ret += d;
        }
        if (num == n - 1) break;
    }
    return ret;
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) == 1 && n) {
        G.clear();
        int a, b, c;
        int cnt = n * (n - 1) / 2;
        while (cnt--) {
            scanf("%d%d%d", &a, &b, &c);
            add_edge(a, b, c);
        }
        printf("%d\n", Kruskal(n));
    }

    return 0;
}