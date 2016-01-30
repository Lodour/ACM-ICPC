#include <bits/stdc++.h>
using namespace std;
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
#define set(a,b) memset(a,b,sizeof(a))

string s;
bool check(int n) {
	string base = s.substr(0, n);
	for (int j = n; j < (int)s.size(); j += n)
		if (s.substr(j, n) != base)
			return 0;
}

int solve() {
	for (int i = 1; i < (int)s.size(); i++)
		if (check(i))
			return i;
	return s.size();
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	fastin;
	int T;
	cin >> T;
	while (T--) {
		cin >> s;
		cout << solve() << endl;
		if (T) cout << endl;
	}

	return 0;
}
