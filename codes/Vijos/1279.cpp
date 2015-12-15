#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;

ll solve(ll a, ll b) {
	return b == 0 ? 0 : a / b * b + solve(b, a % b);
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	ll a, b;
	for (int i = 0; i < 10; i++) {
		cin >> a >> b;
		if (a < b) swap(a, b);
		cout << solve(a, b) << endl;
	}

	return 0;
}