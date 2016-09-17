#include <algorithm>
#include <iostream>
#include <cstring>
#include <bitset>
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
#define inf 0x3f3f3f3f
#define SZ(x) ((int)(x).size())
#define MO(a,b) (((a)%(b)+(b))%(b))
#define all(x) (x).begin(),(x).end()
#define set(a,x) memset(a, x, sizeof(a))
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define out(x) cout << #x << ": " << x << endl;
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// head

int f(char c) {
    if ('a' <= c && c <= 'z') return c - 'a' + 26;
    return c - 'A';
}
bool vis[55];

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int n; cin >> n;
    string s; cin >> s;
    int ans = inf;
    VI v[55];
    rep(i, 0, n) {
        int d = f(s[i]);
        vis[d] = 1;
        v[d].pb(i);
    }
    rep(i, 0, 54) v[i].pb(inf);

    rep(i, 0, n) {
        int aa = 0;
        rep(j, 0, 54) if (vis[j]) {
            auto it = lower_bound(v[j].begin(), v[j].end(), i);
            aa = max(aa, *it);
        }
        ans = min(ans, aa - i + 1);
    }
    cout << ans << endl;

    return 0;
}
