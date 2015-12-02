#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
#define set(a,b) memset(a,b,sizeof(a))

struct bint
{
	int l;
	short int w[100];
	bint(int x = 0) {
		l = x == 0;
		memset(w, 0, sizeof(w));
		while (x != 0) {
			w[l++] = x % 10;
			x /= 10;
		}
	}
	bool operator < (const bint& x) const {
		if (l != x.l) return l < x.l;
		int i = l - 1;
		while (i >= 0 && w[i] == x.w[i]) i--;
		return (i >= 0 && w[i] < x.w[i]);
	}
	bint operator + (const bint& x) const {
		bint ans;
		ans.l = l > x.l ? l : x.l;
		for (int i = 0; i < ans.l; i++) {
			ans.w[i] += w[i] + x.w[i];
			ans.w[i + 1] += ans.w[i] / 10;
			ans.w[i] = ans.w[i] % 10;
		}
		if (ans.w[ans.l] != 0) ans.l++;
		return ans;
	}
	bint operator * (const bint& x) const {
		bint res; int up, tmp;
		for (int i = 0; i < l; i++) {
			up = 0;
			for (int j = 0; j < x.l; j++) {
				tmp = w[i] * x.w[j] + res.w[i + j] + up;
				res.w[i + j] = tmp % 10;
				up = tmp / 10;
			}
			if (up != 0) res.w[i + x.l] = up;
		}
		res.l = l + x.l;
		while (res.w[res.l - 1] == 0 && res.l > 1) res.l--;
		return res;
	}
	void print()
	{
		for (int i = l - 1; i >= 0 ; i--)
			printf("%d", w[i]);
		printf("\n");
	}
};

int line, a[100][100];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n, m;
	bint ans = 0;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= m; j++)
			scanf("%d", &a[i][j]);
	for (line = 1; line <= n; line++) {
		int *b = a[line];
		bint dp[100][100];
		for (int i = 1; i <= m; i++)
			dp[i][i] = b[i];
		for (int len = 1; len < m; len++)
			for (int i = 1; i <= m - len; i++) {
				int j = i + len;
				dp[i][j] = max(dp[i + 1][j] * 2 + b[i], dp[i][j - 1] * 2 + b[j]);
			}
		ans = ans + dp[1][m];
	}
	(ans * 2).print();

	return 0;
}
