#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <sstream>
#include <queue>
#include <stack>
#include <string>
#include <functional>
#include <set>
#include <map>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
using namespace std;
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REP2(X,L,R) for(int X=(int)L;X<=(int)R;X++)
#define DEP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define DEP2(X,L,R) for(int X=(int)L;X>=(int)R;X--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define CLR(A,X) memset(A,X,sizeof(A))
#define ALL(container) (container).begin(), (container).end()
#define sz(container) ((int)container.size())
#define UNIQUE(v) sort(ALL(v)); v.erase( unique(v.begin(), v.end()), v.end() );
#define IT iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define fi first
#define se second
const double EPS = 1e-8;
const int MOD = 1000000007;
#define debug(x) cout<<#x<<": "<<x<<endl;
#define debug2(x,y) cout<<#x<<": "<<x<<"\t"<<#y<<": "<<y<<endl;
//************************************************
const int MAXN = 100010;
int pa[MAXN];
int ra[MAXN];
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
typedef pair<int, int> PII;
vector<pair<int, PII> > G;
void init_G() {
    G.clear();
}
void add_edge(int u, int v, int d) {
    G.push_back(make_pair(d, make_pair(u, v)));
}
int Kruskal(int n) {
    init(n);
    sort(G.begin(), G.end());
    int m = G.size();
    int num = 0, ret = 0;
    for (int i = 0; i < m; i++) {
        pair<int, PII> p = G[i];
        int x = p.second.first;
        int y = p.second.second;
        int d = p.first;
        if (unite(x, y)) {
            num++;
            ret += d;
        }
        if (num == n - 1)break;
    }
    if (num != n - 1) return -1;
    return ret;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int n, m;
    while (scanf("%d%d", &m, &n) == 2 && m) {
        init_G();
        int a, b, c;
        while (m--) {
            scanf("%d%d%d", &a, &b, &c);
            add_edge(a, b, c);
            add_edge(b, a, c);
        }
        int ans = Kruskal(n);
        if (ans == -1) puts("?");
        else printf("%d\n", ans);
    }

    return 0;
}