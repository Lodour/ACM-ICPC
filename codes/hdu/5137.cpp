#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <functional>
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
#define sz(container) ((int)container.size())
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
#define INF 0x3FFFFFFF
typedef pair<int, int> PII;
const int MAXN = 100010;
vector<PII> G[MAXN];
void add_edge(int u, int v, int d) {
    G[u].push_back(make_pair(v, d));
}
void init(int n) {
    for (int i = 0; i < n; i++)G[i].clear();
}
int vis[MAXN];
int dis[MAXN];
void spfa(int s, int n, int k) {
    for (int i = 0; i < n; i++)dis[i] = (i == s ? 0 : INF);
    memset(vis, 0, sizeof(vis));
    queue<int>q;
    q.push(s);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        vis[x] = 0;
        for (int i = 0; i < G[x].size(); i++) {
            int y = G[x][i].first;
            int d = G[x][i].second;
            if (y == k)continue;
            if (dis[y] > dis[x] + d) {
                dis[y] = dis[x] + d;
                if (!vis[y]) {
                    q.push(y);
                    vis[y] = 1;
                }
            }
        }
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    while (scanf("%d%d", &n, &m) == 2 && n) {
        init(n);
        while (m--) {
            int a, b, c; scanf("%d%d%d", &a, &b, &c);
            a--; b--;
            add_edge(a, b, c);
            add_edge(b, a, c);
        }
        int ans = -1;
        for (int i = 1; i < n - 1; i++) {
            spfa(0, n, i);
            ans = max(ans, dis[n - 1]);
        }
        if (ans == INF)cout << "Inf" << endl;
        else cout << ans << endl;
    }

    return 0;
}