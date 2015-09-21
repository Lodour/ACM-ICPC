#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <sstream>
#include <queue>
#include <stack>
#include <string>
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
typedef pair<PII, int> PPI;
typedef vector<int> VI;
#define fi first
#define se second
const double EPS = 1e-8;
const int MOD = 1000000007;
#define debug(x) cout<<#x<<": "<<x<<endl;
#define debug2(x,y) cout<<#x<<": "<<x<<"\t"<<#y<<": "<<y<<endl;
//************************************************
ll ans = 0;
// 拓扑排序模板
// 修改maxn为最大点个数
const int maxn = 10010;
typedef pair<int, int> PII;
#define MP(a,b) make_pair(a,b)
int Ans[maxn];
vector<int> G[maxn];
int deg[maxn];
map<PII, bool> S;
// 存图前初始化
void init(int n) {
    for (int i = 0; i < n; i++)G[i].clear();
    S.clear();
    memset(deg, 0, sizeof(deg));
    memset(Ans, 0, sizeof(Ans));
}
// 添加U->V的有向边
void add_edge(int u, int v) {
    // 判断重边
    if (S[MP(u, v)]) return;
    G[u].push_back(v);
    S[MP(u, v)] = 1;
    deg[v]++;
}
// 直接调用, 如需判断有环, 0有1没有
bool toposort(int n) {
    int tot = 0; ans = 0;
    queue<pair<int, ll> > que;
    for (int i = 0; i < n; ++i)
        if (deg[i] == 0) que.push(MP(i, 888));
    while (!que.empty()) {
        int v = que.front().fi;
        int d = que.front().se;
        ans += d;
        que.pop(); tot++;
        for (int i = 0; i < G[v].size(); ++i) {
            int t = G[v][i];
            if (--deg[t] == 0) que.push(MP(t, d + 1));
        }
    }
    if (tot < n) return false;
    return true;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int n, m;
    while (cin >> n >> m) {
        init(n);
        while (m--) {
            int a, b;
            cin >> a >> b;
            add_edge(b - 1, a - 1);
        }
        if (!toposort(n)) ans = -1;
        cout << ans << endl;
    }
    return 0;
}