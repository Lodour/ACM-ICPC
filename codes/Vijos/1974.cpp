#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n; cin >> n;
	int cnt = 1, cur = 1, ans = 0;
	while (n--) {
		ans += cur;
		cnt--;
		if (cnt == 0) cnt = cur = cur + 1;
	}
	cout << ans << endl;

	return 0;
}
