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
			if (i & 1) x += a[i] - '0';
			else x -= a[i] - '0';
		if (abs(x) % 11 == 0) puts("Yes");
		else puts("No");
	}

	return 0;
}
