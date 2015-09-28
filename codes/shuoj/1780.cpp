#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		long long x, lcm;
		scanf("%d", &n);
		lcm = 1;
		while (n--) {
			scanf("%lld", &x);
			lcm = lcm * x / __gcd(lcm, x);
		}
		printf("%lld\n", lcm);
	}

	return 0;
}
