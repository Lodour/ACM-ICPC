#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*******************************/
/*     Dijkstra 优先队列版       */
/*******************************/
/* 需头文件:    vector, queue      */
/* 修改变量:    MAXN(点数最大值)     */
/*******************************/
const int MAXN = 110;    // 点数最大值
const int INF = 0x3FFFFFFF;
typedef pair<int, int> PII;
typedef vector<PII> VII;
VII G[MAXN];        // G[x] = 点x所指向的点集, 包含长度信息
int vis[MAXN];        // vis[x] = 点x是否访问过
int dis[MAXN];        // dis[x] = 出发点到点x的最短距离
// 针对存图前的初始化
void init(int n) {
    for (int i = 0; i < n; i++)
        G[i].clear();
}
// 添加边: (u)>---w--->(v)
void add_edge(int u, int v, int w) {
    // pair优先比较第一个数据的大小, 因此距离放第一个
    G[u].push_back(make_pair(w, v));
}
// 求最短路: (s)>--->...>--->(n)
void Dijkstra(int s, int n) {
    // 针对遍历前的初始化
    for (int i = 0; i < n; i++) vis[i] = 0;
    for (int i = 0; i < n; i++) dis[i] = INF;
    dis[s] = 0;
    // 优先队列(小), 每次优先弹出距离最短的点
    // 声明格式: priority_queue<数据类型,容器类型,优先大/小> 变量名称;
    priority_queue<PII, VII, greater<PII> > Q;
    Q.push(make_pair(dis[s], s));    // 起始点入队(距离放前面)
    while (!Q.empty()) {
        PII t = Q.top();    // 优先队列Q.top() 普通队列Q.front()
        int x = t.second;    // 每次取最小的点的编号
        Q.pop();            // 最小点出列
        if (vis[x]) continue;
        vis[x] = 1;
        // 下面遍历点x所指向的点集
        for (int i = 0; i < G[x].size(); i++) {
            int y = G[x][i].second;    // 取出一点y
            int w = G[x][i].first;    // (x)>---w--->(y)
            // 未访问过y, 且需要更新最短距离时
            if (!vis[y] && dis[y] > dis[x] + w) {
                dis[y] = dis[x] + w;
                Q.push(make_pair(dis[y], y));    // 新的点入队
            }
        }
    }
    // 此时 dis[x] = 出发点到点x的最短距离 x:[0,n)
    // 若 dis[x] == INF, 说明无法从出发点走到
}

int main() {
    // freopen("data.in","r",stdin);
    int n, m;
    while (cin >> n >> m && n && m) {
        init(n);    // 每张新图都需要初始化
        int a, b, x, s, t;
        while (m--) {
            cin >> a >> b >> x;
            a--; b--;
            add_edge(a, b, x);
            add_edge(b, a, x);
        }
        Dijkstra(0, n);
        cout << dis[n - 1] << endl;
    }
    return 0;
}