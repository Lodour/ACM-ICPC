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
#define REP(i,x) for(int i = 0; i < (int)(x); i++)
#define DEP(i,x) for(int i = (int)(x) - 1; i >= 0; i--)
#define FOR(i,x) for(__typeof(x.begin())i=x.begin(); i!=x.end(); i++)
#define set(a,x) memset(a, x, sizeof(a))
#define mo(a,b) (((a)%(b)+(b))%(b))
#define all(x) (x).begin(), (x).end()
#define sz(v) ((int)v.size())
#define UNIQUE(v) sort(all(v)); v.erase(unique(all(v)), v.end())
#define out(x) cout << #x << ": " << x << endl;
#define zero(x) (fabs(x)<eps?1:0)
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);
#define pq priority_queue
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
#define inf 0x3f3f3f3f
#define eps 1e-8
#define mod 1000000007
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define IT iterator
#define X first
#define Y second
#define lson rt<<1
#define rson rt<<1|1
// ************************************************************************

const int maxn = 200000 + 100;
ll f[maxn], invf[maxn];

void exgcd(ll a, ll b, ll &d, ll &x, ll &y) {
    if (!b) {d = a; x = 1; y = 0;}
    else {exgcd(b, a % b, d, y, x); y -= x * (a / b);}
}

ll inv(ll a, ll m) {
    ll x, y, d; exgcd(a, m, d, x, y);
    return d == 1 ? (x + m) % m : -1;
}

void CalFact() {
    f[0] = invf[0] = 1;
    for (int i = 1; i < maxn; i++) {
        f[i] = (f[i - 1] * i) % mod;
        invf[i] = inv(f[i], mod);
    }
}
ll C(int n, int m) {
    return (f[n] * invf[m] % mod) * invf[n - m] % mod;
}

map<int, int> cnt;
PII inter[maxn];

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif
    CalFact();
    int n, k;
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) {
        int l, r;
        scanf("%d%d", &l, &r);
        ++cnt[l];
        --cnt[r + 1];
    }
    ll res = 0;
    int pre = cnt.begin()->X;
    int sum = 0;
    for (auto it : cnt) {
        int npts = it.X - pre;
        // cout << sum << " " << k << " " << C(sum, k) << endl;
        if (sum >= k) res = (res + C(sum, k) * npts % mod) % mod;
        sum += it.Y;
        pre = it.X;
    }
    printf("%I64d\n", res);

    return 0;
}