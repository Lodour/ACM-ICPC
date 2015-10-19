#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n, s;
	scanf("%d", &n);
	s = n * n - n - 1;
	printf("%d*%d*%d=%d=", n, n, n, n * n * n);
	for (int i = 0; i < n; i++)
		printf("%d%c", s += 2, i == n - 1 ? '\n' : '+');
	return 0;
}
