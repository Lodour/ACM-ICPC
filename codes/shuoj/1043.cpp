#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int t[110], v[110], dp[1111];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++)
		scanf("%d%d", &t[i], &v[i]);
	for (int i = 0; i < m; i++) {
		for (int j = n - t[i]; j > 0; j--)
			if (dp[j])
				dp[j + t[i]] = max(dp[j + t[i]], dp[j] + v[i]);
		dp[t[i]] = max(dp[t[i]], v[i]);
	}
	printf("%d\n", *max_element(dp, dp + n + 1));

	return 0;
}
