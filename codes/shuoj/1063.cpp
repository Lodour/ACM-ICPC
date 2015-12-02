#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int a, b;
	while (~scanf("%d%d", &a, &b)) {
		printf("%d %d ", a, b);
		if (a > b) swap(a, b);
		int ans = 0;
		for (int i = a; i <= b; i++) {
			int cnt = 0;
			for (int j = i; j != 1; cnt++)
				j = j & 1 ? j * 3 + 1 : j >> 1;
			ans = ans > cnt ? ans : cnt;
		}
		printf("%d\n", ans + 1);
	}

	return 0;
}
