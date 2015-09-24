#include<stdio.h>
#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int MAXN = 6050;
vector<int>vec[MAXN];
int f[MAXN];
int hap[MAXN];
int dp[MAXN][2];

void dfs(int root)
{
    int len = vec[root].size();
    dp[root][1] = hap[root];
    for (int i = 0; i < len; i++)
        dfs(vec[root][i]);
    for (int i = 0; i < len; i++)
    {
        dp[root][0] += max(dp[vec[root][i]][1], dp[vec[root][i]][0]);
        dp[root][1] += dp[vec[root][i]][0];
    }
}
int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int n;
    int a, b;
    while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &hap[i]);
            vec[i].clear();
            f[i] = -1; //树根标记
            dp[i][0] = dp[i][1] = 0;
        }
        while (scanf("%d%d", &a, &b))
        {
            if (a == 0 && b == 0)break;
            f[a] = b;
            vec[b].push_back(a);
        }
        a = 1;
        while (f[a] != -1)a = f[a]; //找到树根
        dfs(a);
        printf("%d\n", max(dp[a][1], dp[a][0]));


    }
    return 0;
}