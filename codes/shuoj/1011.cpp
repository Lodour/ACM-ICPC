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
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define DEP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define DEPS(i,x) for(int i=((int)(x));i>0;i--)
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

const int maxn = 1e4 + 1;
int n, k, a[22], prime[maxn], tot;
bool vis[maxn];
ll ans;

bool check(int n) {
    REP(i, tot) {
        if (prime[i]*prime[i] > n) break;
        if (n % prime[i] == 0) return 0;
    }
    return 1;
}

void dfs(int i, ll sum, int cnt) {
    if (cnt == k) {ans += check(sum); return;}
    if (i >= n) return;
    dfs(i + 1, sum, cnt);
    dfs(i + 1, sum + a[i], cnt + 1);
    return;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int i = 2; i < maxn; i++)
        if (!vis[i]) {
            prime[tot++] = i;
            for (int j = i * 2; j < maxn; j += i)
                vis[j] = 1;
        }

    while (cin >> n >> k) {
        REP(i, n)cin >> a[i];
        ans = 0;
        dfs(0, 0, 0);
        cout << ans << endl;
    }
    return 0;
}

/**************************************************************
    Problem: 1011
    User: 14123090
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1600 kb
****************************************************************/