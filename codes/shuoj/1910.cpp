#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	while (cin >> n) {
		int ans = 0;
		if (n >= 1) ans += 1 * n;
		if (n >= 2) ans += 4 * n * (n - 1) / 2;
		if (n >= 3) ans += 6 * n * (n - 1) * (n - 2) / 6;
		if (n >= 4) ans += 3 * n * (n - 1) * (n - 2) * (n - 3) / 24;
		cout << ans << endl;
	}
	return 0;
}
