#include <iostream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <queue>
using namespace std;

/*******************************/
/*     Dijkstra - 邻接矩阵版     */
/*******************************/
/* 头文件:	None               */
/* 修改变量:	MAXN(点数最大值)	   */
/*******************************/
const int MAXN = 1010;	// 点数最大值
const int INF = 0x3FFFFFFF;
int G[MAXN][MAXN];	// G[x][y] ＝ x到y的距离
int vis[MAXN];		// vis[x] = 点x是否访问过
int dis[MAXN];		// dis[x] = 出发点到点x的最短距离
// 针对存图前的初始化
void init(int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			G[i][j] = INF;
}
// 添加边: (u)>---w--->(v)
void add_edge(int u, int v, int w) {
	G[u][v] = min(G[u][v], w);
}
// 求最短路: (s)>--->...>--->(n)
void Dijkstra(int s, int n) {
	// 针对遍历前的初始化
	for (int i = 0; i < n; i++) vis[i] = 0;
	for (int i = 0; i < n; i++) dis[i] = INF;
	dis[s] = 0;
	// 开始遍历整张图
	for (int i = 0; i < n; i++) {
		int x; // 即将遍历的点x
		int min_dis = INF; // 未访问点中的最短距离
		// 在剩余点中寻找路程最短的
		for (int j = 0; j < n; j++) {
			if (!vis[j] && dis[j] <= min_dis) {
				x = j;
				min_dis = dis[j];
			}
		}
		vis[x] = 1; // 访问找到的最短点
		// 对于所有x可以到达的点j, 更新dis[j]
		// 如果不能到达, G[x][j]=INF, 不会更新
		for (int j = 0; j < n; j++)
			dis[j] = min(dis[j], dis[x] + G[x][j]);
	}
	// 此时 dis[x] = 出发点到点x的最短距离 x:[0,n)
	// 若 dis[x] == INF, 说明无法从出发点走到
}

void Transform(int n) {
	for (int i = 0; i < n; i++)
		for (int j = 0; j < i; j++)
			swap(G[i][j], G[j][i]);
}

int main() {
	// freopen("data.in", "r", stdin);
	int n, m, x;
	while (cin >> n >> m >> x) {
		init(n);	// 每张新图都需要初始化
		x--;
		int a, b, t;
		while (m--) {
			cin >> a >> b >> t;
			a--; b--;
			add_edge(a, b, t);
		}
		int d[MAXN], ans = -1;
		Dijkstra(x, n);
		for (int i = 0; i < n; i++)
			d[i] = dis[i];
		Transform(n);
		Dijkstra(x, n);
		for (int i = 0; i < n; i++) {
			if (d[i] == INF || dis[i] == INF) continue;
			d[i] += dis[i];
			ans = max(ans, d[i]);
		}
		cout << ans << endl;
	}
	return 0;
}