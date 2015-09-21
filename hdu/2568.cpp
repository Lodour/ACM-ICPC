#include <iostream>
using namespace std;
int main()
{
    int c;
    cin >> c;
    while (c--)
    {
        int n, ans = 0;
        cin >> n;
        while (n > 0)
        {
            if (n % 2 == 1) {ans++; n--;}
            while (n % 2 == 0 && n != 0)n /= 2;
        }
        cout << ans << endl;
    }
    return 0;
}