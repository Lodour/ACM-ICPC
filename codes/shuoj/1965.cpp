#include <iostream>
#include <cstdio>
using namespace std;
//************************************************

const int maxn = 91;
long long dp[91] = {0, 0, 0, 0, 0};

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	for (int i = 5; i < maxn; i++)
		dp[i] = dp[i - 2] + dp[i - 1] + (i & 1);

	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%lld\n", dp[n]);
	}

	return 0;
}
