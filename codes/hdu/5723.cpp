#include <algorithm>
#include <iostream>
#include <cstring>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define X first
#define eps 1e-8
#define Y second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;
const ll iinf = 1LL << 60;
#define inf 0x3f3f3f3f
#define SZ(x) ((int)(x).size())
#define MO(a,b) (((a)%(b)+(b))%(b))
#define all(x) (x).begin(),(x).end()
#define set(a,x) memset(a, x, sizeof(a))
#define rep(i,a,n) for (int i=(int)(a);i<(int)(n);i++)
#define per(i,a,n) for (int i=(int)(n)-1;i>=(int)(a);i--)
#define out(x) cout << #x << ": " << x << endl;
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// head
const int N = 1e5 + 100;
int n, vis[N], cnt[N];
double  dp[N];
vector<PII> V[N];

// 并查集
int fa[N], ra[N];
void init() {
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

// 生成树
vector<pair<int, PII> > G;
void add_edge(int u, int v, int d) {
	G.pb(mp(d, mp(u, v)));
}
ll Kruskal() {
	init();
	sort(G.begin(), G.end());
	int m = G.size();
	ll num = 0, ret = 0;
	for (int i = 0; i < m; i++) {
		pair<int, PII> p = G[i];
		int x = p.Y.X;
		int y = p.Y.Y;
		int d = p.X;
		if (!same(x, y)) {
			unite(x, y);
			num++;
			ret += d;
			V[x].pb(mp(y, d));
			V[y].pb(mp(x, d));
		}
		if (num == n - 1) break;
	}
	return ret;
}

// dfs
void dfs(int rt, int fa) {
	cnt[rt] = 1;
	rep(i, 0, SZ(V[rt])) {
		int son = V[rt][i].X;
		int w = V[rt][i].Y;
		if (son == fa) continue;
		dfs(son, rt);
		cnt[rt] += cnt[son];
		dp[rt] += dp[son] + 1.0 * w * cnt[son] * (n - cnt[son]);
	}
}

int main() {
#ifdef MANGOGAO
	freopen("/Users/Lodour/Documents/ACM/2016年杭电多校联合赛/#1/数据/1001.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		int m;
		scanf("%d%d", &n, &m);
		G.clear();
		rep(i, 0, n) V[i].clear();

		while (m--) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			u--; v--;
			add_edge(u, v, w);
		}
		ll ans = Kruskal();
		set(vis, 0); set(dp, 0);
		dfs(0, -1);
		double s = 1LL * n * (n - 1) / 2;
		printf("%lld %.2f\n", ans, dp[0] / s);
	}

	return 0;
}
