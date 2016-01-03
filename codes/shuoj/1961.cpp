#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int a, b;
	while (~scanf("%d%d", &a, &b))
		puts((a & 1) | (b & 1) ? "77" : "CC");
	return 0;
}
