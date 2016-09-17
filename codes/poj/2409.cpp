#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

ll Pow(ll a, ll n) {
	ll t = 1;
	while (n) {
		if (n & 1) t *= a;
		n >>= 1;
		a *= a;
	}
	return t;
}

ll solve(int c, int n) {
	if (n == 0) return 0;
	ll ans = 0;
	for (int i = 1; i <= n; i++)
		ans += Pow(c, __gcd(i, n));
	if (n & 1)
		ans += n * Pow(c, n + 1 >> 1);
	else
		ans += n / 2 * (1 + c) * Pow(c, n >> 1);
	return ans / n / 2;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int c, n;
	while (cin >> c >> n && c && n)
		cout << solve(c, n) << endl;

	return 0;
}