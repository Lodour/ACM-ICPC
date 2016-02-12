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
#include <functional>
#include <cstdlib>
#include <climits>
#include <cctype>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define eps 1e-18
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define mt(a,b...) make_tuple(a,b)
#define IT iterator
#define X first
#define Y second
#define MO(a,b) (((a)%(b)+(b))%(b))
#define set(a,x) memset(a, x, sizeof(a))
#define REP(i,x) for(int i = 0; i < (int)(x); i++)
#define DEP(i,x) for(int i = (int)(x)-1; i >= 0; i--)
#define out(x) cout << #x << ": " << x << endl;
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);
//************************************************

/*
 * 判断度序列deg[]是否可图，并返回其中一种图的邻接矩阵。
 * deg[i] = mp(度数, 序号)
 */
const int N = 15;
int n;
PII deg[N];
bool G[N][N];
bool cmp(PII a, PII b) {return a > b;}
bool Graphic() {
	for (int i = 0; i < n; i++) {
		sort(deg + i, deg + n, cmp);
		int di = deg[i].X;
		int u = deg[i].Y;
		if (di == 0) return 1;
		if (di >= n - i) return 0;
		for (int j = i + 1; j <= i + di; j++) {
			if (--deg[j].X < 0) return 0;
			int v = deg[j].Y;
			G[u][v] = G[v][u] = 1;
		}
	}
	return 1;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		set(G, 0);
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			int d;
			scanf("%d", &d);
			deg[i] = mp(d, i);
		}
		if (Graphic()) {
			puts("YES");
			for (int i = 0; i < n; i++)
				for (int j = 0; j < n; j++)
					printf("%d%c", G[i][j], j == n - 1 ? '\n' : ' ');
		}
		else puts("NO");
		if (T) puts("");
	}


	return 0;
}
