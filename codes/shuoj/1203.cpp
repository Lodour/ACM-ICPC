#include <iostream>
#include <cstdio>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int a, b;
	while (scanf("%d%d", &a, &b) && a && b) {
		a *= 100;
		int cnt = 0;
		for (int i = 0; i < 100; i++)
			if ((a + i) % b == 0) {
				if (cnt++) putchar(' ');
				printf("%d%d", i / 10, i % 10);
			}
		puts("");
	}

	return 0;
}
