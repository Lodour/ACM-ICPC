#include <iostream>
#include <cstdio>
#include <set>
#include <iterator>
#include <algorithm>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int T;
	scanf("%d", &T);
	for (int t = 1; t <= T; t++) {
		int a[3];
		set<int> s;
		for (int i = 0; i < 3; i++)
			scanf("%d", &a[i]);
		sort(a, a + 3);
		do {
			s.insert(a[0] * 100 + a[1] * 10 + a[2]);
		} while (next_permutation(a, a + 3));
		
		printf("Case #%d:\n", t);
		set<int>::iterator it;
		for (it = s.begin(); it != s.end(); it++)
			printf("%d %d %d\n", (*it) / 100, (*it) / 10 % 10, (*it) % 10);
	}

	return 0;
}
