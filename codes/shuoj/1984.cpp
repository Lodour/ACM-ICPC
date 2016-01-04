#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void exgcd(ll a, ll b, ll &d, ll &x, ll &y) {
	if (!b) {d = a; x = 1; y = 0;}
	else {exgcd(b, a % b, d, y, x); y -= x * (a / b);}
}
#define Mod(a,b) (((a)%(b)+(b))%(b))
bool solve(ll a, ll b, ll c, ll &x, ll &y, ll &dx, ll &dy) {
	if (a == 0 && b == 0) return 0;
	ll d, x0, y0; exgcd(a, b, d, x0, y0);
	if (c % d != 0) return 0;
	dx = b / d; dy = a / d;
	y = Mod(y0 * c / d, dy); x = (c - b * y) / a;
	while (x < 0) {x += dx; y -= dy;}
	if (y < 0) return 0;
	return 1;
}
int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	cin >> t;
	while (t--) {
		ll a, b, m;
		cin >> a >> b >> m;
		ll x, y, dx, dy;
		if (solve(a, b, m, x, y, dx, dy)) cout << x << " " << y << endl;
		else cout << "Impossible" << endl;
	}

	return 0;
}
