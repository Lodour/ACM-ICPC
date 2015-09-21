#include <iostream>
using namespace std;
int main()
{
    string s;
    while (cin >> s)
    {
        if (s[0] == '#') break;
        int sum = 0;
        int i;
        for (i = 0; i < s.size() - 1; i++)
            if (s[i] == '1')sum++;
        if (s[i] == 'e')
            if (sum % 2 == 0) s[i] = '0';
            else s[i] = '1';
        else if (sum % 2 == 0) s[i] = '1';
        else s[i] = '0';
        cout << s << endl;
    }
    return 0;
}