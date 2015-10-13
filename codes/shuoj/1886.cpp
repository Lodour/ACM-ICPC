#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

#define lson rt<<1
#define rson rt<<1|1
#define Lson l,m,lson
#define Rson m+1,r,rson
const int maxn = 100100;

int n, m, ansmin, ansmax, anssum;
int Sum[maxn << 2], Max[maxn << 2], Min[maxn << 2];
void pushup(int rt) {
    Max[rt] = max(Max[lson], Max[rson]);
    Min[rt] = min(Min[lson], Min[rson]);
    Sum[rt] = Sum[lson] + Sum[rson];
}
void build(int l, int r, int rt) {
    if (l == r) {
        scanf("%d", &Max[rt]);
        Sum[rt] = Min[rt] = Max[rt];
        return;
    }
    int m = (l + r) >> 1;
    build(Lson);
    build(Rson);
    pushup(rt);
}
void update(int i, int j, int l, int r, int rt) {
    if (l == r && l == i) {
        Max[rt] += j;
        Sum[rt] += j;
        Min[rt] += j;
        return;
    }
    int m = (l + r) >> 1;
    if (i <= m) update(i, j, Lson);
    if (m < i) update(i, j, Rson);
    pushup(rt);
}
void query(int L, int R, int l, int r, int rt) {
    if (L <= l && r <= R) {
        ansmax = max(ansmax, Max[rt]);
        ansmin = min(ansmin, Min[rt]);
        anssum += Sum[rt];
        return;
    }
    int m = (l + r) >> 1;
    if (L <= m) query(L, R, Lson);
    if (m < R) query(L, R, Rson);
}

int main() {
#ifdef MANGOGAO
    freopen("/Users/Lodour/Downloads/1886-2.in", "r", stdin);
    freopen("/Users/Lodour/Downloads/1886-21.out", "w", stdout);
#endif

    scanf("%d%d", &n, &m);
    build(1, n, 1);
    while (m--) {
        int op, a, b;
        scanf("%d%d%d", &op, &a, &b);
        if (op == 1) update(a, b, 1, n, 1);
        else {
            ansmax = -0x3f3f3f3f;
            ansmin = 0x3f3f3f3f;
            anssum = 0;
            query(a, b, 1, n, 1);
            printf("%d %d %d\n", ansmax, anssum, ansmin);
        }
    }

    return 0;
}
