#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	while (cin >> n)
		cout << (n == 1 ? 3 : (1LL << n) + (n & 1 ? -2 : 2)) << endl;

	return 0;
}
