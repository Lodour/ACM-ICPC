#include <bits/stdc++.h>
using namespace std;
#define N 100
int n, len, a[N], b[N];
int Find(int p, int l, int r) {
	int mid;
	while (l <= r) {
		mid = (l + r) >> 1;
		if (a[p] > b[mid]) l = mid + 1;
		else r = mid - 1;
	}
	return l;
}
int LIS() {
	int len = 1;
	b[1] = a[1];
	for (int i = 2; i <= n; i++) {
		if (a[i] > b[len]) b[++len] = a[i];
		else b[Find(i, 1, len)] = a[i];
	}
	return len;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	while (cin >> n) {
		for (int i = 1; i <= n; i++)
			cin >> a[i];
		cout << LIS() << endl;
	}

	return 0;
}
