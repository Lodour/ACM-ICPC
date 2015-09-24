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
#define mp(X,Y) make_pair(X,Y)
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

int n, m, sx, sy, ans;
int mp[22][22];
const int dis[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

bool check(int nx, int ny) {
	return (nx >= 0 && ny >= 0 && nx < n && ny < m);
}

void dfs(int x, int y, int cnt) {
	if (cnt >= ans) return;
	REP(i, 4) {
		int nx = x + dis[i][0], ny = y + dis[i][1];
		if (!check(nx, ny) || mp[nx][ny] == 1) continue;
		while (check(nx, ny) && mp[nx][ny] == 0) {
			nx += dis[i][0];
			ny += dis[i][1];
		}
		//nx-=dis[i][0];
		//ny-=dis[i][1];
		if (!check(nx, ny))continue;
		if (mp[nx][ny] == 3) ans = min(ans, cnt);
		else {
			//nx+=dis[i][0];ny+=dis[i][1];
			//if(!check(nx,ny))continue;
			if (mp[nx][ny] != 0) {
				mp[nx][ny] = 0;
				if (!check(nx - dis[i][0], ny - dis[i][1]))continue;
				dfs(nx - dis[i][0], ny - dis[i][1], cnt + 1);
				mp[nx][ny] = 1;
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

	while (cin >> m >> n && m && n) {
		REP(i, n)REP(j, m) {
			cin >> mp[i][j];
			if (mp[i][j] == 2) {sx = i; sy = j; mp[i][j] = 0;}
		}
		ans = 11;
		dfs(sx, sy, 1);
		cout << (ans == 11 ? -1 : ans) << endl;
	}


#ifndef ONLINE_JUDGE
	cout << "Done..." << endl;
	while (1);
#endif
	return 0;
}