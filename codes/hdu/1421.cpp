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

const int maxn = 2e3 + 10;
ll a[maxn];
ll f[maxn][maxn / 2];

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int n, k;
    while (cin >> n >> k) {
        REP2(i, 1, n)cin >> a[i];
        sort(a + 1, a + 1 + n);
        CLR(f, 0);
        REP2(i, 2, n)
        REP2(j, 1, i / 2 + 1)
        if (i == j * 2) f[i][j] = f[i - 2][j - 1] + (a[i] - a[i - 1]) * (a[i] - a[i - 1]);
        else f[i][j] = min(f[i - 1][j], f[i - 2][j - 1] + (a[i] - a[i - 1]) * (a[i] - a[i - 1]));
        //REP2(i,2,n){REP2(j,1,i/2+1)cout<<f[i][j]<<" ";cout<<endl;}
        cout << f[n][k] << endl;
    }
    return 0;
}