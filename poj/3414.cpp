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

const int maxn = 111;
int a, b, c;
int vis[maxn][maxn];
PII last[maxn][maxn];
int ans[maxn][maxn];
const string aa[] = {"FILL(1)", "FILL(2)", "DROP(1)", "DROP(2)", "POUR(1,2)", "POUR(2,1)"};

void dfs(int x, int y) {
	if (vis[x][y] == 1) return;
	int lx = last[x][y].X;
	int ly = last[x][y].Y;
	dfs(lx, ly);
	cout << aa[ans[x][y]] << endl;
}

bool bfs() {
	queue<PII> q;
	q.push(MP(0, 0)); vis[0][0] = 1;
	while (!q.empty()) {
		PII t = q.front(); q.pop();
		//cout<<t.X<<" "<<t.Y<<" "<<vis[t.X][t.Y]<<endl;
		if (t.X == c || t.Y == c) {
			cout << vis[t.X][t.Y] - 1 << endl;
			dfs(t.X, t.Y);
			return 1;
		}
		// FILL 1
		if (t.X < a && !vis[a][t.Y]) {
//            debug2(t.X,t.Y)debug(vis[t.X][t.Y])
			vis[a][t.Y] = vis[t.X][t.Y] + 1;
			ans[a][t.Y] = 0;
			last[a][t.Y] = MP(t.X, t.Y);
			q.push(MP(a, t.Y));
		}
		// FILL 2
		if (t.Y < b && !vis[t.X][b]) {
			vis[t.X][b] = vis[t.X][t.Y] + 1;
			ans[t.X][b] = 1;
			last[t.X][b] = MP(t.X, t.Y);
			q.push(MP(t.X, b));
		}
		// Drop 1
		if (t.X && !vis[0][t.Y]) {
			vis[0][t.Y] = vis[t.X][t.Y] + 1;
			ans[0][t.Y] = 2;
			last[0][t.Y] = MP(t.X, t.Y);
			q.push(MP(0, t.Y));
		}
		// Drop 2
		if (t.Y && !vis[t.X][0]) {
			vis[t.X][0] = vis[t.X][t.Y] + 1;
			ans[t.X][0] = 3;
			last[t.X][0] = MP(t.X, t.Y);
			q.push(MP(t.X, 0));
		}
		// Pour 1 2
		if (t.X && t.Y < b) {
			int nx = max(t.X - b + t.Y, 0);
			int ny = min(t.X + t.Y, b);
			if (!vis[nx][ny]) {
				vis[nx][ny] = vis[t.X][t.Y] + 1;
				ans[nx][ny] = 4;
				last[nx][ny] = MP(t.X, t.Y);
				q.push(MP(nx, ny));
			}
		}
		// Pour 2 1
		if (t.Y && t.X < a) {
			int nx = min(t.X + t.Y, a);
			int ny = max(t.Y - a + t.X, 0);
			if (!vis[nx][ny]) {
				vis[nx][ny] = vis[t.X][t.Y] + 1;
				ans[nx][ny] = 5;
				last[nx][ny] = MP(t.X, t.Y);
				q.push(MP(nx, ny));
			}
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

	cin >> a >> b >> c;
	if (!bfs()) cout << "impossible" << endl;

#ifndef ONLINE_JUDGE
	cout << "Done..." << endl;
	while (1);
#endif
	return 0;
}