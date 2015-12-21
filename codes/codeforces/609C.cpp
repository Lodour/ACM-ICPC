#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int a[100010];
int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	ll s = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		s += a[i];
	}
	sort(a, a + n);
	int pos = n - s % n;
	ll ans = 0;
	int ave = s / n;
	for (int i = 0; i < pos; i++)
		ans += abs(a[i] - ave);
	ave = (s + n - 1) / n;
	for (int i = pos; i < n; i++)
		ans += abs(a[i] - ave);
	printf("%I64d\n", ans / 2);

	return 0;
}