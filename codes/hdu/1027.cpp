#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n, m;
	int a[1111];
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 0; i < n; i++)
			a[i] = i + 1;
		while (--m)
			next_permutation(a, a + n);
		for (int i = 0; i < n; i++)
			printf("%d%c", a[i], i == n - 1 ? '\n' : ' ');
	}

	return 0;
}
