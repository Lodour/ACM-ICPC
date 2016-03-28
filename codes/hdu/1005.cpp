#include <iostream>
#include <cstdio>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
const int mod = 7;

class Matrix {
public:
	int r, c;
	int **m;
	Matrix(int R, int C): r(R), c(C) {
		m = new int*[r];
		REP(i, r) m[i] = new int[c];
		REP(i, r) REP(j, c) m[i][j] = 0;
	}
	Matrix(const Matrix& B) {
		r = B.r; c = B.c; m = new int*[r];
		REP(i, r) m[i] = new int[c];
		REP(i, r) REP(j, c) m[i][j] = B.m[i][j];
	}
	~Matrix() {REP(i, r) delete[] m[i]; delete[] m;}
	void e() {REP(i, r) REP(j, c) m[i][j] = !(i ^ j);}
	int* operator [] (int p) {return m[p];}
	int* operator [] (int p) const {return m[p];}
	Matrix& operator = (const Matrix& B) {
		r = B.r; c = B.c; this->~Matrix(); m = new int*[r];
		REP(i, r) m[i] = new int[c];
		REP(i, r) REP(j, c) m[i][j] = B[i][j];
		return *this;
	}
	Matrix operator * (const Matrix& B) const {
		Matrix rt(r, B.c);
		REP(i, r) REP(k, c) if (m[i][k] != 0) REP(j, B.c)
			rt[i][j] = (rt[i][j] + m[i][k] * B[k][j] % mod) % mod;
		return rt;
	}
	Matrix operator ^ (int n) {
		Matrix rt(r, c); rt.e();
		Matrix ba(*this);
		while (n) {
			if (n & 1) rt = rt * ba;
			ba = ba * ba;
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

int solve(int A, int B, int n) {
	if (n <= 2) return 1;
	Matrix a(2, 2), b(2, 1);
	a[0][0] = A; a[0][1] = B;
	a[1][0] = 1; a[1][1] = 0;
	b[0][0] = b[1][0] = 1;
	return ((a ^ n - 2) * b)[0][0];
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int A, B, n;
	while (cin >> A >> B >> n, A && B && n)
		cout << solve(A, B, n) << endl;

	return 0;
}
