#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;
#define X first
#define Y second
#define mp make_pair
typedef pair<int, int> PII;
typedef pair<PII, int> PIII;

const int inf = 0x3f3f3f3f;
const int dx[] = { -2, -1, 1, 2};
const int dy[] = {1, 2, 2, 1};
int n, m, a, b, c, d;
bool vis[22][22];

bool bfs() {
	queue<PIII> q;
	q.push(mp(mp(a, b), 0));
	while (!q.empty()) {
		PII u = q.front().X;
		int dis = q.front().Y;
		q.pop();
		if (u.X == c && u.Y == d)
			return printf("%d\n", dis);
		for (int i = 0; i < 4; i++) {
			int nx = u.X + dx[i];
			int ny = u.Y + dy[i];
			if (nx <= 0 || ny <= 0 || nx > n || ny > m)
				continue;
			q.push(mp(mp(nx, ny), dis + 1));
		}
	}
	return puts("Impossible");
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	while (~scanf("%d%d", &n, &m)) {
		scanf("%d%d%d%d", &a, &b, &c, &d);
		bfs();
	}
	return 0;
}
