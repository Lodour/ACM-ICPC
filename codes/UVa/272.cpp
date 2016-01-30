#include <bits/stdc++.h>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	char c;
	bool f = 1;
	while (c = getchar(), c != EOF) {
		if (c == '"') {
			if (f) printf("``");
			else printf("''");
			f = !f;
		} else putchar(c);
	}

	return 0;
}
