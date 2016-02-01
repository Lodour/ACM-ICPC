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

char text[1010];

int read(int len) {
	char c;
	int rt = 0;
	while (len && (c = getchar()) != EOF) {
		while (c == '\n') c = getchar();
		len--;
		rt = rt * 2 + (c - '0');
	}
	return rt;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	while (gets(text) != NULL) {
		int len = read(3);
		while (len) {
			// printf("LEN: %d\n", len);
			int cur;
			while (1) {
				cur = read(len);
				// printf(" CUR: %d\n", cur);
				if (cur == (1 << len) - 1) {
					// printf(" BREAK!\n");
					break;
				}
				int pos = (1 << len) - len - 1 + cur;
				putchar(text[pos]);
			}
			len = read(3);
		}
		puts("");
		getchar();
	}

	return 0;
}
