#include <iostream>
#include <cstdio>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	const int mod[] = {10, 100, 1000};
	const int ans[] = {1, 18, 188};
	while (t--) {
		int n;
		scanf("%d", &n);
		while (n) {
			int nn = n;
			for (int i = 0; i < 3; i++)
				if (n % mod[i] == ans[i])
					n /= mod[i];
			if (nn == n) break;
		}
		puts(n ? "NO" : "YES");
	}

	return 0;
}
