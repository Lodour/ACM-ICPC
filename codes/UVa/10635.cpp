#include <cstdio>
#include <cstring>
#include <vector>
using namespace std;
#define pb push_back
typedef vector<int> VI;
// nlogn求出序列a和b的最长公共子串
// nlogn ~ mnlog(mn)

// 最大序列长度
const int N = 250 * 250 + 1000;
// 序列a长度p 序列b长度q 最终序列c长度tot dp序列 序列中最大数字
int a[N], b[N], c[N], dp[N], p, q, tot, maxn;
// 序列a中元素在b中出现的下标
VI pos[N];

void init() {
	for (int i = 0; i < maxn; i++)
		pos[i].clear();
	tot = 0;
}

void input() {
	scanf("%d %d %d", &maxn, &p, &q);
	maxn *= maxn;
	p++; q++;
	init();
	for (int i = 0; i < p; i++)
		scanf("%d", a + i);
	for (int i = 0; i < q; i++) {
		scanf("%d", b + i);
		pos[b[i]].pb(i);
	}
}

int LIS(int a[], int n) {
	int k = 0;
	dp[0] = a[0];
	for (int i = 1; i < n; i++)
		if (a[i] > dp[k]) dp[++k] = a[i];
		else {
			int l = 0, r = k, mid;
			while (l <= r) {
				mid = l + r >> 1;
				if (dp[mid] < a[i]) l = mid + 1;
				else r = mid - 1;
			}
			dp[l] = a[i];
		}
	return k + 1;
}

int LCS() {
	for (int i = 0; i < p; i++)
		for (int j = 0; j < (int)pos[a[i]].size(); j++)
			c[tot++] = pos[a[i]][j];
	return LIS(c, tot);
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	char cc = '\144';
	printf("%c", cc);

	int t, cnt = 0;
	scanf("%d", &t);
	while (t--) {
		input();
		printf("Case %d: %d\n", ++cnt, LCS());
	}

	return 0;
}