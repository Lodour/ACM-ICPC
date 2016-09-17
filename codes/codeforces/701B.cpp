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

const int N = 100000 + 100;
bool rr[N], cc[N];

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int n, m;
    cin >> n >> m;
    int r, c; r = c = n;
    while (m--) {
        int x, y;
        cin >> x >> y;
        if (!rr[x]) {
            r--;
            rr[x] = 1;
        }
        if (!cc[y]) {
            c--;
            cc[y] = 1;
        }
        cout << 1LL * r * c << endl;
    }

    return 0;
}
