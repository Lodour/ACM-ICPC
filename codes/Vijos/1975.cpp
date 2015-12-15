#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))

bool mp[110][110];
int a[110][110];
const int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1};
const int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1};

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		getchar();
		for (int j = 1; j <= m; j++) {
			if (getchar() == '*') {
				mp[i][j] = 1;
				for (int k = 0; k < 8; k++)
					a[i + dx[k]][j + dy[k]]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			if (mp[i][j]) putchar('*');
			else printf("%d", a[i][j]);
		puts("");
	}

	return 0;
}
