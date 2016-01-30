#include <bits/stdc++.h>
using namespace std;
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
#define set(a,b) memset(a,b,sizeof(a))
#define pb push_back
#define mp make_pair
#define X first
#define Y second
typedef vector<pair<int, string> > VP;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	fastin;
	int n, m, cnt = 0;
	bool fi = 1;
	string s[15];
	int num[15][15];
	while (cin >> n && n && cin >> m) {
		set(num, 0);
		int tot = 0;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			s[i] += "*";
			for (int j = 0; j < m; j++) {
				if (s[i][j] == '*') continue;
				if (i == 0 || j == 0 || s[i - 1][j] == '*' || s[i][j - 1] == '*')
					num[i][j] = ++tot;
			}
		}
		for (int j = 0; j <= m; j++)
			s[n][j] = '*';
		string t;
		VP va, vd;
		// Across
		t.clear();
		for (int i = 0; i < n; i++)
			for (int j = 0; j <= m; j++) {
				if (s[i][j] == '*') {
					if (t.size())
						va.pb(mp(num[i][j - t.size()], t)), t.clear();
				}
				else t += s[i][j];
			}
		// Down
		t.clear();
		for (int j = 0; j < m; j++)
			for (int i = 0; i <= n; i++) {
				if (s[i][j] == '*') {
					if (t.size())
						vd.pb(mp(num[i - t.size()][j], t)), t.clear();
				}
				else t += s[i][j];
			}
		sort(va.begin(), va.end());
		sort(vd.begin(), vd.end());
		if (!fi) puts("");
		fi = 0;
		printf("puzzle #%d:\n", ++cnt);
		puts("Across");
		for (int i = 0; i < (int)va.size(); i++)
			printf("% 3d.%s\n", va[i].X, &va[i].Y[0]);
		puts("Down");
		for (int i = 0; i < (int)vd.size(); i++)
			printf("% 3d.%s\n", vd[i].X, &vd[i].Y[0]);
	}
	return 0;
}
