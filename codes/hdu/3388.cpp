#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define fi first
#define eps 1e-8
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;
const ll iinf = 1LL << 60;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define SZ(x) ((int)(x).size())
#define MO(a,b) (((a)%(b)+(b))%(b))
#define all(x) (x).begin(),(x).end()
#define set(a,x) memset(a, x, sizeof(a))
#define rep(i,a,n) for (int i=(int)(a);i<(int)(n);i++)
#define per(i,a,n) for (int i=(int)(n)-1;i>=(int)(a);i--)
#define OUT(x) cout << #x << ": " << x << endl;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// ================================================================================

ll a[100], tot;
// 分解n
void get(ll n) {
    ll d = sqrt(n);
    for (int i = 2; i <= d; i++)
        if (n % i == 0) {
            a[tot++] = i;
            while (n % i == 0)
                n /= i;
        }
    if (n != 1) a[tot++] = n;
}


// [1,x]中与m&&n不互素的数的个数
ll f(ll x) {
    ll ans = 0;
    for (int i = 1; i < (1 << tot); i++) {
        ll lcm = 1;
        for (int j = 0; j < tot; j++)
            if (i & (1 << j))
                lcm = lcm * 1LL * a[j];
        ll add = x / lcm;
        ll op = __builtin_popcount(i) & 1 ? 1 : -1;
        ans += op * add;
    }
    return x - ans;
}

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int t;
    cin >> t;
    for (int T = 1; T <= t; T++) {
        ll n, m, k;
        scanf("%lld%lld%lld", &n, &m, &k);
        // 求出n和m所有的素因子
        tot = 0; get(n); get(m);
        sort(a, a + tot);
        tot = unique(a, a + tot) - a;
        // 二分
        ll l = 1, r = 10000000000LL;
        while (l < r) {
            ll mid = (l + r) >> 1;
            ll cnt = f(mid);
            if (cnt >= k) {
                r = mid;
            }
            else l = mid + 1;
        }
        printf("Case %d: %lld\n", T, l);
    }


    return 0;
}