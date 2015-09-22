#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
/****************************************************************************/
#define in(x) scanf("%d",&x)
#define inn(x,y) scanf("%d%d",&x,&y)
#define IN(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define CLR(x,y) memset((x),(y),sizeof(x));
#define debug(x) cout<<#x<<": "<<x<<endl;
#define debug2(x,y) cout<<#x<<": "<<x<<"\t"<<#y<<": "<<y<<endl;
/****************************************************************************/
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 101010;
int n;
ll seg[maxn << 2], sum[maxn << 2];
void PushUp(int rt) {
	sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}
void PushDown(int rt, int m) {
	if (seg[rt] == 0) return;
	seg[rt << 1] += seg[rt];
	seg[rt << 1 | 1] += seg[rt];
	sum[rt << 1] += seg[rt] * (m - (m >> 1));
	sum[rt << 1 | 1] += seg[rt] * (m >> 1);
	seg[rt] = 0;
}
void build(int l, int r, int rt) {
	seg[rt] = 0;
	if (l == r) {
		scanf("%I64d", &sum[rt]);
		return;
	}
	int m = (l + r) >> 1;
	build(lson);
	build(rson);
	PushUp(rt);
}
void update(int L, int R, int c, int l, int r, int rt) {
	if (L <= l && r <= R) {
		seg[rt] += c;
		sum[rt] += c * (r - l + 1);
		return;
	}
	PushDown(rt, r - l + 1);
	int m = (l + r) >> 1;
	if (L <= m) update(L, R, c, lson);
	if (m < R) update(L, R, c, rson);
	PushUp(rt);
}
ll query(int L, int R, int l, int r, int rt) {
	//debug2(l,r)debug(rt)
	if (L <= l && r <= R) return sum[rt];
	PushDown(rt, r - l + 1);
	int m = (l + r) >> 1;
	ll ret = 0;
	if (L <= m) ret += query(L, R, lson);
	if (m < R) ret += query(L, R, rson);
	return ret;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	int q;
	while (inn(n, q) == 2) {
		CLR(sum, 0); CLR(seg, 0);
		build(1, n, 1);
		int x, y, z;
		char op[4];
		while (q--) {
			scanf("%s %d %d", op, &x, &y);
			if (op[0] == 'C') {
				in(z);
				update(x, y, z, 1, n, 1);
			}
			else printf("%I64d\n", query(x, y, 1, n, 1));
		}
	}

	return 0;
}