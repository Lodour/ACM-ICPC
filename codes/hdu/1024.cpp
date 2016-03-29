#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))
#define inf 40000000000LL;
typedef long long ll;
const int N = 1000000 + 100;
ll dp[N], pre[N], a[N];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n, m;
	while (~scanf("%d%d", &m, &n)) {
		for (int i = 1; i <= n; i++)
			scanf("%lld", a + i);
		set(dp, 0); set(pre, 0);
		ll MAX;
		for (int i = 1; i <= m; i++) {
			MAX = -inf;
			for (int j = i; j <= n; j++) {
				dp[j] = max(dp[j - 1], pre[j - 1]) + a[j];
				pre[j - 1] = MAX;
				MAX = max(MAX, dp[j]);
			}
		}
		printf("%lld\n", MAX);
	}

	return 0;
}
