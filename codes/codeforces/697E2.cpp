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

ll Pow(ll a, ll n, ll mod) {
	ll t = 1;
	for (; n; n >>= 1, a = a * a % mod)
		if (n & 1) t = t * a % mod;
	return t;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int k;
	cin >> k;
	ll a = 2, b = -1 + mod, x;
	while (k--) {
		cin >> x;
		a = Pow(a, x, mod);
		b = Pow(b, x, mod);
	}
	// now a = 2 ^ n, b = (-1) ^ n
	// now a = 2 ^ (n - 1)
	a = a * Pow(2, mod - 2, mod) % mod;

	// p = (2 ^ (n - 1) + (-1) ^ n) / 3
	ll p = (a + b) % mod * Pow(3, mod - 2, mod) % mod;
	// q = 2 ^ (n - 1)
	ll q = a;
	cout << p << "/" << q << endl;
	return 0;
}
