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
int num[200200];
int t[800800];
void creat(int x, int left, int right)
{
    if (left == right)
    {
        t[x] = num[left];
        return;
    }
    creat(x * 2, left, (left + right) / 2);
    creat(x * 2 + 1, (left + right) / 2 + 1, right);
    t[x] = max(t[x * 2], t[x * 2 + 1]);
}
void add(int x, int left, int right, int pos, int q)
{
    if (left == right && right == pos)
    {
        t[x] = q;
        return;
    }
    if (pos <= (left + right) / 2)
    {
        add(x * 2, left, (left + right) / 2, pos, q);
    }
    else
    {
        add(x * 2 + 1, (left + right) / 2 + 1, right, pos, q);
    }
    t[x] = max(t[x * 2], t[x * 2 + 1]);
}
int count(int x, int left, int right, int lb, int rb)
{
    if (left == lb && right == rb)
    {
        return t[x];
    }
    if (rb <= (left + right) / 2)
    {
        return count(x * 2, left, (left + right) / 2, lb, rb);
    }
    else if (lb > (left + right) / 2)
    {
        return count(x * 2 + 1, (left + right) / 2 + 1, right, lb, rb);
    }
    else
    {
        return max(count(x * 2, left, (left + right) / 2, lb, (left + right) / 2), count(x * 2 + 1, (left + right) / 2 + 1, right, (left + right) / 2 + 1, rb));
    }
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        REP2(i, 1, n) scanf("%d", &num[i]);
        creat(1, 1, n);
        while (m--) {
            char op;
            int i, j;
            getchar();
            scanf("%c %d %d", &op, &i, &j);
            if (op == 'U') add(1, 1, n, i, j);
            else printf("%d\n", count(1, 1, n, i, j));
        }
    }

    return 0;
}