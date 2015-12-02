#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

#define set(a,b) memset(a,b,sizeof(a))
#define mod(a) (((a)%10+10)%10)

int a[150], s[150], f[150][50], g[150][50];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		a[i + n] = a[i];
	}
	for (int i = 1; i <= n * 2; i++)
		s[i] = mod(s[i - 1] + a[i]);
	int ff = -1u >> 1, gg = 0;
	for (int h = 1; h <= n; h++) {
		set(f, 0x3f); set(g, 0);
		for (int i = h; i < h + n; i++)
			f[i][1] = g[i][1] = mod(s[i] - s[h - 1]);
		for (int i = h; i < h + n; i++)
			for (int j = 2; j <= m && j <= i - h + 1; j++)
				for (int k = h; k < i; k++) {
					if (k - h + 1 < j - 1) continue;	// 需要保证dp子结构是有意义的
					f[i][j] = min(f[i][j], f[k][j - 1] * mod(s[i] - s[k]));
					g[i][j] = max(g[i][j], g[k][j - 1] * mod(s[i] - s[k]));
				}
		ff = min(ff, f[h + n - 1][m]);
		gg = max(gg, g[h + n - 1][m]);
	}
	printf("%d\n%d\n", ff, gg);

	return 0;
}
