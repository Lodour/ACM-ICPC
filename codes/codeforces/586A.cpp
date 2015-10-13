#include <iostream>
#include <cstdio>
using namespace std;

const int N = 10010;
int a[N];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n, ans = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for (int i = 1; i <= n; i++)
		if (a[i] == 1 || (a[i] == 0 && a[i - 1] == 1 && a[i + 1] == 1))
			ans++;
	printf("%d\n", ans);

	return 0;
}
