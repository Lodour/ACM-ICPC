#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int inf = 0x3f3f3f3f;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n, k, a[1010];
	while (~scanf("%d%d", &n, &k)) {
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		double ans = inf;
		double sx2 = 0.0, sx = 0.0;
		for (int i = 0; i < k; i++) {
			sx2 += a[i] * a[i];
			sx += a[i];
		}
		for (int i = 0; i <= n - k; i++) {
			ans = min(ans, sx2 / k - sx * sx / k / k);
			sx2 = sx2 - a[i] * a[i] + a[i + k] * a[i + k];
			sx = sx - a[i] + a[i + k];
		}
		printf("%.2lf\n", ans);
	}
	return 0;
}