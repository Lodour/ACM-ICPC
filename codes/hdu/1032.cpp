#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))

const int N = 1e6 + 10;
int dp[N];
map<int, bool> vis;

int solve(int n) {
	if (dp[n]) return dp[n];
	int rt = 0, nn = n;
	while (!vis[nn]) {
		vis[nn] = 1;
		nn = nn & 1 ? 3 * nn + 1 : nn >> 1;
		rt++;
	}
	return dp[n] = rt;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n, m;
	while (~scanf("%d%d", &n, &m)) {
		printf("%d %d ", n, m);
		if (n > m) swap(n, m);
		int ans = 0;
		for (int i = n; i <= m; i++) {
			vis.clear();
			ans = max(ans, solve(i));
		}
		printf("%d\n", ans);
	}

	return 0;
}
