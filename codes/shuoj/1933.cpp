#include <bits/stdc++.h>
using namespace std;

int a[1010];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n, s;
	while (~scanf("%d%d", &n, &s)) {
		for (int i = 0; i < n; i++)
			scanf("%d", a + i);
		sort(a, a + n);
		bool ans = 0;
		for (int i = 0; !ans && i < n; i++)
			for (int j = i + 1; !ans && j < n; j++) {
				if (a[i] == a[j]) continue;
				int c = s - a[i] - a[j];
				int *x = lower_bound(a, a + n, c);
				if (*x == c && c != a[i] && c != a[j]) ans = 1;
			}
		puts(ans ? "YES" : "NO");
	}

	return 0;
}
