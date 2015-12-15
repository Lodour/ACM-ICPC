#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n, dp[60] = {0, 1, 1};
	scanf("%d", &n);
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + dp[i - 3] + 1;
	printf("%d\n", dp[n]);

	return 0;
}
