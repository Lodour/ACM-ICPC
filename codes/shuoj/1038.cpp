#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
vector<pair<int, PII> > v;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++) {
			int x;
			scanf("%d", &x);
			if (x != 0) v.pb(mp(-x, mp(i, j)));
		}
	sort(v.begin(), v.end());
	int ans = 0;
	PII pos = mp(0, v[0].Y.Y);
	for (int i = 0; i < v.size(); i++) {
		int go = abs(v[i].Y.X - pos.X) + abs(v[i].Y.Y - pos.Y);
		int out = v[i].Y.X;
		if (k >= go + 1 + out) {
			k -= go + 1;
			ans += -v[i].X;
			pos = v[i].Y;
		} else break;
	}
	printf("%d\n", ans);

	return 0;
}
