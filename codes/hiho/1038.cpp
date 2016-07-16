#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;
const int N = 555;
const int M = 100100;
int w[N], v[N];
int dp[M];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		scanf("%d%d", &w[i], &v[i]);
	for (int i = 1; i <= n; i++)
		for (int j = m; j >= w[i]; j--)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	int res = 0;
	for (int i = 0; i <= m; i++)
		res = max(res, dp[i]);
	printf("%d\n", res);

	return 0;
}