#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))

int a[150], dp1[150], dp2[150];

void LIS(int v[], int dp[], int n) {
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
	}
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	LIS(a, dp1, n);
	reverse(a, a + n);
	LIS(a, dp2, n);
	reverse(dp2, dp2 + n);
	for (int i = 0; i < n; i++)
		ans = max(ans, dp1[i] + dp2[i] - 1);
	printf("%d\n", n - ans);

	return 0;
}
