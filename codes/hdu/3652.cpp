#include <bits/stdc++.h>
using namespace std;
#define set(a,x) memset(a, x, sizeof(a))
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;

const int N = 15;

// dp[i][j][k] = i位余数为j且状态为k的个数 k=0/1/2=不含13/首位为3/含13
int dp[N][13][3], m[N];

void init() {
	m[0] = 1;
	for (int i = 1; i < N; i++)
		m[i] = m[i - 1] * 10 % 13;
	dp[0][0][0] = 1;
	for (int i = 0; i < N - 1; i++)	// 枚举位数
		for (int j = 0; j < 13; j++) {	// 枚举余数
			// 第i位为k时，i+1位余数为(j+m[i]*k)%13的不含13的个数
			for (int k = 0; k < 10; k++)	// 枚举第i位的数字
				dp[i + 1][(j + m[i]*k) % 13][0] += dp[i][j][0];
			// 但是第i位为3时，第i+1位不能为1
			// 需要减去i位数模13余j且首位为3的状态
			dp[i + 1][(j + m[i] * 1) % 13][0] -= dp[i][j][1];

			// 若第i+1位放的是3，要求之前不含13，直接累加
			dp[i + 1][(j + m[i] * 3) % 13][1] += dp[i][j][0];

			// 若第i+1位放的是1后有了13，则第i位是3，累加i位是3的
			dp[i + 1][(j + m[i] * 1) % 13][2] += dp[i][j][1];

			// 已经含有13的直接累加
			for (int k = 0; k < 10; k++)
				dp[i + 1][(j + m[i]*k) % 13][2] += dp[i][j][2];
		}
}

int solve(int n) {
	int num[15] = {0}, tot = 0;
	while (n) {
		num[tot++] = n % 10;
		n /= 10;
	}
	int ans = 0, curmod = 0;
	bool flag = 0;
	for (int i = tot - 1; i >= 0; i--) {
		for (int j = 0; j < num[i]; j++)
			ans += dp[i][(13 - (curmod + j * m[i]) % 13) % 13][2];
		if (flag)
			for (int j = 0; j < num[i]; j++)
				ans += dp[i][(13 - (curmod + j * m[i]) % 13) % 13][0];
		else {
			if (num[i + 1] == 1 && num[i] > 3)
				ans += dp[i + 1][(13 - curmod) % 13][1];
			if (num[i] > 1)
				ans += dp[i][(13 - (curmod + m[i]) % 13) % 13][1];
		}
		if (num[i + 1] == 1 && num[i] == 3)
			flag = 1;
		curmod = (curmod + num[i] * m[i]) % 13;
	}
	return ans;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	fastin;
	init();
	int n;
	while (cin >> n)
		cout << solve(n + 1) << endl;

	return 0;
}