#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))

#define N 2500
int a[N], dp[N];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n, t, ans = 0;
	scanf("%d%d", &n, &t);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if ((dp[j] - 1) % (2 * t) < t && a[j] > a[i])
				dp[i] = max(dp[i], dp[j] + 1);
			if ((dp[j] - 1) % (2 * t) >= t && a[j] < a[i])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);

	return 0;
}
