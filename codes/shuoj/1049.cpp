#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int id, a, b, c, s;
	bool operator < (const Node& x) const {
		if (s != x.s) return s > x.s;
		if (a != x.a) return a > x.a;
		return id < x.id;
	}
} st[333];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		Node &t = st[i];
		scanf("%d%d%d", &t.a, &t.b, &t.c);
		t.id = i;
		t.s = t.a + t.b + t.c;
	}
	sort(st, st + n);
	for (int i = 0; i < 5; i++)
		printf("%d %d\n", st[i].id + 1, st[i].s);

	return 0;
}
