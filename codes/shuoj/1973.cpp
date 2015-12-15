#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define lson rt<<1
#define rson rt<<1|1
#define Lson l,m,lson
#define Rson m+1,r,rson
const int maxn = 100100;
int seg[maxn << 2], f[maxn << 2][3];

void ff(int *g, int t) {
    int tmp;
    if (t == 0) return;
    if (t == 1) {tmp = g[2]; g[2] = g[1]; g[1] = g[0]; g[0] = tmp;}
    if (t == 2) {tmp = g[0]; g[0] = g[1]; g[1] = g[2]; g[2] = tmp;}
}

void PushUp(int rt) {
    for (int i = 0; i < 3; i++)
        f[rt][i] = f[lson][i] + f[rson][i];
}

void PushDown(int rt) {
    if (seg[rt] == 0) return;
    seg[lson] += seg[rt];
    seg[rson] += seg[rt];
    ff(f[lson], seg[rt] % 3);
    ff(f[rson], seg[rt] % 3);
    seg[rt] = 0;
}

void build(int l, int r, int rt) {
    if (l == r) {
        f[rt][0] = 1;
        return;
    }
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
    PushUp(rt);
}

void update(int L, int R, int c, int l, int r, int rt) {
    if (L <= l && r <= R) {
        seg[rt] += c;
        ff(f[rt], c % 3);
        return;
    }
    PushDown(rt);
    int m = (r + l) >> 1;
    if (L <= m) update(L, R, c, Lson);
    if (m < R) update(L, R, c, Rson);
    PushUp(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) return f[rt][0];
    PushDown(rt);
    int m = (l + r) >> 1, ret = 0;
    if (L <= m) ret += query(L, R, Lson);
    if (m < R) ret += query(L, R, Rson);
    return ret;
}

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int n, q, op, l, r;
    scanf("%d%d", &n, &q);
    build(1, n, 1);
    while (q--) {
        scanf("%d%d%d", &op, &l, &r);
        if (op == 0) update(l, r, 1, 1, n, 1);
        else printf("%d\n", query(l, r, 1, n, 1));
    }
    return 0;
}