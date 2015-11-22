#include <iostream>
#include <cstdio>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t, a[10], ans = 0;
	for (int i = 0; i < 10; i++)
		scanf("%d", &a[i]);
	scanf("%d", &t);
	for (int i = 0; i < 10; i++)
		ans += t + 30 >= a[i];
	printf("%d\n", ans);


	return 0;
}