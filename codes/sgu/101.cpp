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

const int N = 111;
int n, st, cnt;
int G[N][N], det[10];
PII s[N], ans[N];

void dfs(int u) {
	for (int v = 0; v <= 6; v++)
		if (G[u][v]) {
			G[u][v]--; G[v][u]--;
			dfs(v);
			ans[++cnt] = mp(u, v);
		}
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		s[i] = mp(u, v);
		G[u][v]++; G[v][u]++;
		det[u]++; det[v]++;
	}
	for (int i = 0; i <= 6; i++)
		if (det[i] & 1) {
			cnt++;
			st = i;
		} else if (det[i] && !st)
			st = i;
	if (cnt > 2) {
		puts("No solution");
		return 0;
	}
	cnt = 0;
	dfs(st);
	if (cnt < n) {
		puts("No solution");
		return 0;
	}
	for (int i = cnt; i >= 1; i--)
		for (int j = 1; j <= n; j++)
			if (ans[i] == s[j]) {
				printf("%d +\n", j);
				s[j] = mp(-1, -1);
				break;
			}
			else if (ans[i] == mp(s[j].Y, s[j].X)) {
				printf("%d -\n", j);
				s[j] = mp(-1, -1);
				break;
			}

	return 0;
}
