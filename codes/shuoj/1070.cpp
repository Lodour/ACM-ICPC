#include <iostream>
#include <cstdio>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n, dp[31] = {0, 1, 2, 4};
	for (int i = 4; i < 31; i++)
		dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
	while (scanf("%d", &n) && n)
		printf("%d\n", dp[n]);

	return 0;
}
