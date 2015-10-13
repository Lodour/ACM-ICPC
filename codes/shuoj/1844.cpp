#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	while (~scanf("%d", &n)) {
		int a[31], b[31];
		for (int i = 0; i < n; i++)
			scanf("%d", a + i);
		for (int i = 0; i < n; i++)
			scanf("%d", b + i);
		sort(a, a + n);
		sort(b, b + n);
		int ans = 0;
		for (int i = 0; i < n; i++)
			ans += a[i] * b[i];
		printf("%d\n", ans);
	}


	return 0;
}
