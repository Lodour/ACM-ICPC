#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

typedef long long ll;
const int mod = 1000007;
const int N = 444;
int m, n, k;
int CC[N][N];

void init() {
	for (int i = 0; i < N; i++) {
		CC[i][0] = 1;
		for (int j = 1; j <= i; j++)
			CC[i][j] = (CC[i - 1][j - 1] + CC[i - 1][j]) % mod;
	}
}

int C(int m, int n) {
	return (m >= 0 && n >= 0 && m >= n) ? CC[m][n] : 0;
}

int solve() {
	if (m * n < k) return 0;
	ll tot = C(m * n, k);
	tot = ((tot - 2 * (C((n - 1) * m, k) + C((m - 1) * n, k))) % mod + mod) % mod;
	tot = (tot + 4 * C((n - 1) * (m - 1), k) + C(n * (m - 2), k) + C((n - 2) * m, k)) % mod;
	tot = ((tot - 2 * C((n - 1) * (m - 2), k) - 2 * C((m - 1) * (n - 2), k)) % mod + mod) % mod;
	tot = (tot + C((n - 2) * (m - 2), k)) % mod;
	return tot;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	init();
	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d%d", &m, &n, &k);
		printf("%d\n", solve());
	}
	return 0;
}