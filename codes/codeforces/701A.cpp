#include <algorithm>
#include <iostream>
#include <cstring>
#include <bitset>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <map>
#include <set>
using namespace std;
#define fi first
#define eps 1e-8
#define se second
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef vector<int> VI;
typedef pair<int, int> PII;
const ll iinf = 1LL << 60;
#define inf 0x3f3f3f3f
#define SZ(x) ((int)(x).size())
#define MO(a,b) (((a)%(b)+(b))%(b))
#define all(x) (x).begin(),(x).end()
#define set(a,x) memset(a, x, sizeof(a))
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
#define out(x) cout << #x << ": " << x << endl;
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// head
const int N = 111;
int a[N], id[N];

bool cmp(int i, int j) {
    return a[i] < a[j];
}

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int n;
    scanf("%d", &n);
    rep(i, 0, n) {
        scanf("%d", a + i);
        id[i] = i;
    }
    sort(id, id + n, cmp);
    for (int i = 0, j = n - 1; i < j; i++, j--)
        printf("%d %d\n", id[i]+1, id[j]+1);

    return 0;
}
