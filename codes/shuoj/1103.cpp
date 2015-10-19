#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	char a[110];
	gets(a);
	for(int i=0;a[i];i++)
		putchar(tolower(a[i]));

	return 0;
}
