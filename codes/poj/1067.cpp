#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif
	int a, b;
	while (~scanf("%d%d", &a, &b)) {
		if (a > b) swap(a, b);
		int k = b - a;
		int a_k = floor(k * (sqrt(5.0) + 1.0) * 0.5);
		puts(a_k == a ? "0" : "1");
	}
	return 0;
}
