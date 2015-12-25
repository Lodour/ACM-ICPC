#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define mp make_pair
#define pb push_back
typedef pair<int, int> PII;
typedef vector<PII> VII;
#define set(a,b) memset(a,b,sizeof(a))
const int N = 40010;
VII G[N];
bool vis[N];
int dis[N];

void dfs(int u) {
	for (int i = 0; i < (int)G[u].size(); i++) {
		int &v = G[u][i].X;
		int &d = G[u][i].Y;
		if (!vis[v]) {
			vis[v] = 1;
			dis[v] = dis[u] ^ d;
			dfs(v);
		}
	}
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t, cnt = 0;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) G[i].clear();
		for (int i = 0; i < n - 1; i++) {
			int u, v, d;
			scanf("%d%d%d", &u, &v, &d);
			G[u].pb(mp(v, d));
			G[v].pb(mp(u, d));
		}
		set(dis, 0); set(vis, 0);
		dfs(1);
		printf("Case %d:\n", ++cnt);
		while (m--) {
			int u, v;
			scanf("%d%d", &u, &v);
			printf("%d\n", dis[u]^dis[v]);
		}
	}

	return 0;
}
