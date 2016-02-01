#include <bits/stdc++.h>
using namespace std;
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
#define set(a,b) memset(a,b,sizeof(a))

const int N = 55;
const int M = 1010;

char str[N][M];
int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 0; i < n; i++)
			scanf("%s", str[i]);
		int ans = 0;
		for (int i = 0; i < m; i++) {
			int a, t, g, c;
			a = t = g = c = 0;
			for (int j = 0; j < n; j++) {
				if (str[j][i] == 'A') a++;
				if (str[j][i] == 'T') t++;
				if (str[j][i] == 'G') g++;
				if (str[j][i] == 'C') c++;
			}
			int ma = max(a, max(t, max(g, c)));
			if (ma == a) putchar('A');
			else if (ma == c) putchar('C');
			else if (ma == g) putchar('G');
			else if (ma == t) putchar('T');
			ans += a + t + g + c - ma;
		}
		printf("\n%d\n", ans);
	}

	return 0;
}
