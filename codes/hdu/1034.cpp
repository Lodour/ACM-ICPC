#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define mo(a,b) (((a)%(b)+(b))%b)
int a[111111];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n;
	while (~scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++)
			scanf("%d", a + i);
		int ans = 0;
		bool out = 0;
		while (!out) {
			ans++;
			int tmp = a[n - 1];
			for (int i = n - 1; i > 0; i--)
				a[i] = a[i] / 2 + a[mo(i - 1, n)] / 2;
			a[0] = a[0] / 2 + tmp / 2;

			for (int i = 0; i < n; i++)
				if (a[i] & 1) a[i]++;

			out = 1;
			for (int i = 1; i < n; i++)
				if (a[i] != a[0])
					out = 0;
		}
		printf("%d %d\n", ans, a[0]);
	}

	return 0;
}
