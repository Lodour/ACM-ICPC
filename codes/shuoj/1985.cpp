#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	while (~scanf("%d", &n)) {
		int a[25] = {0};
		for (int i = 0; i < n; i++)
			scanf("%d", a + i);
		sort(a, a + n);
		int ans = 0;
		while (n > 3) {
			int t1 = a[1] + a[0] + a[n - 1] + a[1];
			int t2 = a[n - 1] + a[0] + a[n - 2] + a[0];
			ans += min(t1, t2);
			n -= 2;
		}
		if (n == 3) ans += a[0] + a[1] + a[2];
		if (n == 2) ans += a[1];
		if (n == 1) ans += a[0];
		printf("%d\n", ans);
	}

	return 0;
}
