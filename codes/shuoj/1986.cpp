#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n, m;
	while (~scanf("%d%d", &m, &n)) {
		n = min(n, m);
		bool a[1010] = {0};
		for (int i = 2; i <= n; i++)
			for (int j = i; j <= m; j += i)
				a[j] ^= 1;
		int ans = 0;
		for (int i = 1; i <= m; i++)
			ans += a[i] == 0;
		printf("%d\n", ans);
	}

	return 0;
}
