#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int fib[100] = {0, 1};

void init() {
	for (int i = 2; i < 47; i++)
		fib[i] = fib[i - 1] + fib[i - 2];
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	init();
	int n;
	while (~scanf("%d", &n) && n != -1) {
		int i;
		for (i = 0; i < 47; i++)
			if (fib[i] == n)break;
		if (i < 47) cout << i << endl;
		else cout << "Not a Fibonacci number." << endl;
	}

	return 0;
}