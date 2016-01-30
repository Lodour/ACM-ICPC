#include <bits/stdc++.h>
using namespace std;
#define lson rt<<1
#define rson rt<<1|1
#define Lson l,m,lson
#define Rson m+1,r,rson
#define set(a,b) memset(a,b,sizeof(a))
#define N 100010
int seg[N << 2], ma[N << 2];

void PushUp(int rt) {
	ma[rt] = max(ma[lson], ma[rson]);
}
void PushDown(int rt) {
	if (seg[rt] == 0) return;
	seg[lson] += seg[rt];
	seg[rson] += seg[rt];
	ma[lson] += seg[rt];
	ma[rson] += seg[rt];
	seg[rt] = 0;
}
void build(int l, int r, int rt) {
	seg[rt] = 0;
	if (l == r) {
		ma[rt] = 0;
		return;
	}
	int m = (l + r) >> 1;
	build(Lson); build(Rson);
	PushUp(rt);
}
void update(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) {
		seg[rt]++;
		ma[rt]++;
		return;
	}
	PushDown(rt);
	int m = (l + r) >> 1;
	if (L <= m) update(L, R, Lson);
	if (m < R) update(L, R, Rson);
	PushUp(rt);
}
int query(int L, int R, int l, int r, int rt) {
	if (L <= l && r <= R) return ma[rt];
	PushDown(rt);
	int m = (l + r) >> 1, ret = 0;
	if (L <= m) ret = max(ret, query(L, R, Lson));
	if (m < R) ret = max(ret, query(L, R, Rson));
	return ret;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int n, m, k;
	scanf("%d%d%d", &n, &m, &k);
	build(1, n, 1);
	while (m--) {
		int l, r;
		scanf("%d%d", &l, &r);
		if (query(l, r, 1, n, 1) < k) {
			puts("Yes");
			update(l, r - 1, 1, n, 1);
		}
		else {
			puts("No");
		}
	}


	return 0;
}

