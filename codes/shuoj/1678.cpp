#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int a, b, k, s[222];
	while (~scanf("%d%d%d", &a, &b, &k)) {
		for (int i = 0; i < a + b; i++)
			scanf("%d", &s[i]);
		sort(s, s + a + b);
		printf("%d\n", s[k - 1]);
	}

	return 0;
}