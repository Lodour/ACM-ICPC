#include <iostream>
using namespace std;
int dp[11][2];
int main() {
    int n, k;
    cin >> n >> k;
    dp[1][1] = k - 1;
    for (int i = 2; i <= n; i++) {
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][1]) * (k - 1);
        dp[i][0] = dp[i - 1][1];
    }
    cout << dp[n][0] + dp[n][1] << endl;
    return 0;
}
/**************************************************************
    Problem: 1096
    User: 14123090
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1560 kb
****************************************************************/