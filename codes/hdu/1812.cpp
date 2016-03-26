// 需要高精度
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
	ll ans = 0;
	ans += Pow(c, n * n);
	ans += 2 * Pow(c, (n * n + 3) / 4);
	ans += Pow(c, (n * n + 1) / 2);
	ans += 2 * Pow(c, n * (n + 1) / 2);
	ans += 2 * Pow(c, n * ((n + 1) / 2));
	return ans / 8;
}

class a {
	int b = 0;
};

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n, c;
	while (cin >> n >> c)
		cout << solve(c, n) << endl;

	return 0;
}