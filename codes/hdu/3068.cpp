#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char str[110110 << 1], s[110110];
int p[110110 << 1];
int manacher(int len) {
    int ans = 0;
    str[0] = '$'; str[1] = '#';
    for (int i = 0; i < len; i++)
        str[2 * (i + 1)] = s[i], str[2 * (i + 1) + 1] = '#';
    str[2 * len + 2] = '\0';
    len = 2 * len + 2;
    int id = 0, mx = 0;
    p[0] = 0;
    for (int i = 1; i < len; i++) {
        if (i >= p[id] + id)p[i] = 1;
        else p[i] = min(p[2 * id - i], mx - i);
        while (str[i - p[i]] == str[i + p[i]]) p[i]++;
        if (p[i] + i > mx) mx = p[i] + i, id = i;
        ans = max(ans, p[i] - 1);
    }
    return ans;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    while (~scanf("%s", s)) {
        printf("%d\n", manacher(strlen(s)));
    }

    return 0;
}