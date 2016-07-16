#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

bool check(char s[], int t, int len) {
	for (int i = 0; i < t; i++)
		for (int j = i; j < len; j += t)
			if (s[i] != s[j]) return 0;
	return 1;
}

int solve(char s[]) {
	int len = strlen(s);
	for (int t = 1;; t++)
		if (len % t == 0 && check(s, t, len))
			return t;
	return -1;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t, cnt = 0;
	char s[88];
	scanf("%d", &t);
	for (int T = 0; T < t; T++) {
		if (T) puts("");
		scanf("%s", s);
		printf("%d\n", solve(s));
	}
	return 0;
}
