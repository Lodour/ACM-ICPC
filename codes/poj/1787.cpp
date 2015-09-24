#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;
int dp[10010], ans[10010], num[10010], path[10010];
int p, c[5] = {0, 1, 5, 10, 25}, t[5];
int main()
{
	while (scanf("%d %d %d %d %d", &p, &t[1], &t[2], &t[3], &t[4]) > 0 && (p + t[1] + t[2] + t[3] + t[4]))
	{
		memset(dp, 0, sizeof(dp));
		memset(ans, 0, sizeof(ans));
		memset(path, 0, sizeof(path));
		dp[0] = 1;
		for (int i = 1; i <= 4; i++)
		{
			memset(num, 0, sizeof(num));
			for (int j = c[i]; j <= p; j++)
				if (dp[j - c[i]] && dp[j - c[i]] + 1 > dp[j] && num[j - c[i]] < t[i]) //一般来说，完全背包的硬币是没有限制的，后一个数必然可以由前面的某个数组成，所以也就不需要dp[j-c[i]]>0，<br>但是，这次用到的完全背包其硬币数受到了限制，也就导致有些数根本不可能组成，所以要把这些数排除
				{
					dp[j] = dp[j - c[i]] + 1;
					num[j] = num[j - c[i]] + 1;
					path[j] = j - c[i];
				}
		}
		int i = p;
		if (dp[p] > 0)
		{
			while (i != 0)
			{
				ans[i - path[i]]++;
				i = path[i];
			}
			printf("Throw in %d cents, %d nickels, %d dimes, and %d quarters.\n", ans[1], ans[5], ans[10], ans[25]);
		}
		else  printf("Charlie cannot buy coffee.\n");
	}
	return 0;
}