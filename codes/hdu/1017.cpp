#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;



int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m, cnt = 0;
		while (~scanf("%d%d", &n, &m) && !(n == 0 && m == 0)) {
			int ans = 0;
			for (int a = 1; a < n; a++)
				for (int b = a + 1; b < n; b++)
					if ((a * a + b * b + m) % (a * b) == 0)
						ans++;
			printf("Case %d: %d\n", ++cnt, ans);
		}
		if (t) puts("");
	}

	return 0;
}
