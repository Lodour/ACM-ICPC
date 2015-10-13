#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

bool cmp(int a, int b) {
	return abs(a) > abs(b);
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	int n, a[100];
	while (scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n, cmp);
		for (int i = 0; i < n; i++)
			printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
	}

	return 0;
}
