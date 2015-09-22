#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
/****************************************************************************/
#define debug(x) cout<<#x<<": "<<x<<endl;
#define debug2(x,y) cout<<#x<<": "<<x<<"\t"<<#y<<": "<<y<<endl;
/****************************************************************************/
#define lson rt<<1
#define rson rt<<1|1
#define Lson l,m,lson
#define Rson m+1,r,rson

const int maxn = 50050;
int seg[maxn << 2], sum[maxn << 2];
int lsum[maxn << 2], rsum[maxn << 2];

void PushUp(int rt, int m) {
	lsum[rt] = lsum[lson];
	rsum[rt] = rsum[rson];
	if (lsum[rt] == m - (m >> 1)) lsum[rt] += lsum[rson];
	if (rsum[rt] == (m >> 1)) rsum[rt] += rsum[lson];
	sum[rt] = max(rsum[lson] + lsum[rson], max(sum[lson], sum[rson]));
}

void PushDown(int rt, int m) {
	if (seg[rt] == -1) return;
	seg[lson] = seg[rson] = seg[rt];
	lsum[lson] = rsum[lson] = sum[lson] = seg[rt] ? 0 : m - (m >> 1);
	lsum[rson] = rsum[rson] = sum[rson] = seg[rt] ? 0 : (m >> 1);
	seg[rt] = -1;
}

void build(int l, int r, int rt) {
	seg[rt] = -1;
	lsum[rt] = rsum[rt] = sum[rt] = r - l + 1;
	if (r == l) return;
	int m = (l + r) >> 1;
	build(Lson);
	build(Rson);
}

void update(int L, int R, int c, int l, int r, int rt) {
	if (L <= l && r <= R) {
		lsum[rt] = rsum[rt] = sum[rt] = c ? 0 : r - l + 1;
		seg[rt] = c;
		return;
	}
	PushDown(rt, r - l + 1);
	int m = (l + r) >> 1;
	if (L <= m) update(L, R, c, Lson);
	if (m < R) update(L, R, c, Rson);
	PushUp(rt, r - l + 1);
}

int query(int c, int l, int r, int rt) {
	if (l == r) return l;
	PushDown(rt, r - l + 1);
	int m = (l + r) >> 1;
	if (sum[lson] >= c) return query(c, Lson);
	else if (rsum[lson] + lsum[rson] >= c) return m - rsum[lson] + 1;
	else return query(c, Rson);
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	int n, m;
	scanf("%d%d", &n, &m);
	build(1, n, 1);
	int op, x, y;
	while (m--) {
		scanf("%d", &op);
		if (op == 1) {
			scanf("%d", &x);
			if (sum[1] < x) printf("0\n");
			else {
				int p = query(x, 1, n, 1);
				printf("%d\n", p);
				update(p, p + x - 1, 1, 1, n, 1);
			}
		}
		else {
			scanf("%d%d", &x, &y);
			update(x, x + y - 1, 0, 1, n, 1);
		}
	}

	return 0;
}