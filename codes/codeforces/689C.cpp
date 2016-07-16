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
#define MOD 1000000007
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define IT iterator
#define X first
#define Y second
#define lson rt<<1
#define rson rt<<1|1
// ************************************************************************
ll m;

ll f(ll a) {
    ll res = 0;
    for (ll k = 2;; k++) {
        ll k3 = k * k * k;
        if (k3 > a) break;
        if (res > m - a / k3) return -1;
        res += a / k3;
    }
    // cout << "!" << a << " " << res << endl;
    return res;
}

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    cin >> m;
    ll l = 1, r = 9000000000000000000LL;
    while (l < r) {
        // cout << l << " " << r << endl;
        ll mid = (l + r) >> 1;
        ll rr = f(mid);
        if (rr >= m || rr == -1) r = mid;
        else l = mid + 1;
    }
    while (f(l - 1) == m) l--;
    cout << (f(l) == m ? l : -1) << endl;

    return 0;
}