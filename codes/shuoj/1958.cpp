#include <bits/stdc++.h>
using namespace std;

int solve(int a, int b) {
	if (b == 0) return a;
	if (a != 2) return (b & 1) ? 2 : 1;
	return (b & 1) ? 1 : 2;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	while (n--) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", solve(a, b));
	}

	return 0;
}
