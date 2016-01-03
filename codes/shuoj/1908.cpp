#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	ll dp[21] = {0, 0, 1};
	for (int i = 3; i < 21; i++)
		dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]);
	while (~scanf("%d", &n))
		printf("%lld\n", dp[n]);
	return 0;
}
