#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))
#define pb push_back
typedef vector<int> VI;

const int N = 111;
int n, m;
int dp[N][N], num[N], pos[N];
bool vis[N];
VI g[N];

void dfs(int rt) {
    vis[rt] = 1;
    for (int i = num[rt]; i <= m; i++)
        dp[rt][i] = pos[rt];
    for (int i = 0; i < (int)g[rt].size(); i++) {
        int son = g[rt][i];
        if (vis[son]) continue;
        dfs(son);
        for (int j = m; j >= num[rt]; j--)
            for (int k = 1; k <= m - j; k++)
                if (dp[son][k])
                    dp[rt][j + k] = max(dp[rt][j + k], dp[rt][j] + dp[son][k]);
    }
}


int main() {
#ifdef MANGOGAO
    freopen("C:\\Users\\Lodour\\Desktop\\data.in", "r", stdin);
#endif

    while (~scanf("%d%d", &n, &m) && n != -1 && m != -1) {
        for (int i = 1; i <= n; i++) {
            scanf("%d%d", num + i, pos + i);
            num[i] = (num[i] + 19) / 20;
        }
        for (int i = 1; i <= n; i++)
            g[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            g[u].pb(v);
            g[v].pb(u);
        }
        if(!m){
            puts("0");
            continue;
        }
        set(dp, 0); set(vis, 0);
        dfs(1);
        printf("%d\n", dp[1][m]);
    }

    return 0;
}
