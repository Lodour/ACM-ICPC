#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0;i<n;i++)
ll mod = 1000000007LL;

ll Mul(ll a, ll b, ll mod) {
	ll t = 0;
	for (; b; b >>= 1, a = (a << 1) % mod)
		if (b & 1) t = (t + a) % mod;
	return t;
}

class Matrix {
private:
	int r, c;
	ll **m;
public:
	Matrix(int R, int C): r(R), c(C) {
		m = new ll*[r];
		REP(i, r) m[i] = new ll[c];
		REP(i, r) REP(j, c) m[i][j] = 0;
	}
	Matrix(const Matrix& b) {
		r = b.r; c = b.c; m = new ll*[r];
		REP(i, r) m[i] = new ll[c];
		REP(i, r) REP(j, c) m[i][j] = b.m[i][j];
	}
	~Matrix() {REP(i, r) delete[] m[i]; delete[] m;}
	void e() {REP(i, r) REP(j, c) m[i][j] = !(i ^ j);}
	ll* operator [] (int p) {return m[p];}
	ll* operator [] (int p) const {return m[p];}
	Matrix& operator = (const Matrix& b) {
		if (r != b.r || c != b.c) {
			this->~Matrix();
			r = b.r; c = b.c; m = new ll*[r];
			REP(i, r) m[i] = new ll[c];
		}

		REP(i, r) REP(j, c) m[i][j] = b[i][j];
		return *this;
	}
	Matrix operator * (const Matrix& b) const {
		Matrix rt(r, b.c);
		REP(i, r) REP(k, c) if (m[i][k] != 0) REP(j, b.c)
			rt[i][j] = (rt[i][j] + m[i][k] * b[k][j] % mod) % mod;
		return rt;
	}
	Matrix operator + (const Matrix& b) const {
		Matrix rt(r, c);
		REP(i, r) REP(j, c) rt[i][j] = (m[i][j] + b[i][j]) % mod;
		return rt;
	}
	Matrix operator ^ (ll n) {
		Matrix rt(r, c); rt.e();
		Matrix b(*this);
		while (n) {
			if (n & 1) rt = rt * b;
			b = b * b;
			n >>= 1;
		}
		return rt;
	}
	void out() {
		REP(i, r) REP(j, c)
		cout << m[i][j] << (j == c - 1 ? '\n' : ' ');
		cout << endl;
	}
};


int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	ll a, c, x0, n, g;
	cin >> mod >> a >> c >> x0 >> n >> g;
	Matrix A(1, 2); A[0][0] = x0; A[0][1] = 1;
	Matrix B(2, 2); B[0][0] = a; B[1][0] = c; B[1][1] = 1;
	A = A * (B ^ n);
	cout << A[0][0] % g << endl;

	return 0;
}