#include <bits/stdc++.h>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))
const int N = 10;
const int T = 50;
int n, m, t, sx, sy;
bool vis[N][N];
char mp[N][N];

bool inline in(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < m;
}
const int dx[] = { -1, 0, 0, 1};
const int dy[] = {0, -1, 1, 0};

bool dfs(int x, int y, int p) {
	vis[x][y] = 1;
	bool rt = 0;
	if (p == t) return mp[x][y] == 'D';
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!rt && in(nx, ny) && !vis[nx][ny])
			if (mp[nx][ny] != 'X' && p + 1 <= t) {
				rt |= dfs(nx, ny, p + 1);
				vis[nx][ny] = 0;
			}
	}
	return rt;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	while (~scanf("%d%d%d", &n, &m, &t) && n && m) {
		for (int i = 0; i < n; i++) {
			scanf("%s", mp[i]);
			for (int j = 0; j < m; j++)
				if (mp[i][j] == 'S')
					sx = i, sy = j;
		}
		set(vis, 0);
		puts(dfs(sx, sy, 0) ? "YES" : "NO");
	}

	return 0;
}
