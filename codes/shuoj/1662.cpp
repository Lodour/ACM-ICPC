#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <queue>
#include <algorithm>
using namespace std;

int s[110], e[110], t[110];

bool cmp(int a, int b) {
	return (e[a] < e[b]) || (e[a] == e[b] && s[a] < s[b]);
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	while (~scanf("%d", &n) && n) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &s[i], &e[i]);
			t[i] = i;
		}
		sort(t, t + n, cmp);
		int ans = 1;
		int r = e[t[0]];
		for (int i = 1; i < n; i++)
			if (r <= s[t[i]]) {
				ans++;
				r = e[t[i]];
			}
		printf("%d\n", ans);
	}
	return 0;
}
