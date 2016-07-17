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

const int N = 501;
int c[N];
int dp[2][N][N];

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int n, m, x;
    scanf("%d%d", &n, &m);

    int now, pre;
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &x);
        now = i & 1;
        pre = 1 - now;
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= m; k++) {
                dp[now][j][k] |= dp[pre][j][k];
                if (j >= x) {
                    dp[now][j][k] |= dp[pre][j - x][k];
                    if (k >= x)
                        dp[now][j][k] |= dp[pre][j - x][k - x];
                }
            }
    }
    VI ans;
    for (int i = 0; i <= m; i++)
        if (dp[now][m][i]) ans.pb(i);
    printf("%d\n", ans.size());
    for (int i = 0; i < (int)ans.size(); i++)
        printf("%d%c", ans[i], i == (int)ans.size() - 1 ? '\n' : ' ');
    return 0;
}
