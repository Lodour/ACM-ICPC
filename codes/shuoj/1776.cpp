#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
 
const int N = 46;
long long dp[N] = {0, 1, 1};
 
int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif
 
    for (int i = 3; i < N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    int n;
    while (~scanf("%d", &n))
        printf("%lld\n",dp[n]);
 
    return 0;
}
