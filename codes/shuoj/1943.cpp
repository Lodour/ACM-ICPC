#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))

#define N 100100
int a[N], b[N], f[N], lis[N];

// a: -7 10 9 2 3 8 8 1
// b: -7 2  3 8
// f: 1  2  2 2 3 4 4 2


int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n, len, pos;
	while (~scanf("%d", &n)) {
		set(b, 0); set(f, 0); set(lis, 0);
		for (int i = 1; i <= n; i++)
			scanf("%d", &a[i]);
		b[f[1] = len = 1] = a[1];
		for (int i = 2; i <= n; i++) {
			if (a[i] > b[len]) b[f[i] = ++len] = a[i];
			else b[f[i] = lower_bound(b + 1, b + len + 1, a[i]) - b] = a[i];
		}
		for (int i = n, t = len; i >= 1 && t >= 1; i--)
			if (f[i] == t) lis[--t] = a[i];
		for (int i = 0; i < len; i++)
			printf("%d%c", lis[i], i == len - 1 ? '\n' : ' ');
	}

	return 0;
}
