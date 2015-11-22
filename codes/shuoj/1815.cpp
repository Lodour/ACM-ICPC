#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;


int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	cin >> t;
	cin.get();
	for (int T = 1; T <= t; T++) {
		string line;
		getline(cin, line);
		stringstream ss(line);
		int ans = 0;
		while (ss >> line) ans++;
		printf("Case %d: %d\n", T, ans);
	}

	return 0;
}