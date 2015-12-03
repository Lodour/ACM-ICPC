#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))

#define N 600
int a[N], b[N], dp[N][N];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m, ans = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		scanf("%d", &m);
		for (int i = 1; i <= m; i++)
			scanf("%d", &b[i]);
		set(dp, 0);
		// dp[i][j] = dp[i-1][j] (a[i]!=b[j])
		// dp[i][j] = max{dp[i-1][k]|k in range(1,j) && b[k]<b[j]} + 1 (b[i]==b[j])
		// ans = dp[n][m]
		for (int i = 1; i <= n; i++) {
			int Max = 0;
			for (int j = 1; j <= m; j++) {
				dp[i][j] = dp[i - 1][j];
				if (a[i] > b[j]) Max = max(Max, dp[i - 1][j]);
				if (a[i] == b[j]) dp[i][j] = Max + 1;
			}
		}
		for (int i = 1; i <= m; i++)
			ans = max(ans, dp[n][i]);
		printf("%d\n", ans);
	}

	return 0;
}
