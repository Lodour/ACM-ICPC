#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))
#define inf 0x3f3f3f3f
const int N = 111;


int a[N], dp[N][N];
int solve(int l, int r) {
	if (dp[l][r] != -inf) return dp[l][r];
	if (l + 1 == r) return a[l];
	return dp[l][r] = max(solve(l + 1, r), solve(l, r - 1));
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	while (~scanf("%d", &n) && n) {
		int sum = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", a + i);
			sum += a[i];
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				dp[i][j] = -inf;
		printf("%d\n", abs(sum - solve(0, n)));
	}

	return 0;
}