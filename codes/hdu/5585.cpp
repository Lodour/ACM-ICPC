#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	string s;
	int a, b, c;
	while (getline(cin, s)) {
		a = b = c = 0;
		for (int i = 0; i < s.size(); i++) {
			a = (a * 10 + s[i] - '0') % 2;
			b = (b * 10 + s[i] - '0') % 3;
			c = (c * 10 + s[i] - '0') % 5;
		}
		puts(!a || !b || !c ? "YES" : "NO");
	}

	return 0;
}