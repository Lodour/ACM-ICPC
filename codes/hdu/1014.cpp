#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))
typedef long long ll;
const int N = 100010;
ll step, mod;
int tot;
bool vis[N];

bool solve() {
    set(vis, 0);
    tot = 0;
    ll n = 0;
    while (!vis[n]) {
        vis[n] = 1;
        n = (n + step) % mod;
        tot++;
    }
    return tot == mod;
}

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    while (~scanf("%lld %lld", &step, &mod)) {
        printf("% 10lld% 10lld    ", step, mod);
        puts(solve() ? "Good Choice\n" : "Bad Choice\n");
    }
    return 0;
}
