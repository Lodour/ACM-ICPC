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

const int N = 1010;
char s[N][N];
int r[N], c[N];

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int n, m, tot = 0;
    scanf("%d%d", &n, &m);
    rep(i, 0, n) {
        scanf("%s", s[i]);
        rep(j, 0, m) if (s[i][j] == '*') {
            r[i]++;
            c[j]++;
            tot++;
        }
    }
    rep(i, 0, n)rep(j, 0, m)if (r[i] + c[j] - (s[i][j] == '*') == tot) {
        printf("YES\n%d %d\n", i + 1, j + 1);
        return 0;
    }
    puts("NO");

    return 0;
}
