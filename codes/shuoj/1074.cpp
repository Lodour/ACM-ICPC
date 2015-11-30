#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

bool next(string& s, int a, int b) {
	int i = s.size() - 1;
	bool f = 0;
	for (; i >= 0; i--) {
		if (s[i] == char('a' + b - s.size() + i)) continue;
		s[i]++;
		f = 1;
		break;
	}
	if (!f) return 0;
	for (i += 1; i < s.size(); i++)
		s[i] = s[i - 1] + 1;
	return 1;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif
	_
	int a, b, w;
	string s;
	cin >> a >> b >> w >> s;
	for (int i = 0; i < 5 && next(s, a, b); i++)
		cout << s << endl;
	return 0;
}