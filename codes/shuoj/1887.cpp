#include <cstdio>
#include <cstring>
using namespace std;
#define lson rt<<1
#define rson rt<<1|1
#define Lson l,m,lson
#define Rson m+1,r,rson
#define set(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int maxn = 100010;
ll seg[maxn << 2], sum[maxn << 2];
void PushUp(int rt) {
    sum[rt] = sum[lson] + sum[rson];
}
void PushDown(int rt, int m) {
    if (seg[rt] == 0) return;
    seg[lson] += seg[rt];
    seg[rson] += seg[rt];
    sum[lson] += seg[rt] * (m - (m >> 1));
    sum[rson] += seg[rt] * (m >> 1);
    seg[rt] = 0;
}
void build(int l, int r, int rt) {
    seg[rt] = 0;
    if (l == r) {
        scanf("%lld", &sum[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
    PushUp(rt);
}
void update(int L, int R, int add, int l, int r, int rt) {
    if (L <= l && r <= R) {
        seg[rt] += add;
        sum[rt] += add * (r - l + 1);
        return;
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if (L <= m) update(L, R, add, Lson);
    if (m < R) update(L, R, add, Rson);
    PushUp(rt);
}
ll query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) return sum[rt];
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    ll ret = 0;
    if (L <= m) ret += query(L, R, Lson);
    if (m < R) ret += query(L, R, Rson);
    return ret;
}
int main() {
    //freopen("data.in", "r", stdin);
    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        set(seg, 0); set(sum, 0);
        build(1, n, 1);
        while (m--) {
            int op, x, y, z;
            scanf("%d", &op);
            if (op == 1) {
                scanf("%d%d%d", &x, &y, &z);
                update(x, y, z, 1, n, 1);
            }
            else {
                scanf("%d%d", &x, &y);
                printf("%lld\n", query(x, y, 1, n, 1));
            }
        }
    }
    return 0;
}
