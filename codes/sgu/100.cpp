#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int a, b;
	scanf("%d%d", &a, &b);
	printf("%d\n", a + b);

	return 0;
}
