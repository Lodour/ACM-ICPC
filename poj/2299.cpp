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
#define lowbit(i) (i&(-i))
const int maxn = 5e5 + 10;
int bit[maxn], n, a[maxn], b[maxn];

int query(int i) {
	int s = 0;
	while (i > 0) {
		s += bit[i];
		i -= lowbit(i);
	}
	return s;
}
void add(int i, int x) {
	while (i <= n) {
		bit[i] += x;
		i += lowbit(i);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	while (scanf("%d", &n) && n) {
		CLR(bit, 0);
		REP(i, n) {
			scanf("%d", &a[i]);
			b[i] = a[i];
		}
		sort(b, b + n);
		REP(i, n)a[i] = lower_bound(b, b + n, a[i]) - b + 1;
		ll ans = 0;
		REP(i, n) {
			ans += i - query(a[i]);
			add(a[i], 1);
		}
		printf("%I64d\n", ans);
	}
	return 0;
}