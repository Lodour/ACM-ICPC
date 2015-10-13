#include <iostream>
#include <cstdio>
using namespace std;

long long C(int n, int m) {
	return m == 0 ? 1 : C(n - 1, m - 1) * n / m;
}
int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int a, b;
	while (~scanf("%d%d", &a, &b))
		printf("%lld\n", C(a + b - 1, b - 1));

	return 0;
}
