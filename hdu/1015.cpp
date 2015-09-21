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

int n; string key;
vector<string> ans;

ll cal(char c, int cnt) {
    ll r = (cnt & 1) ? -1 : 1;
    cnt++;
    while (cnt--)r *= c - 'A' + 1;
    return r;
}

void check(string s) {
    vector<string> tt;
    sort(ALL(s));
    // reverse(ALL(s));
    do {
        ll sum = 0;
        REP(i, sz(s)) sum += cal(s[i], i);
        // if(s=="GHOST")debug(sum)
        if (sum == n) tt.pb(s);
    } while (next_permutation(ALL(s)));
    if (sz(tt)) {
        sort(ALL(tt));
        ans.pb(tt[sz(tt) - 1]);
    }
}

void dfs(int i, string s) {
    if (s.size() == 5) {
        check(s);
        return;
    }
    if (s.size() > 5 || i >= key.size()) return;
    dfs(i + 1, s + key[i]);
    dfs(i + 1, s);
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    ios::sync_with_stdio(0);
    cin.tie(0);


    while (cin >> n >> key && n && key != "END") {
        ans.clear();
        dfs(0, "");
        sort(ans.begin(), ans.end());
        if (ans.size()) cout << ans[sz(ans) - 1] << endl;
        else cout << "no solution" << endl;
    }
    return 0;
}