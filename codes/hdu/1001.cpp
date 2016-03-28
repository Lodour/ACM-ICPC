#include <iostream>
#include <cstdio>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	while (~scanf("%d", &n))
		printf("%d\n\n", n & 1 ? (n + 1) / 2 * n : n / 2 * (n + 1));

	return 0;
}
