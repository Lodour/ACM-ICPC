#include <iostream>
#include <cstdio>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t, cnt = 0;
	scanf("%d", &t);
	while (t--) {
		int n, cur;
		int anss, ansl, ansr, s, l;
		anss = -1111;
		s = 0;
		ansl = ansr = l = 1;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &cur);
			s += cur;
			if (anss < s) {
				anss = s;
				ansl = l;
				ansr = i;
			}
			if (s < 0) {
				s = 0;
				l = i + 1;
			}
		}
		if (cnt++) puts("");
		printf("Case %d:\n", cnt);
		printf("%d %d %d\n", anss, ansl, ansr);
	}
	return 0;
}
