#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
#define PI 3.141592653589793116
#define E 2.718281828459045091

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int ans = 0.5 * log10(2 * PI * n) + 1.0 * n * log10(1.0 * n / E);
        printf("%d\n", ans + 1);
    }

    return 0;
}
