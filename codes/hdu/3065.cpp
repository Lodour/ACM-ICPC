// Multy Cases
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
const int MAXN = 2000000 + 100;
char txt[MAXN];
char s[1111][55];
int res[1111];

const int AC_SIGMA = 128, AC_V = 130, AC_N = 51 * 1000;
struct AC_automaton {
    struct node {
        node *go[AC_V], *fail, *fa;
        int fg, id;
    } pool[AC_N], *cur, *root, *q[AC_N];
    node* newnode() {
        node *p = cur++;
        memset(p->go, 0, sizeof(p->go));
        p->fail = p->fa = NULL;
        p->fg = 0; p->id = -1;
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
    void query(char s[]) {
        set(res, 0);
        node *p = root;
        for (int i = 0; s[i]; i++) {
            p = p->go[s[i]];
            node *v = p;
            while (v != root) {
                if (v->id != -1) res[v->id]++;
                v = v->fail;
            }
        }
    }
} T;
typedef AC_automaton::node ACnode;


int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int n;
    while (~scanf("%d", &n)) {
        T.init();

        rep(i, 0, n) {
            ACnode *p = T.root;
            scanf("%s", s[i]);
            for (int j = 0; s[i][j]; j++)
                p = T.append(p, s[i][j]);
            p->id = i;
        }

        T.build();

        scanf("%s", txt);
        T.query(txt);

        rep(i, 0, n) if (res[i]) printf("%s: %d\n", s[i], res[i]);
    }
    return 0;
}
