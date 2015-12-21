#include <bits/stdc++.h>
using namespace std;

int a[100010];
int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", a + i);
	sort(a, a + n);
	for (int i = n - 1; i >= 0; i--) {
		m -= a[i];
		if (m <= 0) {
			printf("%d\n", n - i);
			return 0;
		}
	}

	return 0;
}