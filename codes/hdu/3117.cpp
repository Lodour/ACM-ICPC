#include <iostream>
#include <iomanip>
#include <functional>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
using namespace std;
#define PB(X) push_back(X)
#define REP(X,N) for(int X=0;X<N;X++)
#define REP2(X,L,R) for(int X=L;X<=R;X++)
#define DEP(X,R,L) for(int X=R;X>=L;X--)
#define CLR(A,X) memset(A,X,sizeof(A))
#define IT iterator
#define debug(x) cout<<#x<<": "<<x<<endl;
typedef long long ll;

const int maxn = 2;

struct Mat {
    ll mat[maxn][maxn];
    Mat() {
        REP(i, maxn)REP(j, maxn)mat[i][j] = !(i ^ j);
    }
    Mat operator = (const Mat& m) {
        REP(i, maxn)REP(j, maxn)this->mat[i][j] = m.mat[i][j];
    }
};

Mat operator * (const Mat& a, const Mat& b) {
    Mat t;
    REP(i, maxn)
    REP(j, maxn) {
        t.mat[i][j] = 0;
        REP(k, maxn) t.mat[i][j] = (t.mat[i][j] + (a.mat[i][k] * b.mat[k][j]) % 10000) % 10000;
    }
    return t;
}

ostream& operator << (ostream &out, const Mat& m) {
    REP(i, maxn) {
        REP(j, maxn) {
            if (j) out << " ";
            out << m.mat[i][j];
        }
        out << endl;
    }
    return out;
}

int last4(int n) {
    if (n == 0) return 0;
    n--;
    Mat base, ans; base.mat[0][0] = base.mat[0][1] = base.mat[1][0] = 1; base.mat[1][1] = 0;
    while (n) {
        if (n & 1) ans = ans * base;
        base = base * base;
        n >>= 1;
    }
    return ans.mat[0][0];
}

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    ll f[41] = {0}; f[1] = 1;
    REP2(i, 2, 40) f[i] = f[i - 1] + f[i - 2];

    int n;
    while (cin >> n) {
        if (n < 40) printf("%lld\n", f[n]);
        else {
            double a = n * log((1 + sqrt(5)) * 1.0 / 2) / log(10) - log(sqrt(5)) / log(10);
            while (a >= 6.0)a -= 1.0;
            int ANS = pow(10, a);
            while (ANS >= 10000) ANS /= 10;
            printf("%d...%04d\n", ANS, last4(n));
        }

    }
    return 0;
}