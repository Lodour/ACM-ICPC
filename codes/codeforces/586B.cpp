#include <iostream>
#include <cstdio>
using namespace std;

int f[111], g[111], a[2][111], b[111];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < n - 1; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++)
		scanf("%d", &b[i]);
	f[0] = 0; f[1] = a[0][0];
	for (int i = 2; i <= n - 1; i++)
		f[i] = f[i - 1] + a[0][i - 1];
	g[n - 1] = 0; g[n - 2] = a[1][n - 2];
	for (int i = n - 3; i >= 0; i--)
		g[i] = g[i + 1] + a[1][i];

	int ans = 0x3f3f3f3f;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			ans = min(ans, b[i] + b[j] + f[i] + g[i] + f[j] + g[j]);
		}
	printf("%d\n", ans);

	return 0;
}
