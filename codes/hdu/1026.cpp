#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))
#define X first
#define Y second
#define mp make_pair
typedef pair<int, int> PII;

const int N = 111;
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};
int n, m;
char str[N];
int g[N][N];
PII pre[N][N];
bool vis[N][N];
int ans[N][N];
int tot;

struct Node {
	int t;
	int x, y;
	int px, py;
	Node(int a, int b, int c, int d, int e) {
		x = a; y = b; px = c; py = d; t = e;
	}
	bool operator < (const Node &b) const {
		return b.t < t;
	}
};

void output(int x, int y, int t) {
	if (x == 0 && y == 0) return;
	output(pre[x][y].X, pre[x][y].Y, ans[x][y]);
	printf("%ds:(%d,%d)->(%d,%d)\n", ++tot, pre[x][y].X, pre[x][y].Y, x, y);
	while (g[x][y]--)
		printf("%ds:FIGHT AT (%d,%d)\n", ++tot, x, y);
}

bool bfs() {
	priority_queue<Node> pq;
	Node cur(0, 0, -1, -1, g[0][0]);
	pq.push(cur);
	while (!pq.empty()) {
		cur = pq.top(); pq.pop();
		pre[cur.x][cur.y] = mp(cur.px, cur.py);
		ans[cur.x][cur.y] = cur.t;
		vis[cur.x][cur.y] = 1;
		if (cur.x == n - 1 && cur.y == m - 1) {
			printf("It takes %d seconds to reach the target position, let me show you the way.\n", cur.t);
			tot = 0;
			output(cur.x, cur.y, cur.t);
			return 1;
		}
		for (int i = 0; i < 4; i++) {
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m) continue;
			if (vis[nx][ny] || g[nx][ny] == -1) continue;
			int nt = cur.t + 1 + g[nx][ny];
			vis[nx][ny] = 1;
			pq.push(Node(nx, ny, cur.x, cur.y, nt));
		}
	}
	return 0;
}



int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	while (~scanf("%d%d", &n, &m)) {
		for (int i = 0; i < n; i++) {
			scanf("%s", str);
			for (int j = 0; j < m; j++)
				g[i][j] = str[j] == 'X' ? -1 : str[j] == '.' ? 0 : str[j] - '0';
		}
		set(pre, -1); set(ans, 0); set(vis, 0);
		if (!bfs()) puts("God please help our poor hero.");
		puts("FINISH");
	}

	return 0;
}
