#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a));
const int N = 1010;
char mp[N][N];
bool rg[N], cg[N];
int gx[N], gy[N];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		int tot = 0;
		int s = 0;
		set(rg, 0); set(cg, 0);
		for (int i = 0; i < n; i++) {
			scanf("%s", mp[i]);
			for (int j = 0; j < m; j++)
				if (mp[i][j] == 'G') {
					gx[tot] = i;
					gy[tot++] = j;
					s += m - j - 1;
					rg[i] = cg[j] = 1;
					break;
				}
		}
		int ans = 0;
		// row
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (i != j) ans += (m - rg[i]) * (m - rg[j]);
		// col
		for (int i = 0; i < m; i++)
			for (int j = 0; j < m; j++)
				if (i != j) ans += (n - cg[i]) * (n - cg[j]);
		// g
		int d = 0;
		for (int i = 0; i < tot; i++) {
			d += gx[i] * (m - gx[i] - 1);
			d += gy[i] * (n - gy[i] - 1);
			if (i && gx[i] == gx[i - 1] + 1)
				d += min(gy[i], gy[i - 1]) * (m - max(gy[i] + 1, gy[i - 1] + 1));
		}
		ans += d * 4;
		int cnt = n * m - tot;
		printf("%.4f\n", ans * 1.0 / (cnt * (cnt - 1) + cnt));
	}
	return 0;
}
