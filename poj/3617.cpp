#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
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
#define pb(X) push_back(X)
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
typedef vector<int> VI;
#define X first
#define Y second
const double EPS = 1e-8;
const int MOD = 1000000007;
#define debug(x) cout<<#x<<": "<<x<<endl;
#define debug2(x,y) cout<<#x<<": "<<x<<"\t"<<#y<<": "<<y<<endl;
//************************************************


int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, cnt = 0;
	string s, t;
	cin >> n;
	REP(i, n) {
		cin >> t;
		s += t[0];
	}
	for (int i = 0, j = sz(s) - 1; i <= j;) {
		bool l = 0;
		for (int ii = i, jj = j; ii <= jj; ii++, jj--) {
			if (s[ii] < s[jj]) {
				l = 1;
				break;
			}
			else if (s[ii] > s[jj]) {
				l = 0;
				break;
			}
		}
		if (l) putchar(s[i++]);
		else putchar(s[j--]);
		if (++cnt % 80 == 0)putchar('\n');
	}
	if (cnt % 80 != 0) putchar('\n');

	return 0;
}