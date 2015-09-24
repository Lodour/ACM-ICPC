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
//const int MOD = 1000000007;
#define debug(x) cout<<#x<<": "<<x<<endl;
#define debug2(x,y) cout<<#x<<": "<<x<<"\t"<<#y<<": "<<y<<endl;
/****************************************************************************/
int h, w, n;
int a[800800];

void build(int l, int r, int u) {
    a[u] = w;
    if (l == r) return;
    int mid = (l + r) / 2;
    build(l, mid, u * 2);
    build(mid + 1, r, u * 2 + 1);
}
int query(int u, int l, int r, int x) {
    if (l == r) {
        if (a[u] >= x) {
            a[u] -= x;
            return l;
        }
        else return -1;
    }
    int mid = (l + r) / 2, ans;
    if (a[u * 2] >= x) ans = query(u * 2, l, mid, x);
    else ans = query(u * 2 + 1, mid + 1, r, x);
    a[u] = max(a[u * 2], a[u * 2 + 1]);
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    while (~scanf("%d%d%d", &h, &w, &n)) {
        h = min(h, n);
        build(1, h, 1);
        int t;
        while (n--) {
            scanf("%d", &t);
            //if(a[1]<t) puts("-1");
            //else
            printf("%d\n", query(1, 1, h, t));
        }
    }

    return 0;
}