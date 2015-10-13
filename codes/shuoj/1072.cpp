#include <iostream>
#include <cstdio>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	while (scanf("%d", &n) && n)
		printf("%d\n", n / 2);

	return 0;
}
