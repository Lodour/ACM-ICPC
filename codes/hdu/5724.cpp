#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

const int N = 1 << 20;
int sg[N << 1], vis[100];
void calsg() {
	for (int i = 1; i < N; i++) {
		memset(vis, 0, sizeof(vis));
		int pre = -1;
		for (int j = 0; j < 20; j++) {
			if (i & (1 << j)) {
				if (pre != -1) {
					vis[sg[(i ^ (1 << j)) | (1 << pre)]] = 1;
				}
			}
			else {
				pre = j;
			}
		}
		for (int j = 0;; j++)
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
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		int ans = 0;
		while (n--) {
			int m;
			scanf("%d", &m);
			int y = 0;
			while (m--) {
				int x;
				scanf("%d", &x);
				y |= 1 << (20 - x);
			}
			ans ^= sg[y];
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}
