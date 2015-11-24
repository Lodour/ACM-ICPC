#include <iostream>
#include <cstdio>
using namespace std;

typedef long long ll;
const int mod = 1e9 + 7;

ll Pow(ll a, ll n) {
	ll rt = 1;
	while (n) {
		if (n & 1) rt = (rt * a) % mod;
		a = (a * a) % mod;
		n >>= 1;
	}
	return rt;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	ll ans = ((Pow(3, 3 * n) - Pow(7, n)) % mod + mod) % mod;
	printf("%lld\n", ans);

	return 0;
}
