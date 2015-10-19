#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d%d", &a, &b);
		for (int i = 0; i < b; i++)
			for (int j = 0; j < a; j++) {
				if (i != 0 && j == 0) continue;
				int len = min(j, a - j - 1);
				for (int k = 0; k < len; k++)
					putchar(' ');
				putchar('X');
				if (j * 2 + 1 != a) {
					for (int k = 0; k < a - 2 * len - 2; k++)
						putchar(' ');
					putchar('X');
				}
				puts("");
			}
		if (t) puts("");
	}
	return 0;
}
