#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 500050;
int ans[N];

void init() {
	for (int i = 1; i < N; i++)
		for (int j = i; j < N; j += i)
			ans[j] += i;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	init();
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", ans[n]-n);
	}

	return 0;
}
