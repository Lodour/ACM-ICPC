#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif
	int n, m;
	while (~scanf("%d%d", &n, &m) && n && m) {
		puts((n % 2 && m % 2) ? "Wonderful!" : "What a pity!");
	}
	return 0;
}
