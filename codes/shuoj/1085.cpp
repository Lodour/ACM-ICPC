#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<double, double> PDD;
#define mp make_pair
#define pb push_back
#define X first
#define Y second

PDD a[110], b[110];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n, m;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%lf%lf", &a[i].X, &a[i].Y);
	scanf("%d", &m);
	for (int i = 0; i < m; i++)
		scanf("%lf%lf", &b[i].X, &b[i].Y);
	sort(a, a + n);
	sort(b, b + m);
	double ans = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (a[i].X <= b[j].X && a[i].Y >= b[j].X && a[i].Y <= b[j].Y)
				ans += a[i].Y - b[j].X;
			else if (a[i].X >= b[j].X && a[i].X <= b[j].Y && a[i].Y >= b[j].Y)
				ans += b[j].Y - a[i].X;
			else if (a[i].X >= b[j].X && a[i].Y <= b[j].Y)
				ans += a[i].Y - a[i].X;
			else if (a[i].X <= b[j].X && a[i].Y >= b[j].Y)
				ans += b[j].Y - b[j].X;
	printf("%.3lf\n", ans);

	return 0;
}
