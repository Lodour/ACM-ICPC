#include <iostream>
#include <cmath>
using namespace std;
int maxfact = 1;

bool isprime(int x)
{
    if (x == 1) return 0;
    int h = sqrt(x);
    for (int i = 2; i <= h; i++)
        if (x % i == 0)return 0;
    return 1;
}

bool newans(int n)
{
    for (int i = n; i > maxfact; i--)
        if (n % i == 0 && isprime(i)) {maxfact = i; return 1;}
    return 0;
}

int main()
{
    int n, ans;
    while (cin >> n)
    {
        ans = maxfact = 1;
        while (n--)
        {
            int cnt;
            cin >> cnt;
            if (newans(cnt)) ans = cnt;
        }
        cout << ans << endl;
    }
    return 0;
}