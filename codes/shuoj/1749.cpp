#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
using namespace std;

const string BASE = "01234567";

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	string a, b;
	while (cin >> a >> b) {
		string ans;
		int i = a.size() - 1;
		int j = b.size() - 1;
		int t = 0;
		for (; i >= 0 || j >= 0; i--, j--) {
			int sum = 0;
			if (i >= 0) sum += a[i] - '0';
			if (j >= 0) sum += b[j] - '0';
			if (t >= 0) sum += t;
			ans += BASE[sum % 8];
			t = sum / 8;
		}
		if (t > 0) ans += BASE[t];
		reverse(ans.begin(), ans.end());
		cout << a << "+" << b << "=" << ans << endl;
	}

	return 0;
}
