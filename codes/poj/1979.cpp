#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

int n, m, ans = 0;
char mp[22][22];
bool vis[22][22];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
void dfs(int x, int y) {
	vis[x][y] = 1;
	ans++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx < 0 || ny < 0 || nx >= n || ny >= m)continue;
		if (vis[nx][ny] || mp[nx][ny] != '.')continue;
		dfs(nx, ny);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	while (cin >> m >> n && n) {
		int sx, sy;
		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				mp[i][j] = s[j];
				if (s[j] == '@') {
					mp[i][j] = '.';
					sx = i;
					sy = j;
				}
			}
		}
		ans = 0;
		memset(vis, 0, sizeof(vis));
		dfs(sx, sy);
		cout << ans << endl;
	}

	return 0;
}ƒ