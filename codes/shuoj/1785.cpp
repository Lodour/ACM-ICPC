// 容斥原理
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[15];

long long lcm(long long mul, long long x) {
	return mul / __gcd(mul, x) * x;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif
	int n, m;
	while (~scanf("%d%d", &n, &m)) {
		for (int i = 0; i < m; i++)
			scanf("%d", &a[i]);
		long long ans = 0;
		for (int i = 0; i < (1 << m); i++) {
			int cnt = 0;
			long long mul = 1;
			for (int j = 0; j < m; j++)
				if (i & (1 << j)) {
					mul = lcm(mul, a[j]);
					cnt++;
				}
			if (cnt == 0) continue;
			if (cnt & 1) ans += n / mul;
			else ans -= n / mul;
		}
		printf("%lld\n", ans);
	}
	return 0;
}

