#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

const int maxn = 10010;
double a[maxn];
double eps = 1e-5;

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	int n, k;
	while (~scanf("%d%d", &n, &k)) {
		double maxl = 0.0;
		for (int i = 0; i < n; i++) {
			scanf("%lf", &a[i]);
			maxl = max(maxl, a[i]);
		}
		double l = 0, r = maxl;
		while (r - l > eps) {
			// cout<<r<<" "<<l<<endl;
			double mid = (r + l) / 2;
			int sum = 0;
			for (int i = 0; i < n; i++)
				sum += a[i] / mid;
			if (sum >= k)l = mid;
			else r = mid;
		}
		printf("%.2lf\n", int(r * 100) * 0.01);
	}

	return 0;
}