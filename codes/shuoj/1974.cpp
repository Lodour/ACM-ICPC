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

	int n, k;
	scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n);
	int ans = 0, pos;
	for (int i = n; i >= 1; i--) {
		int d = a[i] * min(k, n - i + 1);
		if (d > ans) {
			ans = d;
			pos = i;
		}
	}
	printf("%d %d\n", a[pos], ans);

	return 0;
}
