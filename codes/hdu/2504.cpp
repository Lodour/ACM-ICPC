#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		ll a, b;
		scanf("%lld%lld", &a, &b);
		ll c = 2 * b;
		while (__gcd(a, c) != b)
			c += b;
		printf("%lld\n", c);
	}

	return 0;
}
