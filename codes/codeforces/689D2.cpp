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

const int MAXN = 2000000 + 100;
int a[MAXN], b[MAXN];
deque<int> mx, mn;

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d", &b[i]);

    ll ans = 0;
    for (int i = 1, j = 1; i <= n; i++) {
        while (!mx.empty() && a[mx.back()] <= a[i]) mx.pop_back();
        while (!mn.empty() && b[mn.back()] >= b[i]) mn.pop_back();
        mx.push_back(i);
        mn.push_back(i);
        while (j <= i && a[mx.front()] - b[mn.front()] > 0) {
            j++;
            while (!mx.empty() && mx.front() < j) mx.pop_front();
            while (!mn.empty() && mn.front() < j) mn.pop_front();
        }
        if (!mx.empty() && !mn.empty())
            if (a[mx.front()] == b[mn.front()])
                ans += min(mx.front(), mn.front()) - j + 1;
    }
    printf("%I64d\n", ans);

    return 0;
}