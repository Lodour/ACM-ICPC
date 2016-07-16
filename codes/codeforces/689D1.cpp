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
#define MOD 1000000007
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define IT iterator
#define X first
#define Y second
#define lson rt<<1
#define rson rt<<1|1
// ************************************************************************
const int MAXN = 200000 + 100;
int mmax[MAXN][30], mmin[MAXN][30];
int a[MAXN], b[MAXN], n, k;

void init() {
    for (int i = 1; i <= n; i++) {
        mmax[i][0] = a[i];
        mmin[i][0] = b[i];
    }
    for (int j = 1; (1 << j) <= n; j++)
        for (int i = 1; i + (1 << j) - 1 <= n; i++) {
            mmax[i][j] = max(mmax[i][j - 1], mmax[i + (1 << (j - 1))][j - 1]);
            mmin[i][j] = min(mmin[i][j - 1], mmin[i + (1 << (j - 1))][j - 1]);
        }
}

// op=0/1 返回[l,r]最大/小值
int rmq(int l, int r, int op) {
    int k = 0;
    while ((1 << (k + 1)) <= r - l + 1) k++;
    if (op == 0) return max(mmax[l][k], mmax[r - (1 << k) + 1][k]);
    return min(mmin[l][k], mmin[r - (1 << k) + 1][k]);
}


int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);
    init();
    ll res = 0;
    for (int L = 1; L <= n; L++) {
        int R = n;
        int l, r, m;
        int p1, p2;
        p1 = p2 = -1;

        l = L, r = R + 1;
        while (l < r) {
            m = (l + r) >> 1;
            if (rmq(L, m, 0) - rmq(L, m, 1) >= 0) r = m;
            else l = m + 1;
        }
        if (rmq(L, l, 0) - rmq(L, l, 1) == 0) p1 = l;

        l = L, r = R + 1;
        while (l < r) {
            m = (l + r) >> 1;
            if (rmq(L, m, 0) - rmq(L, m, 1) > 0) r = m;
            else l = m + 1;
        }
        if (rmq(L, l, 0) - rmq(L, l, 1) > 0 || l == n + 1) p2 = l;

        // cout << L << " :  " << p1 << " " << p2 << endl;
        if (p1 != -1 && p2 != -1)
            res += p2 - p1;
    }
    printf("%I64d\n", res);

    return 0;
}