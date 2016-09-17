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

const int N = 111;
int dp[N][3];

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int n, x;
    scanf("%d", &n);
    rep(i, 1, n + 1) {
        scanf("%d", &x);
        rep(j, 0, 3) {
            dp[i][j] = inf;
            dp[i][0] = min(dp[i][0], dp[i - 1][j] + 1);
        }
        if (x & 1) {
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]);
        }
        if (x & 2) {
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]);
        }
    }
    int ans = inf;
    rep(i, 0, 3) ans = min(ans, dp[n][i]);
    printf("%d\n", ans);

    return 0;
}
