#include <bits/stdc++.h>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);
#define N 1010

char mp[N][N];
int dp[N][N], ans[N][N];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t; scanf("%d", &t);
	while (t--) {
		int n, m; set(ans, 0);
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%s", mp[i] + 1);
		set(dp, 0);	// from right to left
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++)
				if (mp[i][j] == '.')
					ans[i - 1][j - 1] += (dp[i][j] = dp[i][j - 1] + 1);
		set(dp, 0);	// from down to up
		for (int j = 1; j <= m; j++)
			for (int i = 1; i <= n; i++)
				if (mp[i][j] == '.')
					ans[i - 1][j - 1] += (dp[i][j] = dp[i - 1][j] + 1);
		set(dp, 0);	// from left to right
		for (int i = n; i >= 1; i--)
			for (int j = m; j >= 1; j--)
				if (mp[i][j] == '.')
					ans[i - 1][j - 1] += (dp[i][j] = dp[i][j + 1] + 1);
		set(dp, 0);	// from up to down
		for (int j = m; j >= 1; j--)
			for (int i = n; i >= 1; i--)
				if (mp[i][j] == '.')
					ans[i - 1][j - 1] += (dp[i][j] = dp[i + 1][j] + 1);
		int res = *max_element(&ans[0][0], &ans[n][m - 1]);
		res = res == 0 ? 0 : res - 4;
		printf("%d\n", res);
	}

	return 0;
}
