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
//************************************************
// 拓扑排序模板
// 修改maxn为最大点个数
const int maxn = 555;
int Ans[maxn];
int G[maxn][maxn];
int deg[maxn];
// 存图前初始化
void init() {
	memset(G, 0, sizeof(G));
	memset(deg, 0, sizeof(deg));
	memset(Ans, 0, sizeof(Ans));
}
// 添加U->V的有向边
void add_edge(int u, int v) {
	if (G[u][v]) return;
	G[u][v] = 1;
	deg[v]++;
}
// 直接调用, 如需判断有环, 0有1没有
bool toposort(int n) {
	int tot = 0;
	queue<int> que;
	for (int i = 0; i < n; ++i)
		if (deg[i] == 0) que.push(i);
	while (!que.empty()) {
		int v = que.front(); que.pop();
		Ans[tot++] = v;
		for (int i = 0; i < n; ++i) {
			if (G[v][i] == 1) {
				deg[i]--;
				if (deg[i] == 0)que.push(i);
			}
		}
	}
	if (tot < n) return false;
	return true;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	const int dir[4][2] = {0, 0, 0, 1, 1, 0, 1, 1};
	string s;
	while (cin >> s && s != "ENDOFINPUT") {
		init();
		int f[4][4];
		REP(i, 4)REP(j, 4)cin >> f[i][j];
		int cnt = 0;
		REP(i, 3)REP(j, 3) {
			cnt++;
			REP(k, 4) {
				int t = f[i + dir[k][0]][j + dir[k][1]];
				if (t == cnt) continue;
				add_edge(cnt - 1, t - 1);
			}
		}
		if (toposort(9)) cout << "THESE WINDOWS ARE CLEAN" << endl;
		else cout << "THESE WINDOWS ARE BROKEN" << endl;
		cin >> s;
	}
	return 0;
}