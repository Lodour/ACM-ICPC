#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))

int mp[55][55], dp[3000], mi[3000], mj[3000];

int dis(int i, int j) {
	int b = abs(mi[i] - mi[j]) + abs(mj[i] - mj[j]);
	return b * b;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%d", &mp[i][j]);
			mi[mp[i][j]] = i;
			mj[mp[i][j]] = j;
		}
	for (int i = 1; i <= n * n; i++) {
		dp[i] = dis(1, i);
		for (int j = 2; j < i; j++)
			dp[i] = max(dp[i], dp[j] + dis(i, j));
	}
	printf("%d\n", dp[n * n]);

	return 0;
}
