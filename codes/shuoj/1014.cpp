#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef pair<int, int> PII;
#define X first
#define Y second
#define pb push_back
#define mp make_pair

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	string s;
	vector<PII> ans1, ans2;
	PII a1, a2;
	while (cin >> s) {
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'E') {
				ans1.pb(a1);
				ans2.pb(a2);
				for (int j = 0; j < ans1.size(); j++)
					cout << ans1[j].X << ":" << ans1[j].Y << endl;
				cout << endl;
				for (int j = 0; j < ans2.size(); j++)
					cout << ans2[j].X << ":" << ans2[j].Y << endl;
				return 0;
			}
			if (s[i] == 'W') {a1.X++; a2.X++;}
			if (s[i] == 'L') {a1.Y++; a2.Y++;}
			if ((a1.X >= 11 || a1.Y >= 11) && abs(a1.X - a1.Y) > 1) {
				ans1.pb(a1);
				a1 = mp(0, 0);
			}
			if ((a2.X >= 21 || a2.Y >= 21) && abs(a2.X - a2.Y) > 1) {
				ans2.pb(a2);
				a2 = mp(0, 0);
			}
		}
	}

	return 0;
}
