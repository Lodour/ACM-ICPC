#include <algorithm>
#include <iostream>
#include <cassert>
#include <cstring>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define inf 0x3f3f3f3f
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;
#define SZ(x) ((int)(x).size())
#define MO(a,b) (((a)%(b)+(b))%(b))
#define all(x) (x).begin(),(x).end()
#define set(a,x) memset(a, x, sizeof(a))
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define out(x) cout << #x << ": " << x << endl;
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
ll powmod(ll a, ll b, ll mod) {ll res = 1; a %= mod; assert(b >= 0); for (; b; b >>= 1) {if (b & 1)res = res * a % mod; a = a * a % mod;} return res;}
// head

const int N = 200000 + 100;
int n, fa[N], ra[N];
int p[N];
VI vec;

void init(int n) {
    rep(i, 0, n + 10) {fa[i] = i; ra[i] = 0;}
}
int find(int x) {
    if (fa[x] != x) fa[x] = find(fa[x]);
    return fa[x];
}
void Union(int x, int y) {
    x = find(x); y = find(y);
    if (x == y) return;
    if (ra[x] < ra[y]) fa[x] = y;
    else {
        fa[y] = x;
        if (ra[x] == ra[y]) ra[x]++;
    }
}
bool same(int x, int y) {
    return find(x) == find(y);
}


int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    scanf("%d", &n);
    init(n);
    int rt = -1;
    rep(i, 1, n + 1) {
        scanf("%d", &p[i]);
        if (i == p[i]) rt = i;
        if (same(i, p[i])) vec.pb(i);
        else Union(i, p[i]);
    }
    int ans = 0;
    if (rt == -1) rt = vec[SZ(vec) - 1];
    for (auto i : vec) if (p[i] != rt) {
            ans++;
            p[i] = rt;
        }
    printf("%d\n", ans);
    rep(i, 1, n + 1) printf("%d ", p[i]);

    return 0;
}
