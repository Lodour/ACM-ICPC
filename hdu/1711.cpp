#include <cstdio>
#include <string>
using namespace std;
int str[1001000], opt[10010];
int Next[10010], len1, len2;
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
int kmp() {
    int i = 0, j = 0;
    while (i < len1 && j < len2) {
        if (j == -1 || str[i] == opt[j]) {
            i++; j++;
        }
        else j = Next[j];
    }
    return j == len2 ? i - j + 1 : -1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d", &len1, &len2);
        for (int i = 0; i < len1; i++) scanf("%d", &str[i]);
        for (int i = 0; i < len2; i++) scanf("%d", &opt[i]);
        getnext();
        printf("%d\n", kmp());
    }
    return 0;
}