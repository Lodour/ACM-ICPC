#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))

bool vis[25][25][25];
int ans[25], tot;
int x, y, z;

void dfs(int a, int b, int c) {
	if (vis[a][b][c]) return;
	vis[a][b][c] = 1;
	if (a == 0) ans[tot++] = c;
	dfs(max(0, a - (y - b)), min(b + a, y), c);	// x to y
	dfs(min(a + b, x), max(0, b - (x - a)), c);	// y to x
	dfs(a, max(0, b - (z - c)), min(b + c, z)); // y to z
	dfs(a, min(b + c, y), max(0, c - (y - b)));	// z to y
	dfs(max(0, a - (z - c)), b, min(c + a, z));	// x to z
	dfs(min(x, a + c), b, max(0, c - (x - a))); // z to x
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	while (~scanf("%d%d%d", &x, &y, &z)) {
		set(vis, 0); tot = 0;
		dfs(0, 0, z);
		sort(ans, ans + tot);
		for (int i = 0; i < tot; i++)
			printf("%d%c", ans[i], i == tot - 1 ? '\n' : ' ');
	}

	return 0;
}
