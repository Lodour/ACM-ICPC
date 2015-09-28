#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		long long n;
		scanf("%lld", &n);
		n = 8 * n - 7;
		long long a = sqrt(n);
		if (a * a == n && (a - 1) % 2 == 0) puts("2");
		else puts("3");
	}
	return 0;
}
