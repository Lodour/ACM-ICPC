#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
const int maxn = 5000;
int v[maxn], d[maxn], ans[maxn];
ll p[maxn];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d%lld", &v[i], &d[i], &p[i]);
	int tot = 0;
	for (int i = 0; i < n; i++) {
		if (p[i] < 0) continue;
		ans[tot++] = i;
		ll cnt = v[i], cc = 0;
		int j = i + 1;
		while (j < n) {
			if (p[j] < 0) {
				j++;
				continue;
			}
			p[j] -= cnt + cc;
			if (cnt > 0) cnt--;
			if (p[j] < 0) cc += d[j];
			j++;
		}
	}
	printf("%d\n", tot);
	for (int i = 0; i < tot; i++)
		printf("%d%c", ans[i] + 1, i == tot - 1 ? '\n' : ' ');


	return 0;
}
