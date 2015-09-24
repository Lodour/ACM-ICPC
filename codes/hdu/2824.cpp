#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 3e6 + 10;
int phi[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    for (int i = 0; i < maxn; i++) phi[i] = i;
    for (int i = 2; i < maxn; i++)
        if (phi[i] == i)
            for (int j = i; j < maxn; j += i)
                phi[j] = phi[j] / i * (i - 1);

    int a, b;
    while (~scanf("%d%d", &a, &b)) {
        long long ans = 0;
        for (int i = a; i <= b; i++) {
            ans += phi[i];
        }
        printf("%lld\n", ans);
    }
    return 0;
}