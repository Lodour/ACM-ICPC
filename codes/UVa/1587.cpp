#include <bits/stdc++.h>
using namespace std;
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
#define set(a,b) memset(a,b,sizeof(a))
typedef pair<int, int> PII;
#define X first
#define Y second

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	fastin;
	vector<PII> v(6);
	while (cin >> v[0].X >> v[0].Y) {
		for (int i = 1; i < 6; i++)
			cin >> v[i].X >> v[i].Y;
		for (int i = 0; i < 6; i++)
			if (v[i].X > v[i].Y)
				swap(v[i].X, v[i].Y);
		sort(v.begin(), v.end());
		bool ans = 1;
		for (int i = 0; i < 6; i += 2)
			if (v[i] != v[i + 1])
				ans = 0;
		if (v[0].X != v[2].X) ans = 0;
		if (v[0].Y != v[4].X) ans = 0;
		if (v[3].Y != v[4].Y) ans = 0;
		cout << (ans ? "POSSIBLE" : "IMPOSSIBLE") << endl;
	}

	return 0;
}
