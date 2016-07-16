#include <iostream>
#include <string>
#include <cstdio>
#include <algorithm>
using namespace std;
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif
	fastcin;
	char c;
	string s;
	while ((c = getchar()) != 'E')
		if (c == 'W' || c == 'L') s += c;

	{
		int a, b; a = b = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			a += s[i] == 'W';
			b += s[i] == 'L';
			if ((a >= 11 || b >= 11) && abs(a - b) >= 2) {
				printf("%d:%d\n", a, b);
				a = b = 0;
			}
		}
		printf("%d:%d\n\n", a, b);
	}

	{
		int a, b; a = b = 0;
		for (int i = 0; i < (int)s.size(); i++) {
			a += s[i] == 'W';
			b += s[i] == 'L';
			if ((a >= 21 || b >= 21) && abs(a - b) >= 2) {
				printf("%d:%d\n", a, b);
				a = b = 0;
			}
		}
		printf("%d:%d\n", a, b);
	}

	return 0;
}
