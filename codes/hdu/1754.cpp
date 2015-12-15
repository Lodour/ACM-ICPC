#include <iostream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <cctype>
using namespace std;
#define REP(i,x) for (int i = 0; i < (x); i++)
#define DEP(i,x) for (int i = (x) - 1; i >= 0; i--)
#define FOR(i,x) for (__typeof((x).begin())i = (x).begin(); i != (x).end(); i++)
#define CLR(a,x) memset(a, x, sizeof(a))
#define ALL(x) (x).begin(), (x).end()
#define SZ(v) ((int)v.size())
#define UNIQUE(v) sort(ALL(v)); v.erase(unique(ALL(v)), v.end())
#define debug(x) cout << #x << ": " << x << endl;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define eps 1e-8
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define IT iterator
#define X first
#define Y second
//************************************************

#define lson rt<<1
#define rson rt<<1|1
#define Lson l,m,lson
#define Rson m+1,r,rson

const int maxn = 200010;
int ma[maxn << 2];
void PushUp(int rt) {
    ma[rt] = max(ma[lson], ma[rson]);
}
void build(int l, int r, int rt) {
    if (l == r) {scanf("%d", &ma[rt]); return;}
    int m = (l + r) >> 1;
    build(Lson); build(Rson);
    PushUp(rt);
}
void update(int p, int val, int l, int r, int rt) {
    if (l == r) {ma[rt] = val; return;}
    int m = (l + r) >> 1;
    if (p <= m) update(p, val, Lson);
    else update(p, val, Rson);
    PushUp(rt);
}
int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) return ma[rt];
    int m = (l + r) >> 1, s = 0;
    if (L <= m) s = max(s, query(L, R, Lson));
    if (m < R) s = max(s, query(L, R, Rson));
    return s;
}

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
    // freopen("data.out", "w", stdout);
#endif

    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        build(1, n, 1);
        char op[2]; int i, j;
        while (m--) {
            scanf("%s %d %d", op, &i, &j);
            if (op[0] == 'Q') printf("%d\n", query(i, j, 1, n, 1));
            else update(i, j, 1, n, 1);
        }
    }

    return 0;
}
