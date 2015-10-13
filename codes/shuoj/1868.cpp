#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	string s;
	while (cin >> s) {
		long long sum = 0, val = 1;
		for (int i = s.size() - 1; i >= 0; i--) {
			int t = s[i] == 'u' ? -1 : s[i] - '0';
			sum += val * t;
			val <<= 1;
		}
		cout << sum << endl;
	}

	return 0;
}
