#include <bits/stdc++.h>
using namespace std;
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
#define set(a,b) memset(a,b,sizeof(a))

const int N = 1111;
int a[N], b[N], tot[10], cnt[10];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n, kase = 0;
	while (scanf("%d", &n) && n) {
		printf("Game %d:\n", ++kase);

		set(tot, 0);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			tot[a[i]]++;
		}

		for (;;) {
			int p = 0, q = 0;
			set(cnt, 0);
			for (int i = 0; i < n; i++) {
				scanf("%d", &b[i]);
				if (a[i] == b[i]) p++;
				cnt[b[i]]++;
			}
			if (!b[0]) break;
			for (int i = 1; i < 10; i++)
				q += min(tot[i], cnt[i]);
			printf("    (%d,%d)\n", p, q - p);
		}
	}

	return 0;
}
