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


int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int n, m;
    while (cin >> n >> m) {
        int a[22];
        for (int i = 0; i < m; i++)
            cin >> a[i];

        ll ans = 0;
        for (int i = 1; i < (1 << m); i++) {
            ll d = 1;
            for (int j = 0; j < m; j++)
                if (i & (1 << j))
                    d = d / __gcd(d, 1LL * a[j]) * a[j];
            if (d == 0) continue;
            int op = __builtin_popcount(i) & 1 ? 1 : -1;
            ans += op * (n - 1) / d;
        }
        cout << ans << endl;
    }


    return 0;
}