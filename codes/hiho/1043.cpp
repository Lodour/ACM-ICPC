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
		for (int j = w[i]; j <= m; j++)
			dp[j] = max(dp[j], dp[j - w[i]] + v[i]);
	printf("%d\n", dp[m]);

	return 0;
}


