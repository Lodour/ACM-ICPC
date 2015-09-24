#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
using namespace std;

int a[1010];

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	int r, n, x;
	while (scanf("%d%d", &r, &n) && r != -1) {
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		sort(a, a + n);
		int i = 0, ans = 0;
		while (i < n) {
			// 找到最左侧的点s
			int s = a[i++];
			// 一直走到第一个距离s大于r的点
			while (i < n && a[i] <= s + r) i++;
			// p是需要标记的点
			int p = a[i - 1];
			// 一直走到第一个距离p大于r的点
			while (i < n && a[i] <= p + r) i++;
			// 标记点数加1
			ans++;
		}
		cout << ans << endl;
	}

	return 0;
}