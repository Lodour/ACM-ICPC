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

const int maxm = 1e5 + 10;
const int maxn = 111;
bool dp[maxm];
int v[maxn], num[maxn], cnt[maxm];

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	int n, m;
	while (cin >> n >> m && n) {
		REP(i, n)cin >> v[i];
		REP(i, n)cin >> num[i];
		CLR(dp, 0);
		dp[0] = 1;
		int ans = 0;
		for (int i = 0; i < n; i++) {
			CLR(cnt, 0);
			for (int j = v[i]; j <= m; j++) {
				if (dp[j] || !dp[j - v[i]] || cnt[j - v[i]] >= num[i])
					continue;
				dp[j] = 1;
				cnt[j] = cnt[j - v[i]] + 1;
				ans++;
			}
		}
		cout << ans << endl;


	}

	return 0;
}