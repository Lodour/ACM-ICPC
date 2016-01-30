#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back

const int N = 222;
int n, m;
int dp[N][N];	// dp[i][j] = 以i为根的子树中选j个节点
vector<int> son[N];

void dfs(int u, int cnt) {
	for (int i = 0; i < (int)son[u].size(); i++) {
		int v = son[u][i];
		// 继续取
		if (cnt > 1) dfs(v, cnt - 1);
		// 背包 dp[u][j] = max{dp[u][j], dp[u][k] + dp[v][j-k]}
		for (int j = cnt; j >= 1; j--)
			for (int k = 1; k <= j; k++)
				dp[u][j] = max(dp[u][j], dp[u][k] + dp[v][j - k]);
	}
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	while (~scanf("%d%d", &n, &m), n || m) {
		// Init
		for (int i = 0; i <= n; i++)
			son[i].clear();
		set(dp, 0);
		// Input
		int v;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &v, &dp[i][1]);
			son[v].pb(i);
		}
		// dp
		dfs(0, m + 1);
		// Output
		printf("%d\n", dp[0][m + 1]);
	}

	return 0;
}
