#include <iostream>
#include <cstdio>
using namespace std;

long long f(int n) {
	return n < 1 ? 1 : n * f(n - 1);
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int m, n;
	while (~scanf("%d%d", &m, &n))
		printf("%lld\n", f(n - 1) * f(n) / f(n - m));

	return 0;
}
