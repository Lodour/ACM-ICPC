#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
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
		int n;
		ll cur, ans = 1;
		scanf("%d", &n);
		while (n--) {
			scanf("%lld", &cur);
			ans = ans * cur / __gcd(ans, cur);
		}
		printf("%lld\n", ans);
	}

	return 0;
}
