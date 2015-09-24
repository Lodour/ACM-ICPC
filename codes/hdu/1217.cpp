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

#define INF 0x3FFFFFFF
const int MAXN = 33;
double G[MAXN][MAXN];
void init(int n) {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            //G[i][j] = INF;
            if (i == j)G[i][j] = 1;
            else G[i][j] = 0;
}
void Floyd(int n) {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (G[i][j] < G[i][k]*G[k][j])
                    G[i][j] = G[i][k] * G[k][j];
            }
        }
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int n, m, cnt = 0;
    while (cin >> n && n) {
        init(n);
        map<string, int> f;
        string s;
        REP(i, n) {
            cin >> s;
            f[s] = i;
        }
        cin >> m;
        while (m--) {
            string a, b; double c;
            cin >> a >> c >> b;
            G[f[a]][f[b]] = c;
        }
        Floyd(n);
        bool ans = 0;
        //REP(i,n){REP(j,n)cout<<G[i][j]<<" ";cout<<endl;}
        REP(i, n) if (G[i][i] > 1) ans = 1;
        cout << "Case " << ++cnt << ": ";
        cout << (ans ? "Yes" : "No") << endl;
    }

    return 0;
}