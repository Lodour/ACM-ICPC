#include <bits/stdc++.h>
using namespace std;
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
#define set(a,b) memset(a,b,sizeof(a))

string s, t;
bool solve() {
	if (s.size() > t.size()) return 0;
	int i = 0, j = 0;
	while (i < (int)s.size()) {
		while (j < (int)t.size() && t[j] != s[i])
			j++;
		if (j == (int)t.size()) break;
		i++; j++;
	}
	if (i == (int)s.size()) return 1;
	return 0;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	while (cin >> s >> t)
		cout << (solve() ? "Yes" : "No") << endl;

	return 0;
}
