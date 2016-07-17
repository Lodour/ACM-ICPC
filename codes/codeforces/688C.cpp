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
#define mod 1000000007
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define IT iterator
#define X first
#define Y second
#define lson rt<<1
#define rson rt<<1|1
// ************************************************************************

const int N = 100000 + 100;
VI G[N];
int s[N];
bool ans = 1;

void dfs(int u, int op) {
    if (!ans) return;
    s[u] = op;
    for (auto v : G[u]) {
        if (s[v] == op) {
            ans = 0;
            return;
        }
        if (s[v] == -1) dfs(v, 1 - op);
    }
}

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int n, m, st;
    scanf("%d%d", &n, &m);
    while (m--) {
        int u, v;
        scanf("%d%d", &u, &v);
        G[u].pb(v);
        G[v].pb(u);
    }
    set(s, -1);

    for (int i = 1; i <= n; i++)
        if (!G[i].empty() && s[i] == -1)
            dfs(i, 0);

    if (!ans) {
        puts("-1");
    }
    else {
        VI a, b;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 0) a.pb(i);
            if (s[i] == 1) b.pb(i);
        }
        printf("%d\n", a.size());
        for (int i = 0; i < (int)a.size(); i++)
            printf("%d%c", a[i], i == (int)a.size() - 1 ? '\n' : ' ');
        printf("%d\n", b.size());
        for (int i = 0; i < (int)b.size(); i++)
            printf("%d%c", b[i], i == (int)b.size() - 1 ? '\n' : ' ');
    }
    return 0;
}
