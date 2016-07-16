#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <functional>
#include <cstdlib>
#include <climits>
#include <cctype>
using namespace std;
#define REP(i,x) for(int i = 0; i < (int)(x); i++)
#define DEP(i,x) for(int i = (int)(x) - 1; i >= 0; i--)
#define FOR(i,x) for(__typeof(x.begin())i=x.begin(); i!=x.end(); i++)
#define set(a,x) memset(a, x, sizeof(a))
#define mo(a,b) (((a)%(b)+(b))%(b))
#define all(x) (x).begin(), (x).end()
#define sz(v) ((int)v.size())
#define UNIQUE(v) sort(all(v)); v.erase(unique(all(v)), v.end())
#define out(x) cout << #x << ": " << x << endl;
#define zero(x) (fabs(x)<eps?1:0)
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);
#define pq priority_queue
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
#define inf 0x3f3f3f3f
#define eps 1e-8
#define MOD 1000000007
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define IT iterator
#define X first
#define Y second
#define lson rt<<1
#define rson rt<<1|1
// ************************************************************************
// pair<权值, 点>
// 记得初始化
const int MAXN = 200000 + 100;
VII G[MAXN];
int vis[MAXN], dis[MAXN];
void init(int n) {
    for (int i = 0; i < n; i++)
        G[i].clear();
}
void add_edge(int u, int v, int w) {
    G[u].push_back(make_pair(w, v));
}
void Dijkstra(int s, int n) {
    memset(vis, 0, sizeof(vis));
    memset(dis, 0x3F, sizeof(dis));
    dis[s] = 0;
    priority_queue<PII, VII, greater<PII> > q;
    q.push(make_pair(dis[s], s));
    while (!q.empty()) {
        PII t = q.top();
        int x = t.second;
        q.pop();
        if (vis[x]) continue;
        vis[x] = 1;
        for (int i = 0; i < (int)G[x].size(); i++) {
            int y = G[x][i].second;
            int w = G[x][i].first;
            if (!vis[y] && dis[y] > dis[x] + w) {
                dis[y] = dis[x] + w;
                q.push(make_pair(dis[y], y));
            }
        }
    }
}

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    init(n);
    for (int i = 0; i < n; i++) {
        add_edge(i, i + 1, 1);
        add_edge(i + 1, i, 1);
    }
    for (int i = 0; i < n; i++) {
        int v;
        scanf("%d", &v);
        if (v == i) continue;
        add_edge(i, v - 1, 1);
    }
    Dijkstra(0, n);
    for (int i = 0; i < n; i++)
        printf("%d%c", dis[i], i == n - 1 ? '\n' : ' ');

    return 0;
}


