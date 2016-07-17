#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <functional>
#include <cstdlib>
#include <climits>
#include <cctype>
using namespace std;
#define REP(i,x) for(int i = 0; i < (int)(x); i++)
#define DEP(i,x) for(int i = (int)(x) - 1; i >= 0; i--)
#define FOR(i,x) for(__typeof(x.begin())i=x.begin(); i!=x.end(); i++)
#define set(a,x) memset(a, x, sizeof(a))
#define mo(a,b) (((a)%(b)+(b))%(b))
#define all(x) (x).begin(), (x).end()
#define sz(v) ((int)v.size())
#define UNIQUE(v) sort(all(v)); v.erase(unique(all(v)), v.end())
#define out(x) cout << #x << ": " << x << endl;
#define zero(x) (fabs(x)<eps?1:0)
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);
#define pq priority_queue
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
#define inf 0x3f3f3f3f
#define eps 1e-8
#define mod 1000000007
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define IT iterator
#define X first
#define Y second
#define lson rt<<1
#define rson rt<<1|1
// ************************************************************************

const int N = 2222;
int n, fa[N], ra[N];
void init() {
    for (int i = 0; i < N; i++) {
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


struct Node {
    int u, v, w, id;
    Node(int a, int b, int c, int d) {
        w = a; id = b; u = c; v = d;
    }
    bool operator < (Node &b) {
        return w > b.w;
    }
};
vector<Node> G;

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int m, q;
    scanf("%d%d%d", &n, &m, &q);
    for (int i = 1; i <= m; i++) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        G.pb(Node(w, i, u, v));
    }
    sort(G.begin(), G.end());
    while (q--) {
        init();
        int l, r, ans = -1;
        scanf("%d%d", &l, &r);
        for (auto p : G) {
            if (p.id < l || p.id > r) continue;
            int u = p.u;
            int v = p.v;
            if (same(u, v)) {
                ans = p.w;
                break;
            }
            unite(u, v + n);
            unite(u + n, v);
        }
        printf("%d\n", ans);
    }

    return 0;
}
