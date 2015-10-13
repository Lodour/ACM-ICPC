#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1e5 + 10;
int deq[N], a[N];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		int n, k;
		scanf("%d%d", &n, &k);
		int l = 0, r = 0;
		memset(deq, 0, sizeof(deq));
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			while (l < r && a[deq[r - 1]] >= a[i]) r--;
			deq[r++] = i;
			if (i >= k - 1) {
				printf("%d%c", a[deq[l]], i == n - 1 ? '\n' : ' ');
				if (deq[l] == i - k + 1)
					l++;
			}
		}
	}

	return 0;
}
