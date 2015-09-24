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

const int maxn = 222;
int n, m;
char f[maxn][maxn];
int g[maxn][maxn][2];
bool vis[maxn][maxn];
const int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};

void bfs(int x, int y, int k) {
    CLR(vis, 0);
    queue<PII> q;
    q.push(MP(x, y));
    vis[x][y] = 1;
    while (!q.empty()) {
        int tx = q.front().X;
        int ty = q.front().Y;
        q.pop();
        REP(i, 4) {
            int nx = tx + dir[i][0];
            int ny = ty + dir[i][1];
            if (nx < 0 || ny < 0 || nx >= n || ny >= m || vis[nx][ny] || f[nx][ny] == '#') continue;
            vis[nx][ny] = 1;
            g[nx][ny][k] = g[tx][ty][k] + 11;
            q.push(MP(nx, ny));
        }
    }
    /*
    REP(i,n){
        REP(j,m) cout<<g[i][j][k]<<" ";
        cout<<endl;
    }
    */


}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    while (cin >> n >> m) {
        int dx1, dx2, dy1, dy2;
        string line;
        int ans = INF;
        REP(i, n) {
            cin >> line;
            REP(j, m) {
                if (line[j] == 'Y') {dx1 = i; dy1 = j; line[j] = '.';}
                if (line[j] == 'M') {dx2 = i; dy2 = j; line[j] = '.';}
                f[i][j] = line[j];
            }
        }
        CLR(g, 0);
        bfs(dx1, dy1, 0);
        bfs(dx2, dy2, 1);
        REP(i, n)REP(j, m) if (f[i][j] == '@' && g[i][j][0] && g[i][j][1]) ans = min(ans, g[i][j][0] + g[i][j][1]);
        cout << ans << endl;
    }

#ifndef ONLINE_JUDGE
    cout << "Done..." << endl;
    while (1);
#endif
    return 0;
}