#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int a[110][110];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif


	int n, t;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &a[i][j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			scanf("%d", &t);
			printf("%d%c", a[i][j] + t, j == n - 1 ? '\n' : ' ');
		}


	return 0;
}