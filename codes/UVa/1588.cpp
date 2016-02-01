#include <bits/stdc++.h>
using namespace std;
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
#define set(a,b) memset(a,b,sizeof(a))

int solve(string s, string t) {
	for (int i = 0; i < (int)t.size(); i++)
		if (t[i] == '1') t[i] = '*';
		else t[i] = '1';
	for (int i = 0; i < (int)s.size(); i++) {
		bool f = 1;
		for (int j = 0; j < (int)t.size(); j++)
			if (i + j < (int)s.size()) {
				if (t[j] != '*' && t[j] != s[i + j])
					f = 0;
			}
			else {
				if (f) return s.size() + t.size() - j;
				break;
			}
		if (f) return s.size();
	}
	return s.size() + t.size();
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	fastin;
	string s, t;
	while (cin >> s >> t)
		cout << min(solve(s, t), solve(t, s)) << endl;


	return 0;
}
