#include <bits/stdc++.h>
using namespace std;
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
#define set(a,b) memset(a,b,sizeof(a))

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int a[10] = {0};
		for (int i = 1; i <= n; i++) {
			int p = i;
			while (p) {
				a[p % 10]++;
				p /= 10;
			}
		}
		for (int i = 0; i < 10; i++)
			printf("%d%c", a[i], i == 9 ? '\n' : ' ');
	}

	return 0;
}
