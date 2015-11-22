#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	while (~scanf("%d", &n)) {
		int sum, pri, x, y;
		sum = pri = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &x, &y);
			if (y < 0) continue;
			sum += x * (y < 60 ? 0 : min(y / 10 - 5, 4));
			pri += x;
		}
		printf("%.2lf\n", sum * 1.0 / pri);
	}

	return 0;
}