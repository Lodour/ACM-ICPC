#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int a[250], dp[250][250];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}
	for (int l = 1; l <= n; l++) {
		for (int i = 0; i < 2 * n; i++) {
			int j = i + l;
			if (j < 2 * n) {
				for (int k = i + 1; k < j; k++)
					dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + a[i] * a[k] * a[j]);
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i][i + n]);
	printf("%d\n", ans);

	return 0;
}
