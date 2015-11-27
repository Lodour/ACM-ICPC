#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int id[2222];
int a[1001000];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n, k, t;
	while (~scanf("%d", &n)) {
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			id[a[i]] = i;
		}
		scanf("%d", &k); k <<= 1;
		int cnt = 0, ans;
		int mid1 = (n >> 1) - 1, mid2 = n >> 1;
		nth_element(a, a + mid1, a + n); mid1 = a[mid1];
		nth_element(a, a + mid2, a + n); mid2 = a[mid2];
		if (n & 1) mid1 = mid2;
		for (int i = 0; i < n; i++) {
			cnt += abs(a[i] - mid1) <= k || abs(a[i] - mid2) <= k;
			if (a[i] == mid1 || a[i] == mid2)
				ans = id[a[i]];
		}
		if (cnt == 1) printf("YES\n%d\n", ans + 1);
		else printf("NO\n%d\n", cnt);
	}
	return 0;
}
