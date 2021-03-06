#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iterator>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
using namespace std;
#define INF 0x3FFFFFFF
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define REP(i,x) for(int i=0;i<(int)(x);i++)
#define REP2(X,L,R) for(int X=(int)L;X<=(int)R;X++)
#define DEP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define DEP2(X,L,R) for(int X=(int)L;X>=(int)R;X--)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();i++)
#define CLR(A,X) memset(A,X,sizeof(A))
#define ALL(container) (container).begin(), (container).end()
#define SZ(container) ((int)container.size())
#define UNIQUE(v) sort(ALL(v)); v.erase( unique(v.begin(), v.end()), v.end() );
#define IT iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define fi first
#define se second
const double EPS = 1e-8;
const int MOD = 1000000007;
#define debug(x) cout<<#x<<": "<<x<<endl;
#define debug2(x,y) cout<<#x<<": "<<x<<"\t"<<#y<<": "<<y<<endl;
//************************************************
typedef pair<int, int> PII;
typedef vector<PII> VII;
const int MAXN = 1010;
vector<PII> G[MAXN];
void add_edge(int u, int v, int d) {
    G[u].PB(MP(v, d));
}
void init(int n) {
    for (int i = 0; i < n; i++) {
        G[i].clear();
    }
}
int vis[MAXN];
int dis[MAXN];
void dijkstra(int s, int n) {
    for (int i = 0; i < n; i++)vis[i] = 0;
    for (int i = 0; i < n; i++)dis[i] = (i == s ? 0 : INF);
    priority_queue<PII, VII, greater<PII> >q;
    q.push(MP(dis[s], s));
    while (!q.empty()) {
        PII p = q.top();
        int x = p.second;
        q.pop();
        if (vis[x])continue;
        vis[x] = 1;
        for (int i = 0; i < G[x].size(); i++) {
            int y = G[x][i].first;
            int d = G[x][i].second;
            if (!vis[y] && dis[x] + d < dis[y]) {
                dis[y] = dis[x] + d;
                q.push(MP(dis[y], y));
            }
        }
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int t, s, d, maxn = 0;
    while (cin >> t >> s >> d) {
        init(1001);
        REP(i, t) {
            int a, b, c;
            cin >> a >> b >> c;
            maxn = max(maxn, max(a, b));
            add_edge(a, b, c);
            add_edge(b, a, c);
        }
        REP(i, s) {
            int a;
            cin >> a;
            add_edge(0, a, 0);
            add_edge(a, 0, 0);
        }
        maxn++;
        REP(i, d) {
            int des;
            cin >> des;
            add_edge(des, maxn, 0);
            add_edge(maxn, des, 0);
        }
        dijkstra(0, maxn + 1);
        //REP(j,maxn+1)debug2(j,dis[j])
        cout << dis[maxn] << endl;
    }

    return 0;
}