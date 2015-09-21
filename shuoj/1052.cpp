#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <sstream>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <cctype>
using namespace std;
#define mp(X,Y) make_pair(X,Y)
#define pb(X) push_back(X)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef pair<ll, int> PLI;
typedef vector<int> VI;
#define X first
#define Y second
#define de(x) cout<<#x<<": "<<x<<"\t";
#define DE(x) cout<<#x<<": "<<x<<endl;
const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7;
//************************************************

int a[10000];
int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int n, tot = 1;
    cin >> n; n++;
    a[0] = 1;
    while (n--) {
        int d = 0;
        for (int i = 0; i < tot; i++) {
            a[i] = a[i] * 2 + d;
            d = a[i] / 10;
            a[i] %= 10;
        }
        if (d != 0) a[tot++] = d;
    }
    if (a[0] >= 2)a[0] -= 2;
    else {
        int i = 1;
        a[0] = (a[0] + 8) % 10;
        while (a[i] == 0)a[i++] = 9;
        a[i]--;
        tot = max(tot, i + 1);
    }
    while (tot--)
        cout << a[tot];
    cout << endl;
    return 0;
}
/**************************************************************
    Problem: 1052
    User: 14123090
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1600 kb
****************************************************************/