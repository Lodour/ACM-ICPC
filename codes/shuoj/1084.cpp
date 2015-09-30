#include <iostream>
#include <string>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	int a, b;
	string s;
	while (getline(cin, s)) {
		a = b = 0;
		for (int i = 0; i < s.size(); i++) {
			string ss = s.substr(i, 2);
			a += ss == "/*";
			b += ss == "*/";
		}
		if (a < 2 && !(a ^ b))
			cout << s << endl;
	}

	return 0;
}
