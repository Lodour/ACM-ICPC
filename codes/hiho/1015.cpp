#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
const int N = 1001000;
char s1[N], s2[N];

// 返回y中x的个数
int ne[N];
void initkmp(char x[], int m, int ne[]) {
	int i, j; j = ne[0] = -1; i = 0;
	while (i < m) {
		while (j != -1 && x[i] != x[j])
			j = ne[j];
		ne[++i] = ++j;
	}
}
int kmp(char x[], int m, char y[], int n) {
	int i, j, ans; i = j = ans = 0;
	initkmp (x, m, ne);
	while (i < n) {
		while (j != -1 && y[i] != x[j]) j = ne[j];
		i++; j++;
		if (j >= m) {
			ans++; j = ne[j];
		}
	}
	return ans;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s%s", s1, s2);
		printf("%d\n", kmp(s1, strlen(s1), s2, strlen(s2)));
	}

	return 0;
}
