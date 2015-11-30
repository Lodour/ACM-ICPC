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

	int t, a, b;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &a, &b);
		printf("%d\n", a + b);
	}

	return 0;
}
