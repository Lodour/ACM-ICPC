#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define CLR(a,b); memset(a,b,sizeof(a));

int n, k;
char mp[4][111];
bool dp[4][111];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &k);
		CLR(dp, 0);
		for (int i = 1; i <= 3; i++) {
			scanf("%s", mp[i]);
			for (int j = 0; j < n; j++)
				if (mp[i][j] == 's')
					dp[i][j] = 1;
			for (int j = n; j < n + 4; j++)
				mp[i][j] = '.';
		}
		for (int j = 0; j < n; j++)
			for (int i = 1; i <= 3; i++) {
				if (!dp[i][j]) continue;
				// up
				if (i > 1 && mp[i][j + 1] == '.' && mp[i - 1][j + 1] == '.' && mp[i - 1][j + 2] == '.' && mp[i - 1][j + 3] == '.')
					dp[i - 1][j + 3] = 1;
				// pause
				if (mp[i][j + 1] == '.' && mp[i][j + 2] == '.' && mp[i][j + 3] == '.')
					dp[i][j + 3] = 1;
				// down
				if (i < 3 && mp[i][j + 1] == '.' && mp[i + 1][j + 1] == '.' && mp[i + 1][j + 2] == '.' && mp[i + 1][j + 3] == '.')
					dp[i + 1][j + 3] = 1;
			}
		bool ans = 0;
		for (int i = 1; !ans && i <= 3; i++)
			for (int j = n; !ans && j <= n + 3; j++)
				ans |= dp[i][j];
		puts(ans ? "YES" : "NO");

	}

	return 0;
}
