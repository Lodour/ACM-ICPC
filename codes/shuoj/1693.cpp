#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

char f(string s) {
	int a = 0;
	for (int i = 0; i < s.size(); i++)
		a = a * 10 + (s[i] - '0');
	return a;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	cin >> t;
	getchar();
	while (t--) {
		string s;
		getline(cin, s);
		reverse(s.begin(), s.end());
		if (s[0] >= '0' && s[0] <= '9')
			for (int i = 0; i < s.size(); i += 2 + (s[i] == '1'))
				putchar(f(s.substr(i, 2 + (s[i] == '1'))));
		else
			for (int i = 0; i < s.size(); i++) {
				while (s[i]) {
					printf("%d", s[i] % 10);
					s[i] /= 10;
				}
			}
		puts("");
	}
	return 0;
}
