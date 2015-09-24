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
const int MOD = 1000000007;
#define debug(x) cout<<#x<<": "<<x<<endl;
#define debug2(x,y) cout<<#x<<": "<<x<<"\t"<<#y<<": "<<y<<endl;
/****************************************************************************/

const int maxn = 1e5 + 1;
int a[maxn][11], f[maxn][11];

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int n;
    while (scanf("%d", &n) == 1 && n) {
        CLR(a, 0); CLR(f, 0);
        int maxt = -1;
        while (n--) {
            int x, t;
            cin >> x >> t;
            maxt = max(maxt, t);
            a[t][x]++;
        }
        REP2(i, 1, maxt)
        REP(j, 11) {
            f[i][j] = f[i - 1][j];
            if (abs(j - 5) > i) continue;
            // from left
            if (j > 0) f[i][j] = max(f[i][j], f[i - 1][j - 1]);
            // from right
            if (j < 10) f[i][j] = max(f[i][j], f[i - 1][j + 1]);
            // current
            f[i][j] += a[i][j];
        }
        //REP2(i,1,maxt){REP(j,11)cout<<f[i][j]<<" ";cout<<endl;}
        int ans = -1;
        REP(i, 11)ans = max(ans, f[maxt][i]);
        cout << ans << endl;
    }

    return 0;
}