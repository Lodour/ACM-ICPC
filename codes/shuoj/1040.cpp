#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n, m, a[10010];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	while (m--)
		next_permutation(a, a + n);
	for (int i = 0; i < n; i++)
		printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');

	return 0;
}
