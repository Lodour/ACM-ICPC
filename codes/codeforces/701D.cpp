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

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int n, l, v1, v2, k;
    cin >> n >> l >> v1 >> v2 >> k;
    double kk = 1.0 * v1 / v2 + (1.0 - 1.0 * v1 / v2) * v1 * 1.0 / (v1 + v2);
    int N = (n + k - 1) / k;
    double x = 1.0 * l / (1.0 + (N - 1) * kk);
    double ans = (N - 1) * kk * x / v1 + x / v2;
    printf("%.10f\n", ans);

    return 0;
}

