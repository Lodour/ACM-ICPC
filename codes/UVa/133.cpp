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

int n, k, m;
bool vis[22];
int go(int s, int d, int cnt) {
	while (cnt--)
		do {s = MO(s + d - 1, n) + 1;} while (vis[s]);
	return s;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif


	fastcin;
	while (cin >> n >> k >> m, n, k, m) {
		set(vis, 0);
		int tot = n, p = n, q = 1;
		bool fi = 1;
		while (tot) {
			if (!fi) putchar(',');
			fi = 0;
			p = go(p, 1, k);
			q = go(q, -1 , m);
			if (p != q) {
				printf("%3d%3d", p, q);
				tot -= 2;
			}
			else {
				printf("%3d", p);
				tot--;
			}
			vis[p] = vis[q] = 1;
		}
		puts("");
	}

	return 0;
}
