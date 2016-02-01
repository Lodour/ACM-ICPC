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

int f(string s) {
	int cc = 0;
	for (int i = 0; i < (int)s.size(); i++)
		if (s[i] != ' ')
			cc++;
	return cc;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif


	fastcin;
	int T;
	while (cin >> T && T != -1) {
		int cnt = 0;
		string s, t;
		cin >> s >> t;
		cout << "Round " << T << endl;
		for (int i = 0; i < (int)t.size(); i++) {
			if (s.find(t[i]) == string::npos)
				cnt++;
			else
				for (int j = 0; j < (int)s.size(); j++)
					if (s[j] == t[i])
						s[j] = ' ';
			if (cnt == 7)
				break;
			if (f(s) == 0) break;
		}

		if (cnt >= 7) cout << "You lose." << endl;
		else if (f(s) != 0) cout << "You chickened out." << endl;
		else cout << "You win." << endl;
	}

	return 0;
}
