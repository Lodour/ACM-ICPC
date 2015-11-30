#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
#define lson (rt<<1)
#define rson (rt<<1|1)
const int N = 1 << 12;
char str[N];
int tree[N], num0[N], num1[N];
const char ans[] = "BIF";
// B-0 I-1 F-2
int get(int l, int r) {
	int n0 = max(0, num0[r] - num0[l]);
	int n1 = max(0, num1[r] - num1[l]);
	if (n0 && !n1) return 0;
	if (!n0 && n1) return 1;
	return 2;
}

void build(int l, int r, int rt) {
	tree[rt] = get(l, r);
	if (l + 1 == r) return;
	int mid = (l + r) >> 1;
	build(l, mid, lson);
	build(mid, r, rson);
}

void out(int l, int r, int rt) {
	if (l + 1 == r) return;
	int mid = (l + r) >> 1;
	out(l, mid, lson);
	out(mid, r, rson);
	putchar(ans[tree[rt]]);
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n;
	scanf("%d\n", &n);
	gets(str);
	num0[1] = str[0] == '0';
	num1[1] = str[0] == '1';
	for (int i = 2; i <= 1 << n; i++) {
		num0[i] = num0[i - 1] + (str[i - 1] == '0');
		num1[i] = num1[i - 1] + (str[i - 1] == '1');
	}
	build(0, 1 << n, 1);
	out(0, 1 << (n + 1), 1);
	puts("");

	return 0;
}
