#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int a[4], b[4];
	for (int i = 0; i < 4; i++)
		scanf("%d", a + i);
	for (int i = 3; i >= 0; i--) {
		int p = 0;
		for (int j = 0; j < 4; j++)
			if (i != j) b[p++] = a[j];
		do {
			printf("%d %d %d\n", b[0], b[1], b[2]);
		} while (next_permutation(b, b + 3));
	}

	return 0;
}
