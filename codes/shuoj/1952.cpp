#include <bits/stdc++.h>
using namespace std;

const int N = 100010;
int f[N], g[N];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		int n, q, x, y;
		scanf("%d%d", &n, &q);
		for (int i = 0; i < n; i++) {
			scanf("%d", &x);
			f[i + 1] = f[i] + (x & 1);
			g[i + 1] = g[i] + (x & 1 ^ 1);
		}
		while (q--) {
			scanf("%d%d", &x, &y);
			printf("%lld\n", 1LL * (f[y] - f[x - 1]) * (g[y] - g[x - 1]));
		}
	}

	return 0;
}
