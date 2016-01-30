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
		string s;
		cin >> s; s += "X";
		int ans = 0, cnt = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			if (s[i] == 'X')
				ans += (1 + cnt) * cnt / 2, cnt = 0;
			else cnt++;
		}
		cout << ans << endl;
	}

	return 0;
}
