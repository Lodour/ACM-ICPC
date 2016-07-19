// G++ would get MLE while C++ would not
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
const ll mod = 1000000007;
const ll inf = 1ll << 60;
// ************************************************************************

const int AC_SIGMA = 128, AC_V = 130, AC_N = 500 * 210;
struct AC_automaton {
    struct node {
        node *go[AC_V], *fail, *fa;
        int fg, id;
    } pool[AC_N], *cur, *root, *q[AC_N];
    node* newnode() {
        node *p = cur++;
        memset(p->go, 0, sizeof(p->go));
        p->fail = p->fa = NULL; p->fg = 0;
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
    }
    bool query(char s[], bool res[]) {
        node *p = root;
        bool flag = 0;
        for (int i = 0; s[i]; i++) {
            p = p->go[s[i]];
            node *v = p;
            while (v != root) {
                if (v->fg) {
                    res[v->id] = 1;
                    flag = 1;
                }
                v = v->fail;
            }
        }
        return flag;
    }
} T;
typedef AC_automaton::node ACnode;

const int MAXN = 10000 + 100;
char txt[MAXN];
bool res[555];

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    T.init();

    char s[222];
    rep(i, 0, n) {
        ACnode *p = T.root;
        scanf("%s", s);
        for (int j = 0; s[j]; j++)
            p = T.append(p, s[j]);
        p->fg++;
        p->id = i;
    }

    T.build();

    int m, ans = 0;
    scanf("%d", &m);
    rep(i, 0, m) {
        scanf("%s", txt);
        set(res, 0);
        if (T.query(txt, res)) {
            printf("web %d:", i + 1);
            rep(j, 0, n) if (res[j]) printf(" %d", j + 1);
            puts("");
            ans++;
        }
    }
    printf("total: %d\n", ans);
    return 0;
}
