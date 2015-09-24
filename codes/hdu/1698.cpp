#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
/****************************************************************************/
#define in(x); scanf("%d",&x);
#define inn(x,y); scanf("%d%d",&x,&y);
#define IN(x,y,z); scanf("%d%d%d",&x,&y,&z);
#define debug(x) cout<<#x<<": "<<x<<endl;
#define debug2(x,y) cout<<#x<<": "<<x<<"\t"<<#y<<": "<<y<<endl;
/****************************************************************************/
#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1
const int maxn = 101010;
int n;
int t[maxn << 2], sum[maxn << 2];
// 向上更新
void pushUp(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1]; // 根节点更新为两个儿子节点之和
}
// 向下更新
void pushDown(int rt, int m) {
    if (t[rt] == 0) return;
    t[rt << 1] = t[rt << 1 | 1] = t[rt]; // 标记不为0时，标记向下传递
    sum[rt << 1] = (m - (m >> 1)) * t[rt]; // 左儿子的值更新为区间长度*标记
    sum[rt << 1 | 1] = (m >> 1) * t[rt]; // 右儿子的值更新为区间长度*标记
    t[rt] = 0;                      // 取消根节点的标记
}
void build(int l, int r, int rt) {
    t[rt] = 0;          // 根节点标记初始化为0
    sum[rt] = 1;        // 根节点值初始化为1（题意）
    if (l == r) return; // 左右索引相遇时返回
    int m = (l + r) >> 1; // 设置二分中点
    build(lson);        // 递归建立左侧子树
    build(rson);        // 递归建立右侧子树
    pushUp(rt);         // 回溯时往上更新各节点的值
}
void update(int L, int R, int c, int l, int r, int rt) {
    if (L <= l && r <= R) {         // 搜索区间包含于目标区间时
        t[rt] = c;                  // 标记修改后的值
        sum[rt] = c * (r - l + 1);  // 根节点可以直接更新
        return;
    }
    pushDown(rt, r - l + 1);        // 向下更新
    int m = (l + r) >> 1;           // 二分中点
    if (L <= m) update(L, R, c, lson); // 左侧需要更新时，更新左侧
    if (R > m) update(L, R, c, rson); // 右侧需要更新时，更新右侧
    pushUp(rt);                     // 回溯时往上更新各节点的值
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int t, cnt = 0; in(t);
    while (t--) {
        int n, q; inn(n, q);
        build(1, n, 1);
        int x, y, z;
        while (q--) {
            IN(x, y, z);
            update(x, y, z, 1, n, 1);
        }
        printf("Case %d: The total value of the hook is %d.\n", ++cnt, sum[1]);
    }

    return 0;
}