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
		ll n1, n2, d1, d2, t;
		scanf("%lld/%lld %lld/%lld", &n1, &d1, &n2, &d2);
		while (t = __gcd(n1, d1), t != 1) {
			n1 /= t;
			d1 /= t;
		}
		while (t = __gcd(n2, d2), t != 1) {
			n2 /= t;
			d2 /= t;
		}
		ll a = n1 / __gcd(n1, n2) * n2;
		ll b = __gcd(d1, d2);
		while (t = __gcd(a, b), t != 1) {
			a /= t;
			b /= t;
		}
		if (b == 1)printf("%lld\n", a);
		else printf("%lld/%lld\n", a, b);
	}

	return 0;
}
