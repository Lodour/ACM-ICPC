#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

bool solve(int n) {
	if (n <= 1) return 0;
	if (n <= 3) return 1;
	int h = sqrt(1.0 * n);
	for (int i = 2; i <= h; i++)
		if (n % i == 0)return 0;
	return 1;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	while (~scanf("%d", &t)) {
		int ans = 0;
		while (t--) {
			int n;
			scanf("%d", &n);
			ans += solve(n);
		}
		printf("%d\n", ans);
	}

	return 0;
}
