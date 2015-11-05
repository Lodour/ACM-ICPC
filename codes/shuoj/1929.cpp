#include <cstdio>
#include <vector>
#include <algorithm>
#include <cstring>
#include <map>
#include <queue>
using namespace std;

#define mp make_pair
#define pb push_back
#define X first
#define Y second
typedef pair<int, int> PII;

const int N = 111;
int ans[N], deg[N];
vector<PII> G[N];
map<PII, bool> vis;

void init(int n) {
	for (int i = 0; i < n; i++)
		G[i].clear();
	memset(ans, 0, sizeof(ans));
	memset(ans, 0, sizeof(deg));
	vis.clear();
	ans[n] = 0;
}

void add_edge(int a , int b, int x) {
	if (vis[mp(b, a)]) {
		for (int i = 0; i < G[b].size(); i++) {
			if (G[b][i].X == a) {
				G[b][i].Y = max(G[b][i].Y, x);
				break;
			}
		}
	}
	else {
		vis[mp(b, a)] = 1;
		G[b].pb(mp(a, x));
		deg[a]++;
	}
}

void bfs(int n) {
	queue<int> Q;
	for (int i = 0; i < n; i++)
		if (deg[i] == 0)
			Q.push(i);
	while (!Q.empty()) {
		int t = Q.front(); Q.pop();
		for (int i = 0; i < G[t].size(); i++) {
			int x = G[t][i].X;
			ans[x] = max(ans[x], G[t][i].Y + ans[t]);
			if (--deg[x] == 0) Q.push(x);
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		int n, p, q;
		scanf("%d%d%d", &n, &p, &q);
		init(n);
		while (p--) {
			int a, x;
			scanf("%d%d", &a, &x);
			a--;
			ans[a] = max(x, ans[a]);
		}
		while (q--) {
			int a, b, x;
			scanf("%d%d%d", &a, &b, &x);
			add_edge(a - 1, b - 1, x);

		}
		bfs(n);
		printf("%d\n", ans[0]);
	}

	return 0;
}
