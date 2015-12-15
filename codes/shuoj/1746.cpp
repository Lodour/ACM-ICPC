#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int MAXN = 10000010;
bool vis[MAXN];
int tot, phi[MAXN], prime[MAXN];
void CalPhi(int n) {
	set(vis, 0); phi[1] = 1; tot = 0;
	for (int i = 2; i < n; i++) {
		if (!vis[i]) {
			prime[tot++] = i;
			phi[i] = i - 1;
		}
		for (int j = 0; j < tot; j++) {
			if (i * prime[j] > n) break;
			vis[i * prime[j]] = 1;
			if (i % prime[j] == 0) {
				phi[i * prime[j]] = phi[i] * prime[j];
				break;
			}
			else phi[i * prime[j]] = phi[i] * (prime[j] - 1);
		}
	}
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
#endif

	int t, cnt = 0;
	scanf("%d", &t);
	CalPhi(MAXN);
	while (t--) {
		ll n;
		scanf("%lld", &n);
		bool ans = 0;
		for (int i = 0; i < tot && !ans; i++) {
			int &p = prime[i];
			if (1LL * p * p > n) break;
			if (n % (1LL * p * p) == 0) ans = 1;
		}
		printf("Case %d: ", ++cnt);
		puts(ans ? "No" : "Yes");
	}
	return 0;
}
