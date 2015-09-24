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


bool f[5][5], vis[5][5];
PII g[5][5];
queue<PII> q;

const int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

void Print(int x, int y) {
	if (g[x][y] != MP(-1, -1)) Print(g[x][y].X, g[x][y].Y);
	cout << "(" << x << ", " << y << ")" << endl;
}

void bfs(int x, int y) {
	q.push(MP(x, y)); vis[0][0] = 1; g[0][0] = MP(-1, -1);
	while (q.size()) {
		int tx = q.front().X;
		int ty = q.front().Y;
		if (q.front() == MP(4, 4)) {
			Print(4, 4);
			return;
		}
		q.pop();
		vis[tx][ty] = 1;
		REP(i, 4) {
			int nx = tx + dir[i][0];
			int ny = ty + dir[i][1];
			if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5 && !vis[nx][ny] && !f[nx][ny]) {
				g[nx][ny] = MP(tx, ty);
				q.push(MP(nx, ny));
			}
		}
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0);

	REP(i, 5)REP(j, 5)cin >> f[i][j];
	bfs(0, 0);

	return 0;
}