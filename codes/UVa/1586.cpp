#include <bits/stdc++.h>
using namespace std;
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
#define set(a,b) memset(a,b,sizeof(a))

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	fastin;
	const double val[] = {12.01, 1.008, 16.00, 14.01};
	const string base = "CHON";
	int t;
	cin >> t;
	while (t--) {
		string s;
		cin >> s; s += "H";
		double ans = 0;
		int cur = 0, cnt = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			if (isalpha(s[i])) {
				// cout << base[cur] << " " << cnt << endl;
				ans += val[cur] * cnt;
				cur = base.find(s[i]);
				cnt = 1;
			}
			else {
				if (isalpha(s[i - 1])) cnt = 0;
				cnt = cnt * 10 + s[i] - '0';
			}
		}
		cout << setprecision(3) << fixed << ans << endl;
	}

	return 0;
}
