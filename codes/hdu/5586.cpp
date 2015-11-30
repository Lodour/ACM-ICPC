#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
/*
 * 传入序列a和长度n，返回最大子序列和
 * 限制最短长度：用cnt记录长度，rt更新时判断
 */
int MaxSeqSum(int a[], int n) {
	int rt = 0, cur = 0;
	for (int i = 0; i < n; i++) {
		cur += a[i];
		if (cur > rt) rt = cur;
		if (cur < 0) cur = 0;
	}
	return rt;
}

int a[100000];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int s, x, ans, cur, n;
	while (~scanf("%d", &n)) {
		ans = cur = s = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			s += a[i];
			a[i] = (1890 * a[i] + 143) % 10007 - a[i];
		}
		printf("%d\n", s + MaxSeqSum(a, n));
	}

	return 0;
}