#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))

char g[11][11];
int vis[11][11];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};
char dd[] = {'E', 'W', 'N', 'S'};
int n, m, k;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
// freopen("data.out", "w", stdout);
#endif

	while (~scanf("%d%d", &n, &m) && m && n) {
		scanf("%d", &k);
		for (int i = 0; i < n; i++)
			scanf("%s", g[i]);
		set(vis, -1);
		int x = 0, y = k - 1, nx, ny;
		int cnt = 0;
		while (vis[x][y] == -1) {
			vis[x][y] = cnt++;
			for (int i = 0; i < 4; i++)
				if (g[x][y] == dd[i]) {
					nx = x + dx[i];
					ny = y + dy[i];
					break;
				}
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				break;
			else {
				x = nx;
				y = ny;
			}
		}
		if (vis[x][y] + 1 == cnt) {
			printf("%d step(s) to exit\n", cnt);
		}
		else {
			printf("%d step(s) before a loop of %d step(s)\n", vis[x][y], cnt - vis[x][y]);
		}
	}

	return 0;
}
