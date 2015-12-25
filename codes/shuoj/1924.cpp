#include <bits/stdc++.h>
using namespace std;

int a[1010];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n, k;
	while (~scanf("%d%d", &n, &k)) {
		for (int i = 0; i < n; i++)
			scanf("%d", a + i);
		sort(a, a + n);
		double ans = -1u >> 1;
		double sx = 0, sx2 = 0;
		for (int i = 0; i < k; i++) {
			sx += a[i];
			sx2 += a[i] * a[i];
		}
		for (int i = 0; i + k <= n; i++) {
			ans = min(ans, sx2 / k - sx * sx / k / k);
			sx += a[i + k] - a[i];
			sx2 += a[i + k] * a[i + k] - a[i] * a[i];
		}
		printf("%.2lf\n", ans);
	}

	return 0;
}
