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

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	string s;
	cin >> s;
	for (int i = 0; i < SZ(s); i++)
		if (s[i] == 'e') s[i] = ' ';
	stringstream ss(s);
	int b; ss >> s >> b;
	int p = s.find('.');
	while (b--) {
		if (p + 1 >= SZ(s)) s += '0';
		swap(s[p], s[p + 1]);
		p++;
	}
	while (s[0] == '0' && s[1] != '.') s = s.substr(1);
	while (s[SZ(s) - 1] == '0') s = s.substr(0, SZ(s) - 1);
	if (s[SZ(s) - 1] == '.') s = s.substr(0, SZ(s) - 1);
	cout << s << endl;
	return 0;
}
