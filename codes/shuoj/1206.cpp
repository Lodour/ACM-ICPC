#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

struct Node {
	int d, m, y;
};

bool cmp(Node a, Node b) {
	if (a.y != b.y) return a.y < b.y;
	if (a.m != b.m) return a.m < b.m;
	return a.d < b.d;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	Node a[100];
	int n = 0;
	while (~scanf("%d/%d/%d", &a[n].m, &a[n].d, &a[n].y))
		n++;
	sort(a, a + n, cmp);
	for (int i = 0; i < n; i++)
		printf("%d%d/%d%d/%d\n", a[i].m / 10, a[i].m % 10, a[i].d / 10, a[i].d % 10, a[i].y);

}
