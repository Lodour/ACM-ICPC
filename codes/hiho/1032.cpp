#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;


const int N = 1000100;
char s[N], str[N << 1];
int p[N << 1];
void Manacher(char s[], int &n) {
	str[0] = '$';
	str[1] = '#';
	for (int i = 0; i < n; i++) {
		str[(i << 1) + 2] = s[i];
		str[(i << 1) + 3] = '#';
	}
	n = 2 * n + 2;
	str[n] = 0;
	int mx = 0, id;
	for (int i = 1; i < n; i++) {
		p[i] = mx > i ? min(p[2 * id - i], mx - i) : 1;
		for (; str[i - p[i]] == str[i + p[i]]; p[i]++);
		if (p[i] + i > mx) {
			mx = p[i] + i;
			id = i;
		}
	}
}
int solve(char s[]) {
	int n = strlen(s);
	Manacher(s, n);
	int res = 0;
	for (int i = 0; i < n; i++)
		res = max(res, p[i]);
	return res - 1;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%s", s);
		printf("%d\n", solve(s));
	}

	return 0;
}
