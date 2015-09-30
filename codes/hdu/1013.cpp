// root(n) = (n - 1) % 9 + 1

#include <iostream>
#include <string>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	string s;
	while (cin >> s && s[0] != '0') {
		int n = 0;
		for (int i = 0; i < s.size(); i++)
			n += s[i] - '0';
		cout << (n - 1) % 9 + 1 << endl;
	}

	return 0;
}
