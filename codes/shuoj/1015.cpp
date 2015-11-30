#include <iostream>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))
int n, m, a[55], f[55][55][10], g[55][55][10];
#define mod(i,j) (i<=j?((a[j]-a[i-1])%10+10)%10:((a[n]-a[i-1]+a[j])%10+10)%10)

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i] += a[i - 1];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j][0] = g[i][j][0] = mod(i, j);
	int amin = -1u >> 1, amax = 0;
	for (int k = 1; k < m; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if ((n + j - i) % n >= k) {
					amin = -1u >> 1; amax = 0;
					for (int l = 0; l < (n + j - i) % n; l++) {
						amin = min(amin, mod(i, (i + l - 1) % n + 1) * f[(i + l) % n + 1][j][k - 1]);
						amax = max(amax, mod(i, (i + l - 1) % n + 1) * g[(i + l) % n + 1][j][k - 1]);
					}
					f[i][j][k] = amin;
					g[i][j][k] = amax;
				}
	amin = f[1][n][m - 1];
	amax = g[1][n][m - 1];
	for (int i = 2; i <= n; i++) {
		amin = min(amin, f[i][i - 1][m - 1]);
		amax = max(amax, g[i][i - 1][m - 1]);
	}
	printf("%d\n%d\n", amin, amax);
	return 0;
}
