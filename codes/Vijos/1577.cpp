#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))

#define N 10010
int a[N], dp[N];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++) {
		dp[i] = 1;
		for (int j = 1; j < i; j++) {
			if (dp[j] % 2 == 0 && a[i] > a[j])
				dp[i] = max(dp[i], dp[j] + 1);
			if (dp[j] % 2 == 1 && a[i] < a[j])
				dp[i] = max(dp[i], dp[j] + 1);
		}
		ans = max(ans, dp[i]);
	}
	printf("%d\n", ans);
	return 0;
}
