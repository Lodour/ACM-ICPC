#include <bits/stdc++.h>
using namespace std;
#define set(a,x) memset(a, x, sizeof(a))
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;

const int B = 20;

ll dp[B][3];

void init() {
    dp[0][0] = 1;
    for (int i = 1; i < B; i++) {
        dp[i][0] = dp[i - 1][0] * 10 - dp[i - 1][1];
        dp[i][1] = dp[i - 1][0];
        dp[i][2] = dp[i - 1][2] * 10 + dp[i - 1][1];
    }
}

ll solve(ll n) {
    int num[25] = {0}, tot = 0;
    while (n) {
        num[++tot] = n % 10;
        n /= 10;
    }
    bool flag = 0;
    ll ans = 0;
    for (int i = tot; i > 0; i--) {
        ans += num[i] * dp[i - 1][2];
        if (flag) ans += num[i] * dp[i - 1][0];
        else if (num[i] > 4)
            ans += dp[i - 1][1];
        if (num[i + 1] == 4 && num[i] == 9)
            flag = 1;
    }
    return ans;
}


int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    fastin;
    init();

    int t; cin >> t;
    while (t--) {
        ll n; cin >> n;
        cout << solve(n + 1) << endl;
    }

    return 0;
}