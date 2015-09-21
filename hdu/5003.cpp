#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <string>
#include <algorithm>
using namespace std;

double p[55] = {1.0};
double a[55];
double P(int n) {
    if (p[n]) return p[n];
    return p[n] = 0.95 * p[n - 1];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        double ans = 0.0;
        for (int i = 0; i < n; i++) {
            scanf("%lf", &a[i]);
            a[i] = -a[i];
        }
        sort(a, a + n);
        for (int i = 0; i < n; i++)
            ans += P(i) * -a[i];
        printf("%.10lf\n", ans);
    }

    return 0;
}