#include <bits/stdc++.h>
using namespace std;
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
#define set(a,b) memset(a,b,sizeof(a))

map<int, int> pre;

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif

    int n, m;
    while (~scanf("%d%d", &n, &m)) {
        printf("%d/%d = %d.", n, m, n / m);
        string ans;
        pre.clear();
        int len;
        for (int i = 1;; i++) {
            n = n % m * 10;
            ans += '0' + n / m;
            if (pre[n]) {
                len = i - pre[n];
                break;
            }
            pre[n] = i;
        }
        int p = ans.size() - len - 1;
        for (int i = 0; i < (int)ans.size() - 1; i++) {
            if (i == 50) {
                printf("...");
                break;
            }
            if (i == p) putchar('(');
            putchar(ans[i]);
        }
        printf(")\n   %d = number of digits in repeating cycle\n\n", len);
    }

    return 0;
}
