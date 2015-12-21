#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[15];
int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		int t;
		scanf("%d", &t);
		a[t]++;
	}
	ll ans = 0;
	for (int i = 1; i <= m; i++)
		ans += a[i] * (n - a[i]);
	printf("%I64d\n", ans / 2);

	return 0;
}