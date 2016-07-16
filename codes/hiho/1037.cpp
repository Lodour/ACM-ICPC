#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int a[111][111];
int dp[111][111];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			scanf("%d", &a[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + a[i][j];
	int res = -1;
	for (int i = 1; i <= n; i++)
		res = max(res, dp[n][i]);
	printf("%d\n", res);
	return 0;
}