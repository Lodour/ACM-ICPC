#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))
#define eps 1e-3
const int N = 50050;
int w[N], m[N];
double f[N];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif
	int n, k; double ans;
	scanf("%d%d%lf", &n, &k, &ans);
	for (int i = 0; i < n; i++)
		scanf("%d%d", &m[i], &w[i]);
	double l = 0.0, r = 10000.0, mid;
	while (r - l > eps) {
		mid = (l + r) / 2.0;
		for (int i = 0; i < n; i++)
			f[i] = m[i] - mid * w[i];
		sort(f, f + n);
		double sum = 0;
		for (int i = n - k; i < n; i++) sum += f[i];
		if (sum >= 0) l = mid;
		else r = mid;
	}
	if (mid + eps >= ans) printf("%.2lf\n", mid);
	else puts("Hit Yaoge");

	return 0;
}
