#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))

const int N = 1e5;
double a[N];
int id[N];

bool cmp(int i, int j) {return a[i] > a[j];}
bool cmp2(int i, int j) {return i > j;}
int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n, m, k;
	while (~scanf("%d%d%d", &n, &m, &k)) {
		double cur;
		set(a, 0);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++) {
				scanf("%lf", &cur);
				a[j] += cur;
			}
		for (int i = 0; i < m; i++)
			id[i] = i;
		sort(id, id + m, cmp);
		sort(id, id + k, cmp2);
		for (int i = 0; i < k; i++)
			printf("%d%c", id[i] + 1, i == k - 1 ? '\n' : ' ');
	}
	return 0;
}
