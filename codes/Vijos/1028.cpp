#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
typedef long long ll;
#define set(a,b) memset(a,b,sizeof(a))

string s[2020];
int dp[2020];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	ios_base::sync_with_stdio(0); cin.tie(0);
	int n; cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (s[i].find(s[j]) == 0)
				dp[i] = max(dp[i], dp[j] + 1);
	}
	cout << *max_element(dp, dp + n) << endl;

	return 0;
}
