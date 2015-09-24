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
#define inf 0x3f3f3f3f
#define mod 1000000007
#define MP(X,Y) make_pair(X,Y)
#define PB(X) push_back(X)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define SZ(A) (int)(A).size()
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define X first
#define Y second
#ifndef ONLINE_JUDGE
#define de(x) cout<<#x<<": "<<x<<"\t";
#define DE(x) cout<<#x<<": "<<x<<endl;
#else
#define de(x) ;
#define DE(x) ;
#endif
//************************************************

bool f(int n) {
    int h = sqrt(n);
    for (int i = 2; i <= h; i++)
        if (n % i == 0)  return 0;
    return 1;
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    const int d[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    for (int i = 1988; i <= 1989; i++)
        for (int j = 1; j <= 12; j++)
            for (int k = 1; k <= d[j] + (int)(k == 2) * (int)(i % 4 == 0); k++) {
                int x = i * 10000 + 1000 * (j / 10) + 100 * (j % 10) + 10 * (k / 10) + k % 10;
                if (f(x)) cout << x << endl;
            }

    return 0;
}

/**************************************************************
    Problem: 1083
    User: 14123090
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1568 kb
****************************************************************/