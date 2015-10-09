#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
//************************************************

const int maxn = 110;
const int inf = 0x3f3f3f3f;
int dp[maxn][maxn << 1];

struct Stage {
	int a, b, c;
	bool operator < (const Stage& x) const {
		return b < x.b;
	}
} stage[maxn];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m, e;
		scanf("%d%d%d", &n, &m, &e);
		for (int i = 0; i < n; i++)
			scanf("%d%d%d", &stage[i].a, &stage[i].b, &stage[i].c);
		sort(stage, stage + n);
		for (int i = 0; i <= e; i++)
			dp[i][0] = 0;
		for (int i = 0; i < maxn; i++)
			for (int j = 1; j < maxn << 1; j++)
				dp[i][j] = -inf;
		for (int i = 0; i < n; i++) {
			Stage &st = stage[i];
			for (int j = st.a; j <= e; j++)
				for (int k = st.b; k < st.b + m; k++)
					dp[j][k] = max(dp[j][k], dp[j - st.a][k - st.b] + st.c);
		}
		int ans = 0;
		for (int i = m; i <= maxn << 1; i++)
			ans = max(ans, dp[e][i]);
		if (ans) printf("%d\n", ans);
		else puts("Sad Yaoge!");
	}

	return 0;
}
