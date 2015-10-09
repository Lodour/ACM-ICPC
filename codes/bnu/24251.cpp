#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int n, m, Q, q;
		scanf("%d%d%d", &n, &m, &Q);
		if (n > m) swap(n, m);

		printf("Case #%d:\n", t);
		while (Q--) {
			scanf("%d", &q);
			if (q > n + m || q < 2) puts("0");
			else printf("%d\n", min(q - 1, m) - max(q - n, 1) + 1);
		}
	}

	return 0;
}
