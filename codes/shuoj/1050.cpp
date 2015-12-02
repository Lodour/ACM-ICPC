#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int a[30030];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int w, n;
	scanf("%d%d", &w, &n);
	int ans = n;
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	sort(a, a + n);
	for (int i = 0, j = n - 1; i < j; i++, j--)
		if (a[i] + a[j] <= w) ans--;
		else i--;
	printf("%d\n", ans);
	return 0;
}
