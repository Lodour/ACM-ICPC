#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	char c;
	while ((c = getchar()) != EOF)
		if (isalpha(c))
			putchar(c);
	return 0;
}
