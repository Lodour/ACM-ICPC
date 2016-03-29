#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))

const int N = 999999 + 100;
int a[N];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	// int n;
	// while (~scanf("%d", &n)) {
	// 	for (int i = 0; i < n; i++)
	// 		scanf("%d", a + i);
	// 	sort(a, a + n);
	// 	printf("%d\n", a[n >> 1]);
	// }

	int n;
	while (~scanf("%d", &n)) {
		int a, b, ca;
		scanf("%d", &a);
		ca = 1; n--;
		while (n--) {
			scanf("%d", &b);
			ca = a == b ? ca + 1 : ca - 1;
			if (ca == 0) {
				a = b;
				ca = 1;
			}
		}
		printf("%d\n", a);
	}

	return 0;
}
