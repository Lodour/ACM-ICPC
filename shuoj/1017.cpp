#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;

const int maxn = 500;
int ans[maxn], base[maxn], tmp[maxn];

void mul(int a[], int b[]) {
    memset(tmp, 0, sizeof(tmp));
    for (int i = 0; i < maxn; i++)
        for (int j = 0; j < maxn; j++)
            if (i + j < maxn)
                tmp[i + j] += a[i] * b[j];
    for (int i = 0; i < maxn; i++) {
        tmp[i + 1] += tmp[i] / 10;
        tmp[i] %= 10;
        a[i] = tmp[i];
    }
}


int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int p;
    scanf("%d", &p);
    int len = floor(p * log10(2)) + 1;
    ans[0] = 1;
    base[0] = 2;
    while (p) {
        if (p & 1) mul(ans, base);
        mul(base, base);
        p >>= 1;
    }
    for (int i = 0; i < maxn; i++)
        if (ans[i] == 0) ans[i] = 9;
        else {
            ans[i]--;
            break;
        }

    printf("%d\n", len);
    for (int i = maxn - 1; i >= 0; i--) {
        printf("%d", ans[i]);
        if (i % 50 == 0) printf("\n");
    }

    return 0;
}
/**************************************************************
    Problem: 1017
    User: 14123090
    Language: C++
    Result: Accepted
    Time:44 ms
    Memory:1580 kb
****************************************************************/