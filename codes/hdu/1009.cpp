#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 1111;
int n, m, F[N], J[N], id[N];
double price[N];

bool cmp(int i, int j) {return price[i] > price[j];}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	while (~scanf("%d%d", &m, &n) && m != -1 && n != -1) {
		for (int i = 0; i < n; i++) {
			scanf("%d%d", J + i, F + i);
			id[i] = i;
			price[i] = 1.0 * J[i] / F[i];
		}
		sort(id, id + n, cmp);
		double ans = 0;
		for (int i = 0; i < n; i++) {
			int p = id[i];
			if (m > F[p]) {
				m -= F[p];
				ans += J[p];
			}
			else {
				ans += m * price[p];
				break;
			}
		}
		printf("%.3lf\n", ans);
	}

	return 0;
}
