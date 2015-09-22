#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int a[400][400], dp[400][400];
int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	int n, ans = 0;
	cin >> n;
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			cin >> a[i][j];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= i; j++)
			dp[i][j] = a[i][j] + max(dp[i - 1][j], dp[i - 1][j - 1]);
	for (int i = 1; i <= n; i++)
		ans = max(ans, dp[n][i]);
	cout << ans << endl;

	return 0;
}