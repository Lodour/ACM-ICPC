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

//*****************************
// Matrix Struct Template
// By mangogao 2015.9.1
//*****************************
#include <cstring>
ll MOD = 0;
const int maxR = 4;
const int maxC = 4;
struct Matrix {
    long long m[maxR][maxC];
    int r, c;
    void init() {memset(m, 0, sizeof(m));}
    Matrix(int _r, int _c): r(_r), c(_c) {init();}
    Matrix(int _n): r(_n), c(_n) {init();}
    void e() {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                m[i][j] = !(i ^ j);
    }
    Matrix& operator = (const Matrix& mat) {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                m[i][j] = mat.m[i][j];
        return *this;
    }
    Matrix& operator = (const int mat[]) {
        int cnt = 0;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                m[i][j] = mat[cnt++];
        return *this;
    }
    Matrix& operator + (const Matrix& mat) {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                m[i][j] += mat.m[i][j];
        return *this;
    }
    Matrix& operator % (const int& MOD) {
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                m[i][j] %= MOD;
        return *this;
    }
    Matrix operator * (const Matrix& mat) {
        Matrix rt(r, mat.c);
        for (int i = 0; i < r; i++)
            for (int k = 0; k < c; k++)
                if (m[i][k] != 0) {
                    for (int j = 0; j < mat.c; j++)
                        if (MOD) rt.m[i][j] = (rt.m[i][j] + (m[i][k] * mat.m[k][j]) % MOD) % MOD;
                        else rt.m[i][j] = rt.m[i][j] + m[i][k] * mat.m[k][j];
                }
        return rt;
    }
    bool operator == (const Matrix& mat) {
        if (r != mat.r || c != mat.c) return false;
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (m[i][j] != mat.m[i][j]) return false;
        return true;
    }
    Matrix operator ^ (int n) {
        Matrix rt(r, c);
        Matrix base(r, c);
        base = *this;
        rt.e();
        while (n) {
            if (n & 1) rt = rt * base;
            base = base * base;
            n >>= 1;
        }
        return rt;
    }
};
ll Pow(ll n, ll m, ll MOD) {
    ll ret = 1;
    while (m) {
        if (m & 1) ret = (ret * n) % MOD;
        m >>= 1;
        n = (n * n) % MOD;
    } return ret;
}

const int maxn = 50000;
int phi[maxn];

int main() {
#ifndef ONLINE_JUDGE
    freopen("data.in", "r", stdin);
#endif

    int t, cnt = 0;
    scanf("%d", &t);

    Matrix A(2, 2);
    int mat[] = {5, 24, 1, 5};
    A = mat;
    while (t--) {
        ll x;
        cin >> x >> MOD;
        if (!phi[MOD]) {
            Matrix E(2, 2);
            Matrix Ba(2, 2);
            E.e(); Ba = A;
            for (int i = 1;; i++) {
                if ((Ba % MOD) == E) {
                    phi[MOD] = i;
                    break;
                }
                Ba = Ba * A;
            }
        }
        Matrix B(1, 2);
        int mat2[] = {1, 0};
        B = mat2;
        ll n = (Pow(2, x, phi[MOD]) + 1) % phi[MOD];
        B = (A ^ (n)) * B;
        cout << "Case #" << ++cnt << ": ";
        cout << (2 * B.m[0][0] - 1 + MOD) % MOD << endl;
    }
    
    return 0;
}