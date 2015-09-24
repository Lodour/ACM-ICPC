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
typedef vector<int> VI;
#define X first
#define Y second
const double EPS = 1e-8;
const int MOD = 1000000007;
#define debug(x) cout<<#x<<": "<<x<<endl;
#define debug2(x,y) cout<<#x<<": "<<x<<"\t"<<#y<<": "<<y<<endl;
//************************************************

const int maxn = 33;
const int dir[6][3] = { -1, 0, 0, 1, 0, 0, 0, -1, 0, 0, 1, 0, 0, 0, 1, 0, 0, -1};
int l, r, c;
char f[maxn][maxn][maxn];
int vis[maxn][maxn][maxn];

int bfs(int z, int x, int y) {
	queue<pair<PII, int> > q;
	q.push(MP(MP(z, x), y));
	CLR(vis, 0);
	while (!q.empty()) {
		pair<PII, int> t = q.front(); q.pop();
		int tl = t.X.X;
		int tr = t.X.Y;
		int tc = t.Y;
		if (f[tl][tr][tc] == 'E') return vis[tl][tr][tc];
		REP(i, 6) {
			int nl = tl + dir[i][0];
			int nr = tr + dir[i][1];
			int nc = tc + dir[i][2];
			if (nl < 0 || nr < 0 || nc < 0 || nl >= l || nr >= r || nc >= c || vis[nl][nr][nc] || f[nl][nr][nc] == '#')
				continue;
			vis[nl][nr][nc] = vis[tl][tr][tc] + 1;
			q.push(MP(MP(nl, nr), nc));
		}
	}
	return 0;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0);

	while (cin >> l >> r >> c && l) {
		int sl, sr, sc;
		REP(i, l) {
			REP(j, r) {
				string line; cin >> line;
				REP(k, c) {
					if (line[k] == 'S') {sl = i; sr = j; sc = k; line[k] = '.';}
					f[i][j][k] = line[k];
				}
			}
		}
		int ans = bfs(sl, sr, sc);
		if (ans == 0) cout << "Trapped!" << endl;
		//else if (ans==1) cout<<"Escaped in 1 minute."<<endl;
		else cout << "Escaped in " << ans << " minute(s)." << endl;
	}

#ifndef ONLINE_JUDGE
	cout << "Done..." << endl;
	while (1);
#endif
	return 0;
}