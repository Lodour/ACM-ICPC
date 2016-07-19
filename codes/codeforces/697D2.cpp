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

const int N = 100000 + 100;
double dp[N];
int n, p[N], sz[N];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	scanf("%d", &n);
	rep(i, 2, n + 1) scanf("%d", p + i);
	rep(i, 1, n + 1) sz[i] = 1;
	per(i, 2, n + 1) sz[p[i]] += sz[i];
	dp[1] = 1;
	rep(i, 2, n + 1) dp[i] = dp[p[i]] + 0.5 * (1 + sz[p[i]] - sz[i]);
	rep(i, 1, n + 1) printf("%.7f%c", dp[i], i == n ? '\n' : ' ');

	return 0;
}

