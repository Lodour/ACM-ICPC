#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

const int N = 1 << 15;
int p[N];

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	int n, m, cnt = 0;
	while (cin >> n >> m) {
		int ans = n, tot = 0;
		int sq = sqrt(m);
		for (int i = 2; i <= m; i++)
			if (m % i == 0)
				p[tot++] = i;
		for (int i = 1; i <= n; i++)
			for (int j = 0; j < tot; j++)
				if (i % p[j] == 0) {
					ans--;
					break;
				}
		printf("Case %d: %d\n", ++cnt, ans);
	}

	return 0;
}
