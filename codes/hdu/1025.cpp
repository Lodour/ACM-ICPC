#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))
#define X first
#define Y second
typedef pair<int, int> PII;
const int N = 500000 + 100;
int n;
int a[N], b[N], dp[N];

int find(int p, int l, int r) {
	int mid;
	while (l <= r) {
		mid = l + r >> 1;
		if (a[p] > b[mid]) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}

int LIS() {
	int len = 1;
	b[1] = a[1];
	set(dp, 0);
	for (int i = 2; i <= n; i++)
		if (a[i] > b[len]) b[++len] = a[i];
		else b[find(i, 1, len)] = a[i];
	return len;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int cnt = 0;
	while (~scanf("%d", &n)) {
		int u, v;
		for (int i = 1; i <= n; i++) {
			scanf("%d%d", &u, &v);
			a[u] = v;
		}
		printf("Case %d:\n", ++cnt);
		int ans = LIS();
		if (ans == 1) puts("My king, at most 1 road can be built.");
		else printf("My king, at most %d roads can be built.\n", ans);
		puts("");
	}

	return 0;
}
