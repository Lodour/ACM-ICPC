#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

const int N = 10000 + 100;
char s[N];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		int len = strlen(s);
		s[len++] = '#';
		s[len] = 0;
		for (int i = 0; s[i]; i++) {
			int cnt = 0, p = i;
			while (i < len && s[i] == s[p]) {
				cnt++;
				i++;
			} i--;
			if (s[p] == '#') break;
			if (cnt == 1) putchar(s[p]);
			else printf("%d%c", cnt, s[p]);
		}
		puts("");
	}

	return 0;
}
