#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	char a[11];
	while (~scanf("%s", a)) {
		int ans = 0;
		for (int i = 0; a[i]; i++)
			ans += a[i] - '0';
		printf("%d\n", ans);
	}
	return 0;
}
