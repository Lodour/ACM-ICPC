#include <iostream>
#include <cstdio>
using namespace std;
//************************************************

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int a, b;
	while (~scanf("%d%d", &a, &b))
		if ((a & 1) | (b & 1)) puts("77");
		else puts("CC");

	return 0;
}
