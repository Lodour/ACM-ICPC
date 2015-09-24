#include <cstdio>
#include <cstring>
using namespace std;
char str[1010], opt[1010];
int Next[1010], len1, len2;
void getnext() {
    Next[0] = -1;
    int i = 0, j = -1;
    while (i < len2) {
        if (j == -1 || opt[i] == opt[j]) {
            i++; j++;
            Next[i] = j;
        }
        else j = Next[j];
    }
}
int kmp(int st) {
    int i = st, j = 0;
    while (i < len1 && j < len2) {
        if (j == -1 || str[i] == opt[j]) {
            i++; j++;
        }
        else j = Next[j];
    }
    return j == len2 ? i - j + 1 : 0;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    while (scanf("%s", str) && str[0] != '#') {
        scanf("%s", opt);
        len1 = strlen(str);
        len2 = strlen(opt);
        getnext();
        int ans = 0, pos, st = 0;
        while ((pos = kmp(st)) && pos != 0) {
            st = pos + len2 - 1;
            ans++;
        }
        printf("%d\n", ans);
    }

    return 0;
}