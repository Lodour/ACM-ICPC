#include <bits/stdc++.h>
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	fastin
	int t;
	cin >> t;
	while (t--) {
		int n, m, res = 0;
		cin >> n >> m;
		string s[1111];
		for (int i = 0; i < n; i++)
			cin >> s[i];
		for (int i = 0; i < m; i++) {
			int a, t, c, g;
			a = t = c = g = 0;
			for (int j = 0; j < n; j++) {
				if (s[j][i] == 'A') a++;
				if (s[j][i] == 'T') t++;
				if (s[j][i] == 'C') c++;
				if (s[j][i] == 'G') g++;
			}
			int ma = max(a, max(t, max(c, g)));
			if (ma == a) putchar('A');
			else if (ma == c) putchar('C');
			else if (ma == g) putchar('G');
			else if (ma == t) putchar('T');
			res += a + t + c + g - ma;
		}
		printf("\n%d\n", res);
	}


	return 0;
}
