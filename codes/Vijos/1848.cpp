#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif
	fastcin;
	int n, x, res = 0;
	cin >> n >> x;
	for (int i = 1; i <= n; i++) {
		int j = i;
		while (j) {
			res += j % 10 == x;
			j /= 10;
		}
	}
	cout << res << endl;

	return 0;
}