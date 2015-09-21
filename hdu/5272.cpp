#include <iostream>
#include <cmath>
#include <cstdio>
typedef long long int ll;
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int t; scanf("%d", &t);
    while (t--) {
        ll n;
        scanf("%lld", &n);
        bool f = 0;
        int ans = 0;
        while (n != 0) {
            if ((n & 1) == 1) f = 1;
            else if (f) {
                ans++;
                f = 0;
            }
            n >>= 1;
        }
        printf("%d\n", ans + f);
    }
    return 0;
}