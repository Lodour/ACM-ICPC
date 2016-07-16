#include <bits/stdc++.h>
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define X first
#define Y second
#define set(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef pair<int, string> PIS;
typedef vector<PIS> VP;

int n, m;
string G[11];
int a[11][11];

void find(VP& v, int n, int m) {
	string tmp;
	for (int i = 0; i < n; i++) {
		stringstream ss(G[i].substr(0, m));
		for (int j = 0; j < m; j++)
			if (G[i][j] != ' ' && (j == 0 || G[i][j - 1] == ' ')) {
				ss >> tmp;
				v.pb(mp(a[i][j], tmp));
			}
	}
}

void trans() {
	string GG[11];
	int aa[11][11] = {0};
	for (int i = 0; i < m; i++) {
		GG[i].resize(n);
		for (int j = 0; j < n; j++) {
			GG[i][j] = G[j][i];
			aa[i][j] = a[j][i];
		}
	}
	for (int i = 0; i < m; i++) {
		G[i] = GG[i];
		for (int j = 0; j < n; j++)
			a[i][j] = aa[i][j];
	}
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	fastin
	int cnt = 0;
	while (cin >> n && n && cin >> m) {
		set(a, 0);
		if (cnt) puts("");
		int tot = 0;
		for (int i = 0; i < n; i++) {
			cin >> G[i];
			for (int j = 0; j < m; j++) {
				if (G[i][j] == '*') G[i][j] = ' ';
				else if (i == 0 || j == 0 || G[i - 1][j] == ' ' || G[i][j - 1] == ' ')
					a[i][j] = ++tot;
			}
		}

		VP va, vd;
		find(va, n, m);
		trans();
		find(vd, m, n);
		sort(va.begin(), va.end());
		sort(vd.begin(), vd.end());
		printf("puzzle #%d:\n", ++cnt);
		puts("Across");
		for (auto i : va) printf("% 3d.%s\n", i.X, i.Y.c_str());
		puts("Down");
		for (auto i : vd) printf("% 3d.%s\n", i.X, i.Y.c_str());
	}

	return 0;
}
