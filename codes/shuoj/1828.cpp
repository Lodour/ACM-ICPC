#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	int n;
	cin >> n;
	while (n--) {
		string a;
		cin >> a;
		int x = 0;
		for (int i = 0; i < a.size(); i++)
			x = (x * 10 + a[i] - '0') % 13;
		if (x % 13 == 0) puts("Yes");
		else puts("No");
	}

	return 0;
}
