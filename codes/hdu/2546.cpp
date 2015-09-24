#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

const int maxn = 1010;
int a[maxn], dp[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int n, m;
    while (cin >> n && n) {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cin >> m;
        if (m < 5) {
            cout << m << endl;
            continue;
        }
        sort(a, a + n);
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n - 1; i++)
            for (int j = m - 5; j >= a[i]; j--)
                dp[j] = max(dp[j], dp[j - a[i]] + a[i]);
        cout << m - dp[m - 5] - a[n - 1] << endl;
    }

#ifndef ONLINE_JUDGE
    cout << "Done..." << endl;
    while (1);
#endif
    return 0;
}