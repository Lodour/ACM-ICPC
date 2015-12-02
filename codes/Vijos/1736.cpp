#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 10010;
int a[N], b[N], l[N], h[N];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d%d", &a[i], &b[i], &l[i], &h[i]);
	}
	int sx, sy, ans = -1;
	scanf("%d%d", &sx, &sy);
	for (int i = 0; i < n; i++)
		if (sx >= a[i] && sy >= b[i] && sx <= (a[i] + l[i]) && sy <= (b[i] + h[i]))
			ans = i + 1;
	printf("%d\n", ans);

	return 0;
}
