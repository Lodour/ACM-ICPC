#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);

string re(string s) {
	reverse(s.begin(), s.end());
	return s;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif
	fastcin;
	int n;
	cin >> n;
	string a[3];
	for (int i = 0; i < 3; i++)
		cin >> a[i];
	for (int i = 0; i < 3; i++)
		for (int j = i + 1; j < 3; j++) {
			string res;
			for (int k = 0; k < n; k++)
				res += 'a' + ((a[i][k] + a[j][k] - 2 * 'a') >> 1);
			cout << res << endl;
			if (re(res) == a[3 - i - j])
				cout << res << endl;
		}


	return 0;
}
