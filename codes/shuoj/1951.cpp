#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))

int a[1010];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		set(a, 0);
		long long ans = 0;
		int cnt = k, tot = 0, pos = -1;
		int p, q;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &p, &q);
			a[p] += q; tot += q;
			pos = max(pos, p);
		}
		while (tot--) {
			while (!a[pos]) pos--;
			a[pos]--;
			if (cnt == k) {
				ans += 2 * pos;
				cnt = 0;
			}
			cnt++;
		}
		printf("%lld\n", ans);
	}

	return 0;
}
