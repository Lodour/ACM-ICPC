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
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
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
#define X first
#define Y second
const double EPS = 1e-8;
const int MOD = 1000000007;
#define debug(x) cout<<#x<<": "<<x<<endl;
#define debug2(x,y) cout<<#x<<": "<<x<<"\t"<<#y<<": "<<y<<endl;
//************************************************

int n, m, k, sx, sy, ex, ey;
bool ans, vis[10][10];
char mp[10][10];
const int dis[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

void dfs(int x, int y, int cnt) {
    if (cnt > k || ans) return;
    if (cnt == k && mp[x][y] == 'D') {ans = 1; return;}
    int MIN = abs(x - ex) + abs(y - ey);
    if (MIN + cnt > k || (MIN + k - cnt) % 2 != 0)return;
    //cout<<cnt<<" "<<mp[x][y];debug2(x,y)
    REP(i, 4) {
        int nx = x + dis[i][0];
        int ny = y + dis[i][1];
        if (nx >= 0 && ny >= 0 && nx < n && ny < m && !vis[nx][ny] && mp[nx][ny] != 'X') {
            vis[nx][ny] = 1;
            dfs(nx, ny, cnt + 1);
            vis[nx][ny] = 0;
        }
    }

}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> m >> k && n) {
        string s; REP(i, n) {
            cin >> s;
            REP(j, m) {
                if (s[j] == 'S') {sx = i; sy = j; mp[i][j] = '.';}
                if (s[j] == 'D') {ex = i; ey = j;}
                mp[i][j] = s[j];
            }
        }
        ans = 0; CLR(vis, 0); vis[sx][sy] = 1;
        dfs(sx, sy, 0);
        cout << (ans ? "YES" : "NO") << endl;
    }

    return 0;
}