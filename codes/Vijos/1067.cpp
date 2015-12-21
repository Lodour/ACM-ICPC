#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define REP(i,n) for(int i=0;i<n;i++)
#define mod 1000000007LL
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
	Matrix operator ^ (int n) {
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

	int n, k;
	cin >> k >> n;
	k = min(k, n);
	if (k == 1) cout << 1 << endl;
	else {
		Matrix A(1, k), B(k, k);
		for (int i = k - 1; i >= 0; i--)
			A[0][i] = 1 << (k - i - 1);
		B[k - 1][0] = 1;
		for (int i = 0; i < k - 1; i++)
			B[i][0] = B[i][i + 1] = 1;
		B = B ^ (n - k);
		cout << (A * B)[0][0] << endl;
	}

	return 0;
}