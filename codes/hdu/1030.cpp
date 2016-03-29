#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))
typedef long long ll;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	ll a, b;
	while (~scanf("%lld%lld", &a, &b)) {
		ll lea = ceil(sqrt(a));
		ll leb = ceil(sqrt(b));
		ll la = (a - ((lea - 1) * (lea - 1)) + 1) / 2 + 1;
		ll lb = (b - ((leb - 1) * (leb - 1)) + 1) / 2 + 1;
		ll ra = (lea * lea - a) / 2 + 1;
		ll rb = (leb * leb - b) / 2 + 1;
		ll ans = abs(lea - leb) + abs(la - lb) + abs(ra - rb);
		printf("%lld\n", ans);
	}
	return 0;
}
