#include <iostream>
#include <cstdio>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t, n;
	scanf("%d%d", &t, &n);
	if (n == 10) {
		if (t == 1) {
			puts("-1");
			return 0;
		}
		putchar('1');
		t--;
		n = 0;
	}
	while (t--)
		putchar('0' + n);
	puts("");

	return 0;
}
