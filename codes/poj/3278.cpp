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

const int maxn = 2e5 + 1;
int vis[maxn];
int n, m;

int bfs() {
	queue<int> q;
	CLR(vis, 0);
	q.push(n);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		if (x == m) break;
		if (x + 1 < maxn && !vis[x + 1]) {q.push(x + 1); vis[x + 1] = vis[x] + 1;}
		if (x * 2 < maxn && !vis[x * 2]) {q.push(x * 2); vis[x * 2] = vis[x] + 1;}
		if (x && !vis[x - 1]) {q.push(x - 1); vis[x - 1] = vis[x] + 1;}
	}
	return vis[m];
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	cout << bfs() << endl;

#ifndef ONLINE_JUDGE
	cout << "Done..." << endl;
	while (1);
#endif
	return 0;
}