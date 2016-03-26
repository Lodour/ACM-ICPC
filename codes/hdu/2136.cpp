#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 1000010;
int vis[N], tot;

void init() {
	vis[1] = 0;
	for (int i = 2; i < N; i++)
		if (!vis[i]) {
			vis[i] = ++tot;
			for (int j = i; j < N; j += i)
				vis[j] = vis[i];
		}
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	init();
	int n;
	while (~scanf("%d", &n))
		printf("%d\n", vis[n]);

	return 0;
}
