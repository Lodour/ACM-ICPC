#include <iostream>
#include <cstdio>
using namespace std;

const int N = 10000;
int a[N][10] = {0};

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	for (int i = 1; i < N; i++) {
		int c = i;
		while (c) {
			a[i][c % 10]++;
			c /= 10;
		}
		for (int j = 0; j < 10; j++)
			a[i][j] += a[i - 1][j];
	}
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < 10; i++)
			printf("%d%c", a[n][i], i == 9 ? '\n' : ' ');
	}
	return 0;
}
