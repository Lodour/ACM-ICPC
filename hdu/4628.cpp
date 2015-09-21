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

int dp[1 << 17];
int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int t; cin >> t;
    while (t--) {
        string s;
        cin >> s;
        CLR(dp, 0x3f);
        int len = s.size();
        for (int i = 0; i < (1 << len); i++) {
            string tmp;
            for (int j = 0; j < len; j++)
                if (i & (1 << j))tmp += s[j];
            int x, y;
            for (x = 0, y = tmp.size() - 1; x < tmp.size() && y >= 0 && x <= y; x++, y--)
                if (tmp[x] != tmp[y]) break;
            if (x >= y)dp[i] = 1;
        }
        for (int i = 1; i < (1 << len); i++) {
            for (int j = i; j > 0; j = (j - 1)&i)
                dp[i] = min(dp[i], dp[i ^ j] + dp[j]);
        }
        cout << dp[(1 << len) - 1] << endl;

    }

    return 0;
}