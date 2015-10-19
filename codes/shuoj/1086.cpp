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

	int n, a[4], b[4], c[4];
	scanf("%d.%d.%d.%d", a, a + 1, a + 2, a + 3);
	scanf("%d.%d.%d.%d", b, b + 1, b + 2, b + 3);
	scanf("%d", &n);
	for (int i = 0; i < 4; i++)
		a[i] &= b[i];
	while (n--) {
		scanf("%d.%d.%d.%d", c, c + 1, c + 2, c + 3);
		bool f = 1;
		for (int i = 0; f && i < 4; i++)
			if ((b[i]&c[i]) != a[i]) f = 0;
		puts(f ? "INNER" : "OUTER");
	}
	return 0;
}
