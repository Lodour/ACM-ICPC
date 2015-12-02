#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int dp[30030];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n, m, v, p;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &v, &p);
		for (int j = n - v; j >= 0; j--)
			dp[j + v] = max(dp[j + v], dp[j] + v * p);
	}
	printf("%d\n", *max_element(dp, dp + n));
	return 0;
}
