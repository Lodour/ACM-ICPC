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
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
using namespace std;
#define INF 0x3FFFFFFF
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REP2(i,x,y) for(int i=x;i<=y;i++)
#define DEP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define DEPS(i,x) for(int i=((int)(x));i>0;i--)
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
int n, m;
char f[111][111];

void dfs(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m) return;
	if (f[x][y] == '.') return;
	f[x][y] = '.';
	//debug2(x,y)
	REP2(i, -1, 1)REP2(j, -1, 1)if (i || j) dfs(x + i, y + j);
	return;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	int cnt = 0;
	REP(i, n) {
		string s; cin >> s;
		REP(j, m)f[i][j] = s[j];
	}
	REP(i, n)REP(j, m)if (f[i][j] == 'W') {dfs(i, j); cnt++;}
	cout << cnt << endl;

#ifndef ONLINE_JUDGE
	cout << "Done..." << endl;
	while (1);
#endif
	return 0;
}