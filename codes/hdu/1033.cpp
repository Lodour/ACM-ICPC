#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

char s[222];

int dx[4] = {10, 0, -10, 0};
int dy[4] = {0, 10, 0, -10};

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif

	while (gets(s) != NULL) {
		int dir = 0;
		int x = 310, y = 420;
		puts("300 420 moveto");
		puts("310 420 lineto");
		for (int i = 0; s[i]; i++) {
			bool right = s[i] == 'A';
			dir = right ? dir + 3 : dir + 1;
			dir %= 4;
			x += dx[dir];
			y += dy[dir];
			printf("%d %d lineto\n", x, y);
		}
		puts("stroke");
		puts("showpage");
	}

	return 0;
}
