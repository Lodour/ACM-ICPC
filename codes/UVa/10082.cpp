#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	const string s = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./";
	char c;
	while (c = getchar(), c != EOF) {
		int p = s.find(c);
		if (p == (int)string::npos) putchar(c);
		else putchar(s[p - 1]);
	}

	return 0;
}
