#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif
	int n;
	while (~scanf("%d", &n)) {
		puts(n % 3 == 0 ? "Cici" : "Kiki");
	}
	return 0;
}
