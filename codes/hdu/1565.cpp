#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <sstream>
#include <queue>
#include <stack>
#include <string>
#include <functional>
#include <set>
#include <map>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
using namespace std;
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REP2(X,L,R) for(int X=(int)L;X<=(int)R;X++)
#define DEP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define DEP2(X,L,R) for(int X=(int)L;X>=(int)R;X--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define CLR(A,X) memset(A,X,sizeof(A))
#define ALL(container) (container).begin(), (container).end()
#define sz(container) ((int)container.size())
#define UNIQUE(v) sort(ALL(v)); v.erase( unique(v.begin(), v.end()), v.end() );
#define IT iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<PII, int> PPI;
typedef vector<int> VI;
#define fi first
#define se second
const double EPS = 1e-8;
//const int MOD = 1000000007;
#define debug(x) cout<<#x<<": "<<x<<endl;
#define debug2(x,y) cout<<#x<<": "<<x<<"\t"<<#y<<": "<<y<<endl;
/****************************************************************************/
int st[20000], k;
int dp[21][20000];
int mp[21][21];

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    k = 0;
    for (int i = 0; i <= (1 << 20); i++)
        if (!(i & (i << 1)))
            st[k++] = i;

    int n;
    while (cin >> n) {
        REP(i, n)REP(j, n)cin >> mp[i][j];
        CLR(dp, 0);
        dp[0][0] = 1;
        int ans = 0;
        REP(i, n) {
            REP(j, k) {
                if (st[j] >= (1 << n))break;
                int sum = 0;
                REP(h, n)if (st[j] & (1 << h)) sum += mp[i][h];
                REP(h, k) {
                    if (st[h] >= (1 << n))break;
                    if (st[h]&st[j]) continue;
                    dp[i + 1][h] = max(dp[i + 1][h], dp[i][j] + sum);
                }
            }
            REP(j, k) {
                if (st[j] > (1 << n))break;
                ans = max(ans, dp[n][j]);
            }
        }
        cout << ans << endl;
    }

    return 0;
}