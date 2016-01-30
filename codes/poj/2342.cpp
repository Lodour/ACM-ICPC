#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))
const int N = 6666;
int n, fa[N], vis[N];
int dp[N][2];

void dfs(int u) {
	vis[u] = 1;
	for (int v = 0; v < n; v++)
		// v是u的儿子
		if (!vis[v] && fa[v] == u) {
			dfs(v);
			dp[u][1] += dp[v][0];
			dp[u][0] += max(dp[v][0], dp[v][1]);
		}
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	while (~scanf("%d", &n)) {
		// Init
		set(vis, 0); set(dp, 0); set(fa, -1);
		// Input
		for (int i = 0; i < n; i++)
			scanf("%d", &dp[i][1]);
		int l, k, root;
		// while (scanf("%d%d", &l, &k) && l && k) { --->Runtime Error
		while (scanf("%d%d", &l, &k) , l || k) {
			l--; k--;
			root = fa[l] = k;
		}
		// Find root
		while (fa[root] != -1)
			root = fa[root];
		// Dp
		dfs(root);
		// Output
		printf("%d\n", max(dp[root][0], dp[root][1]));
	}


	return 0;
}
