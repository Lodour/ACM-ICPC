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

	char ip[30];
	while (~scanf("%s", ip)) {
		int a[4] = { -1, -1, -1, -1}, f = 1;
		sscanf(ip, "%d.%d.%d.%d", &a[0], &a[1], &a[2], &a[3]);
		for (int i = 0; f && i < 4; i++)
			f &= (a[i] >= 0 && a[i] <= 255);
		puts(f ? "Y" : "N");
	}
	return 0;
}
