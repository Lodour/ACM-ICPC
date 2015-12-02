#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

int f[1111] = {0, 1};

int dfs(int n) {
	if (f[n]) return f[n];
	for (int i = 1; i <= n / 2; i++)
		f[n] += dfs(i);
	return ++f[n];
}

int main() {
	int n;
	scanf("%d", &n);
	printf("%d\n", dfs(n));

	return 0;
}
