#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);

const int N = 222;
int n, tot;
int fa[N], vis[N];
int dp[N][2];
bool dp2[N][2];

map<string, int> f;

int num(const string &s) {
	int r = f[s];
	return r ? r : f[s] = tot++;
}

void dfs(int u) {
	vis[u] = 1;
	for (int v = 1; v <= n; v++)
		if (!vis[v] && fa[v] == u) {
			dfs(v);
			dp[u][1] += dp[v][0];
			dp2[u][1] |= dp2[v][0];
			dp[u][0] += max(dp[v][0], dp[v][1]);
			dp2[u][0] |= dp[v][0] == dp[v][1];
		}
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	fastin;
	while (cin >> n && n) {
		// Init
		f.clear();
		set(fa, -1); set(vis, 0); set(dp2, 0);
		tot = 1;
		for (int i = 1; i <= n; i++) {
			dp[i][0] = 0;
			dp[i][1] = 1;
		}
		// Input
		int root;
		string s, t;
		cin >> s;
		f[s] = tot++;
		for (int i = 0; i < n - 1; i++) {
			cin >> s >> t;
			root = fa[num(s)] = num(t);
		}
		// Find root
		while (fa[root] != -1) root = fa[root];
		// Dp
		dfs(root);
		// Output
		cout << max(dp[root][0], dp[root][1]) << " ";
		bool flag = 0;
		if (dp[root][0] < dp[root][1]) flag = dp2[root][1];
		if (dp[root][0] > dp[root][1]) flag = dp2[root][0];
		if (dp[root][0] == dp[root][1]) flag = 1;
		cout << (flag ? "No" : "Yes") << endl;
	}

	return 0;
}
