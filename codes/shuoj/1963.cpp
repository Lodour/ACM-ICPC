#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<int, int> PII;
#define pb push_back
#define mp make_pair
#define X first
#define Y second
#define lowbit(i) (i&(-i))
const int MAXN = 100100;
int a[MAXN], bit[MAXN], ans[MAXN];
int l[MAXN], r[MAXN], k[MAXN];
int n;

void add(int i, int x) {
	while (i <= n) {
		bit[i] += x;
		i += lowbit(i);
	}
}
int query(int i) {
	int s = 0;
	while (i) {
		s += bit[i];
		i -= lowbit(i);
	}
	return s;
}

vector<PII> b, Q;

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int t, q;
	scanf("%d", &t);
	while (t--) {
		scanf("%d%d", &n, &q);
		// 离散化
		b.clear();
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			b.pb(mp(a[i], i + 1));
		}
		sort(b.begin(), b.end());
		// 离线
		Q.clear();
		for (int i = 0; i < q; i++) {
			scanf("%d%d%d", &l[i], &r[i], &k[i]);
			Q.pb(mp(k[i], i));
		}
		sort(Q.begin(), Q.end());

		int j = 0;
		memset(bit, 0, sizeof(bit));
		for (int i = 0; i < q; i++) {
			while (j < n && b[j].X < Q[i].X)
				add(b[j++].Y, 1);
			ans[Q[i].Y] = query(r[Q[i].Y]) - query(l[Q[i].Y] - 1);
		}

		for (int i = 0; i < q; i++)
			printf("%d\n", ans[i]);
	}

	return 0;
}