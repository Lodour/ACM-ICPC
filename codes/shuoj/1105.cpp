#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	string s;
	getline(cin, s);
	cout << s;
	reverse(s.begin(), s.end());
	cout << s << endl;

	return 0;
}
