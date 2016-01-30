#include <bits/stdc++.h>
using namespace std;
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
#define set(a,b) memset(a,b,sizeof(a))

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	fastin;
	int t;
	cin >> t;
	while (t--) {
		string s, ans;
		cin >> s;
		int len = s.size();
		ans = s; s += s;
		for (int i = 0; i < len; i++)
			ans = min(ans, s.substr(i, len));
		cout << ans << endl;
	}

	return 0;
}
