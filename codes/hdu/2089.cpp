#include <bits/stdc++.h>
using namespace std;
#define set(a,x) memset(a, x, sizeof(a))
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;

const int B = 10;

int dp[B][B];	// dp[i][j] = 符合要求且以j开头的i位数的个数

void init() {
	dp[0][0] = 1;
	for (int i = 1; i <= 7; i++)
		for (int j = 0; j < 10; j++)	// 第i位为j
			for (int k = 0; k < 10; k++)	// 第i-1位为k
				if (j != 4 && !(j == 6 && k == 2))	// 没有4或62时
					dp[i][j] += dp[i - 1][k];
}

int solve(int n) {
	int num[B] = {0}, tot = 0;
	while (n) {
		num[++tot] = n % 10;
		n /= 10;
	}
	int ans = 0;
	for (int i = tot; i > 0; i--) {
		for (int j = 0; j < num[i]; j++)
			if (j != 4 && !(num[i + 1] == 6 && j == 2))
				ans += dp[i][j];
		if (num[i] == 4 || (num[i] == 2 && num[i + 1] == 6))
			break;
	}
	return ans;
}


int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	fastin;
	init();

	int a, b;
	while (cin >> a >> b, a || b){
		cout << solve(b + 1) - solve(a) << endl;
	}

	return 0;
}