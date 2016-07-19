#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <functional>
#include <cstdlib>
#include <climits>
#include <cctype>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define set(a,x) memset(a, x, sizeof(a))
#define all(x) (x).begin(),(x).end()
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define MO(a,b) (((a)%(b)+(b))%(b))
#define out(x) cout << #x << ": " << x << endl;
#define zero(x) (fabs(x)<eps?1:0)
#define pq priority_queue
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;
const ll mod = 1000000007;
const ll inf = 1ll << 60;
// ************************************************************************

ll Mul(ll a, ll b, ll mod) {
	ll t = 0;
	for (; b; b >>= 1, a = (a << 1) % mod)
		if (b & 1) t = (t + a) % mod;
	return t;
}
ll Pow(ll a, ll n, ll mod) {
	ll t = 1;
	for (; n; n >>= 1, a = Mul(a, a, mod))
		if (n & 1) t = Mul(t, a, mod);
	return t;
}
long long Euler(long long n) {
	long long rt = n;
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0) {
			rt -= rt / i;
			while (n % i == 0) n /= i;
		}
	if (n > 1) rt -= rt / n;
	return rt;
}

ll a[100000 + 100];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	ll p = 1, q = 1;

	ll x = 1; // 2^n - 1
	ll pmod = Euler(mod);
	for (int i = 0; i < n; i++)
		x = Mul(x, a[i], pmod);
	x = MO(x - 1, pmod);
	x = Pow(2, x, mod);

	bool ji = 1;
	for (int i = 0; i < n; i++)
		if (a[i] % 2 == 0) ji = 0;

	if (ji) {
		p = MO(x - 1, mod);
		p = Mul(p, inv(3, mod), mod);
		q = x;
	}
	else {
		p = MO(x + 1, mod);
		p = Mul(p, inv(3, mod), mod);
		q = x;
	}
	cout << p << "/" << q << endl;
	return 0;
}

