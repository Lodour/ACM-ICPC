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
int a[N];
char s[N];

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int n, ans = -1u >> 1;
    scanf("%d", &n);
    scanf("%s", s);
    rep(i, 0, n)scanf("%d", a + i);
    rep(i, 0, n)if (s[i] == 'R' && s[i + 1] == 'L') {
        ans = min(ans, a[i + 1] - a[i] >> 1);
    }
    printf("%d\n", ans == -1u >> 1 ? -1 : ans);


    return 0;
}
