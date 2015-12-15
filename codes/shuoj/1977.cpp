#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))
const int maxn = 100010;
char s[maxn];
int dp[maxn][10];

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int t, len;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", s); set(dp, 0x3f);
        len = strlen(s);
        for (int i = 0; i < 10; i++)
            dp[0][i] = 0;
        for (int i = 0; i < len; i++) {
            int si = s[i] - '0';
            for (int j = 0; j < 10; j++) {
                dp[i + 2][j] = min(dp[i + 2][j], dp[i][j] + 1);
                if (j != 0) dp[i + 1][0] = min(dp[i + 1][0], dp[i][j] + 1);
                if (j != si) dp[i + 1][si] = min(dp[i + 1][si], dp[i][j]);
            }
        }
        int ans = dp[len][0];
        for (int i = 1; i < 10; i++)
            ans = min(ans, dp[len][i]);
        printf("%d\n", ans);
    }
    return 0;
}
