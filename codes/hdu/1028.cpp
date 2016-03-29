#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))

int ans;
int dp[150][150];

int dfs(int n, int ma) {
	if (dp[n][ma]) return dp[n][ma];
	// cout << n << " " << ma << endl;
	if (n == 0) return 1;
	int rt = 0;
	for (int i = ma; i >= 1; i--)
		if (n >= i)
			rt += dfs(n - i, i);
	return dp[n][ma] = rt;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n;
	while (~scanf("%d", &n))
		printf("%d\n", dfs(n, n));

	return 0;
}
