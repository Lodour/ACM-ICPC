#include <iostream>
using namespace std;
int n, m, x, y;

bool controled(int i, int j)
{
    if (i == x && j == y) return 1;
    if (i == x || j == y) return 0;
    int a = i - x, b = j - y;
    if (a < 0)a *= -1;
    if (b < 0)b *= -1;
    return (a + b) == 3;
}

int main()
{
    long long f[21][21] = {0};
    cin >> n >> m >> x >> y;
    f[0][0] = 1;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0 || controled(i, j)) continue;
            if (i == 0 && j > 0) f[i][j] = f[i][j - 1];
            else if (i > 0 && j == 0) f[i][j] = f[i - 1][j];
            else f[i][j] = f[i - 1][j] + f[i][j - 1];
        }
    cout << f[n][m] << endl;
    return 0;
}
/**************************************************************
    Problem: 1013
    User: 14123090
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1560 kb
****************************************************************/