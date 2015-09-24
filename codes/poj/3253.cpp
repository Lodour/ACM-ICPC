#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	int n, x;
	ll ans = 0;
	scanf("%d", &n);
	priority_queue<ll, vector<ll>, greater<ll> > pq;
	for (int i = 0; i < n; i++) {
		cin >> x;
		pq.push(x);
	}
	while (pq.size() != 1) {
		ll x = pq.top(); pq.pop();
		ll y = pq.top(); pq.pop();
		ans += x + y;
		pq.push(x + y);
	}
	printf("%lld\n", ans);

	return 0;
}