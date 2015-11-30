#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define mp make_pair
#define X first
#define Y second
typedef pair<int, int> PII;
PII v[110];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n, m, x, y;
	scanf("%d%d", &n, &m);
	int ans = n + 1;
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &x, &y);
		v[i] = mp(x, y);
	}
	sort(v, v + m);
	PII cur = v[0];
	for (int i = 1; i < m; i++) {
		if (v[i].X <= cur.Y + 1)
			cur.Y = max(cur.Y, v[i].Y);
		else {
			ans -= cur.Y - cur.X + 1;
			cur = v[i];
		}
	}
	ans -= cur.Y - cur.X + 1;
	printf("%d\n", ans);
	return 0;
}
