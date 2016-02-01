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

typedef pair<int, VI> PIV;
vector<PIV> ops;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	int n, m, T = 0;
	while (~scanf("%d%d", &n, &m), n, m) {
		if(T) puts("");
		printf("Spreadsheet #%d\n", ++T);
		int cnt; ops.clear();
		scanf("%d", &cnt);
		while (cnt--) {
			char op[5];
			scanf("%s", op);
			VI tmp; int x;
			if (op[0] == 'E' && op[1] == 'X') {
				for (int i = 0; i < 4; i++) {
					scanf("%d", &x);
					tmp.pb(x);
				}
				ops.pb(mp(0, tmp));
			}
			else {
				scanf("%d", &x); int y;
				while (x--) {
					scanf("%d", &y);
					tmp.pb(y);
				}
				if (op[0] == 'I' && op[1] == 'R') ops.pb(mp(1, tmp));
				if (op[0] == 'I' && op[1] == 'C') ops.pb(mp(2, tmp));
				if (op[0] == 'D' && op[1] == 'R') ops.pb(mp(3, tmp));
				if (op[0] == 'D' && op[1] == 'C') ops.pb(mp(4, tmp));
			}
		}
		scanf("%d", &cnt);
		while (cnt--) {
			int x, y;
			scanf("%d%d", &x, &y);
			printf("Cell data in (%d,%d) ", x, y);
			for (auto i : ops) {
				int &op = i.X;
				VI &v = i.Y;
				if (op == 0) {
					if (v[0] == x && v[1] == y) {
						x = v[2]; y = v[3];
					}
					else if (v[2] == x && v[3] == y) {
						x = v[0]; y = v[1];
					}
				}
				if (op == 1) {
					int c = 0;
					for (auto j : v) if (j <= x) c++;
					x += c;
				}
				if (op == 2) {
					int c = 0;
					for (auto j : v) if (j <= y) c++;
					y += c;
				}
				if (op == 3) {
					int c = 0;
					for (auto j : v) {
						if (j < x) c++;
						if (j == x) x = -1;
					}
					x -= c;
				}
				if (op == 4) {
					int c = 0;
					for (auto j : v) {
						if (j < y) c++;
						if (j == y) y = -1;
					}
					y -= c;
				}
				if (x < 0 || y < 0) break;
			}
			if (x < 0 || y < 0) puts("GONE");
			else printf("moved to (%d,%d)\n", x, y);
		}
	}

	return 0;
}
