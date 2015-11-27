#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;

struct Node {
	double x, y, z;
	Node(double x = 0, double y = 0, double z = 0): x(x), y(y), z(z) {}
	Node operator / (int d) {return Node(x / d, y / d, z / d);}
	Node operator + (Node& d) {return Node(x + d.x, y + d.y, z + d.z);}
	double len(Node a) {
		return sqrt((x - a.x) * (x - a.x) + (y - a.y) * (y - a.y) + (z - a.z) * (z - a.z));
	}
} a[5555], p, q, mid, ans;

bool cmp(Node p, Node q) {
	return p.len(mid) < q.len(mid);
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf%lf%lf", &a[i].x, &a[i].y, &a[i].z);
	scanf("%lf%lf%lf", &p.x, &p.y, &p.z);
	scanf("%lf%lf%lf", &q.x, &q.y, &q.z);
	mid = (p + q) / 2;
	sort(a, a + n, cmp);
	printf("%.3lf %.3lf %.3lf\n", a[0].x, a[0].y, a[0].z);
	return 0;
}
