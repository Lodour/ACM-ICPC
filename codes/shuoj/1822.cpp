#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	int n, cnt = 0;
	while (~scanf("%d", &n)) {
		int ans = 0;
		for (int i = 5; i <= n; i *= 5)
			ans += n / i;
		printf("Case %d:%d,%d\n", ++cnt, n, ans);
	}

	return 0;
}
