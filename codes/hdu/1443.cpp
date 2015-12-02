#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n, res[14] = {0};
	while (~scanf("%d", &n) && n) {
		if (!res[n]) {
			int ans, flag;
			for (ans = n + 1;; ans++) {	
				int cnt = n * 2;
				flag = 0;
				for (int i = ans;; i += ans - 1) {	// KEY: i += ans - 1;
					i = i % cnt ? i % cnt : cnt;
					if (i <= n) break;
					else cnt--;
					if (cnt == n) {
						flag =  1;
						break;
					}
				}
				if (flag) {
					res[n] = ans;
					break;
				}
			}
		}
		printf("%d\n", res[n]);
	}

	return 0;
}
