#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		ll n;
		scanf("%lld", &n);
		n = 8 * n - 7;
		ll a = sqrt(n);
		puts(a * a == n && (a - 1) % 2 == 0 ? "2" : "3");
	}
	return 0;
}
