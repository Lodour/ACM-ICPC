#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int k, n;
	long long ans = 0, cnt = 1;
	scanf("%d%d", &k, &n);
	while (n) {
		if (n & 1) ans += cnt;
		n >>= 1;
		cnt *= k;
	}
	printf("%lld\n", ans % (1LL << 32));
	return 0;
}
