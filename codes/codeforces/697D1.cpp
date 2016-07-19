#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <functional>
#include <cstdlib>
#include <climits>
#include <cctype>
using namespace std;
#define REP(i,x) for(int i = 0; i < (int)(x); i++)
#define DEP(i,x) for(int i = (int)(x) - 1; i >= 0; i--)
#define FOR(i,x) for(__typeof(x.begin())i=x.begin(); i!=x.end(); i++)
#define set(a,x) memset(a, x, sizeof(a))
#define mo(a,b) (((a)%(b)+(b))%(b))
#define all(x) (x).begin(), (x).end()
#define sz(v) ((int)v.size())
#define UNIQUE(v) sort(all(v)); v.erase(unique(all(v)), v.end())
#define out(x) cout << #x << ": " << x << endl;
#define zero(x) (fabs(x)<eps?1:0)
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);
#define pq priority_queue
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
#define inf 0x3f3f3f3f
#define MOD 1000000007
#define eps 1e-8
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define IT iterator
#define X first
#define Y second
#define lson rt<<1
#define rson rt<<1|1
// ************************************************************************

const int N = 100000 + 100;
VI G[N];
double ans[N];
int cnt[N];

void dfs(int rt) {
	double res = 0;
	for (auto i : G[rt])
		res += cnt[i];
	// out(rt)
	// out(res)
	for (auto i : G[rt]) {
		// cout << i << " " << cnt[i] << endl;
		ans[i] = ans[rt] + 1.0 + (res - cnt[i]) * 0.5;
		dfs(i);
	}
}

int dfs2(int rt) {
	int res = 0;
	if (G[rt].empty()) return cnt[rt] = 1;
	for (auto i : G[rt]) {
		res += dfs2(i);
	}
	return cnt[rt] = res + 1;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	ans[1] = 1;
	for (int i = 2; i <= n; i++) {
		int u;
		scanf("%d", &u);
		G[u].pb(i);
	}
	cnt[1] = dfs2(1);
	// for (int i = 1; i <= n; i++)
	// cout << cnt[i] << endl;
	dfs(1);
	for (int i = 1; i <= n; i++)
		printf("%.7f%c", ans[i], i == n ? '\n' : ' ');
	return 0;
}

