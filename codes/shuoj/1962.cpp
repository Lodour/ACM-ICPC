#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;
#define mp make_pair
#define X first
#define Y second
typedef pair<int, int> PII;
const int maxn = 110;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

char map[maxn][maxn];
bool vis[maxn][maxn][2];
int n, m;
PII st;

int solve() {
	memset(vis, 0, sizeof(vis));
	queue<pair<PII, PII> > Q;
	Q.push(mp(st, mp(0, 0)));
	while (!Q.empty()) {
		int px = Q.front().X.X;
		int py = Q.front().X.Y;
		int state = Q.front().Y.X;
		int step = Q.front().Y.Y;
		Q.pop();
		if (map[px][py] == 'T') return step;
		if (map[px][py] == '@' && !vis[px][py][!state]) {
			vis[px][py][!state] = 1;
			Q.push(mp(mp(px, py), mp(!state, step + 1)));
		}
		for (int i = 0; i < 4; i++) {
			int nx = px + dx[i];
			int ny = py + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (vis[nx][ny][state] || map[nx][ny] == '#') continue;
			if (state == 0 && map[nx][ny] == 'w') continue;
			if (state == 1 && map[nx][ny] == '~') continue;
			vis[nx][ny][state] = 1;
			Q.push(mp(mp(nx, ny), mp(state, step + 1)));
		}
	}
	return -1;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++) {
			scanf("%s", map[i]);
			for (int j = 0; j < m; j++)
				if (map[i][j] == 'S')
					st = mp(i, j);
		}
		int ans = solve();
		if (ans == -1) puts("Sad Yaoge!");
		else printf("%d\n", ans);
	}

	return 0;
}
