#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	ll a, b;
	scanf("%lld%lld", &a, &b);
	if (__gcd(a, b) != 1) {
		puts("Impossible");
		return 0;
	}
	while (a > 1 || b > 1) {
		if (a > b) {
			printf("%lldA", a / b - (a % b == 0));
			a %= b;
		}
		else {
			printf("%lldB", b / a - (b % a == 0));
			b %= a;
		}
	}
	puts("");

	return 0;
}
