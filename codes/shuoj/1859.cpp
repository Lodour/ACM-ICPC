#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int h[111];
int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	int n;
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++)
			scanf("%d", &h[i]);
		sort(h, h + n);
		for (int i = 0; i < n; i++)
			printf("%d%c", h[i], (i == n - 1) ? '\n' : ' ');
	}

	return 0;
}
