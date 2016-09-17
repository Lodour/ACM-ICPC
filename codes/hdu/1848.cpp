#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1011;
int f[N], sg[N], vis[N];
void calsg() {
	int tot = 1; f[0] = 1; f[1] = 2;
	while (f[tot++] < N)
		f[tot] = f[tot - 1] + f[tot - 2];
	sg[0] = 0;
	for (int i = 1; i < N; i++) {
		memset(vis, 0, sizeof(vis));
		for (int j = 0; j < tot && f[j] <= i; j++)
			vis[sg[i - f[j]]] = 1;
		for (int j = 0; j < N; j++)
			if (!vis[j]) {
				sg[i] = j;
				break;
			}
	}
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif
	calsg();
	int m, n, p;
	while (~scanf("%d%d%d", &m, &n, &p) && m && n && p) {
		puts((sg[m]^sg[n]^sg[p]) ? "Fibo" : "Nacci");
	}
	return 0;
}
