#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<PII> VII;
#define inf 0x3f3f3f3f
#define mod 1000000007
#define eps 1e-18
#define mp(x,y) make_pair(x,y)
#define pb(x) push_back(x)
#define mt(a,b...) make_tuple(a,b)
#define IT iterator
#define X first
#define Y second
#define MO(a,b) (((a)%(b)+(b))%(b))
#define set(a,x) memset(a, x, sizeof(a))
#define REP(i,x) for(int i = 0; i < (int)(x); i++)
#define DEP(i,x) for(int i = (int)(x)-1; i >= 0; i--)
#define out(x) cout << #x << ": " << x << endl;
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif


	fastcin;
	string s, t;
	int cs[26], ct[26];
	while (cin >> s >> t) {
		set(cs, 0); set(ct, 0);
		for (int i = 0; i < (int)s.size(); i++)
			cs[s[i] - 'A']++;
		for (int i = 0; i < (int)t.size(); i++)
			ct[t[i] - 'A']++;
		sort(cs, cs + 26);
		sort(ct, ct + 26);
		bool f = 1;
		for (int i = 0; i < 26; i++)
			if (cs[i] != ct[i]) f = 0;
		cout << (f ? "YES" : "NO") << endl;
	}

	return 0;
}
