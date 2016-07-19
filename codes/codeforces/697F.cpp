#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <functional>
#include <cstdlib>
#include <climits>
#include <cctype>
using namespace std;
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define set(a,x) memset(a, x, sizeof(a))
#define all(x) (x).begin(),(x).end()
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define SZ(x) ((int)(x).size())
#define MO(a,b) (((a)%(b)+(b))%(b))
#define out(x) cout << #x << ": " << x << endl;
#define zero(x) (fabs(x)<eps?1:0)
#define pq priority_queue
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;
const ll mod = 100000;//1000000007;
const ll inf = 1ll << 60;
// ************************************************************************
int n;
ll l;
const int N = 222;
typedef long long Mat[N][N];

// n阶矩阵乘法 a = a * b
void MatMul(Mat& a, Mat& b, int n) {
    Mat res;
    rep(i, 0, n) rep(j, 0, n) res[i][j] = (i == j ? 0 : -inf);
    rep(i, 0, n) rep(k, 0, n) rep(j, 0, n)
    res[i][j] = max(res[i][j], a[i][k] + b[k][j]);
    rep(i, 0, n) rep(j, 0, n) a[i][j] = res[i][j];
}

// n阶矩阵快速幂 a = a ^ p
void MatPow(Mat& a, ll p, int n) {
    Mat ba, res;
    rep(i, 0, n) rep(j, 0, n) {
        res[i][j] = (i == j ? 0 : -inf);
        ba[i][j] = a[i][j];
    }
    for (; p; p >>= 1) {
        if (p & 1) MatMul(res, ba, n);
        MatMul(ba, ba, n);
    }
    rep(i, 0, n) rep(j, 0, n) a[i][j] = res[i][j];
}

const int AC_SIGMA = 26, AC_V = 29, AC_N = 222;
struct AC_automaton {
    struct node {
        node *go[AC_V], *fail, *fa;
        int fg, id;
    } pool[AC_N], *cur, *root, *q[AC_N];
    node* newnode() {
        node *p = cur++;
        memset(p->go, 0, sizeof(p->go));
        p->fail = p->fa = NULL;
        p->fg = 0; p->id = 0;
        return p;
    }
    void init() { cur = pool; root = newnode();}
    node* append(node *p, int w) {
        if (!p->go[w]) p->go[w] = newnode(), p->go[w]->fa = p;
        return p = p->go[w];
    }
    void build() {
        int t = 1;
        q[0] = root;
        rep(i, 0, t) rep(j, 0, AC_SIGMA) if (q[i]->go[j]) {
            node *v = q[i]->go[j], *p = v->fa->fail;
            while (p && !p->go[j]) p = p->fail;
            if (p) v->fail = p->go[j]; else v->fail = root;
            q[t++] = q[i]->go[j];
        } else {
            node *p = q[i]->fail;
            while (p && !p->go[j]) p = p->fail;
            if (p) q[i]->go[j] = p->go[j]; else q[i]->go[j] = root;
        }
        rep(i, 0, t) if (q[i]->fail) q[i]->fg += q[i]->fail->fg;

        // rep(i, 0, t) rep(j, 0, AC_SIGMA) if (!q[i]->go[j]) {
        //     node *p = q[i]->fail;
        //     while (p && !p->go[j]) p = p->fail;
        //     if (p) q[i]->go[j] = p->go[j]; else q[i]->go[j] = root;
        // }

        Mat A;
        rep(i, 0, t) rep(j, 0, t) A[i][j] = -inf;
        rep(i, 0, t) rep(j, 0, AC_SIGMA) {
            ll &d = A[q[i] - pool][q[i]->go[j] - pool];
            d = max(d, (ll)q[i]->go[j]->fg);
        }
        MatPow(A, l, t);
        // rep(i, 0, t)rep(j, 0, t)printf("%I64d%c", A[i][j], j == t - 1 ? '\n' : ' ');
        ll ans = -inf;
        rep(i, 0, t) ans = max(ans, A[0][i]);
        printf("%I64d\n", ans);
    }

} T;
typedef AC_automaton::node ACnode;


int a[N];
char s[N];

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int m;
    scanf("%d%I64d", &n, &l);
    rep(i, 0, n) scanf("%d", &a[i]);
    T.init();
    rep(i, 0, n) {
        scanf("%s", s);
        ACnode *p = T.root;
        for (int j = 0; s[j]; j++)
            p = T.append(p, s[j] - 'a');
        p->fg += a[i];
    }
    T.build();

    return 0;
}
