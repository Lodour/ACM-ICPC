#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> VI;
#define pb push_back

int n;
VI adj[22];
bool isp[40] = {0, 1, 1, 1, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0};
void init() {
	for (int i = 1; i <= 19; i++)
		for (int j = 1; j <= 19; j++)
			if (i != j && isp[i + j])
				adj[i].pb(j);
}

vector<VI> ans;

void dfs(int u, int cur, VI vi) {
	if (cur == (1 << n) - 1) {
		if (!isp[u + 1]) return;
		ans.pb(vi);
		return;
	}
	for (int i = 0; i < (int)adj[u].size(); i++) {
		int v = adj[u][i];
		if (v > n) break;
		if (!(cur & (1 << v - 1))) {
			vi.pb(v);
			dfs(v, cur | (1 << v - 1), vi);
			vi.pop_back();
		}
	}
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	init();
	int cnt = 0;
	while (~scanf("%d", &n)) {
		ans.clear();
		printf("Case %d:\n", ++cnt);

		dfs(1, 1, VI({1}));
		for (int i = 0; i < (int)ans.size(); i++) {
			for (int j = 0; j < (int)ans[i].size(); j++)
				printf("%d%c", ans[i][j], j == (int)ans[i].size() - 1 ? '\n' : ' ');
		}

		puts("");
	}

	return 0;
}
