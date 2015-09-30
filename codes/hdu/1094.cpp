#include <iostream>
using namespace std;
int main()
{
	int a, b, n, tmp, m, ans;
	while (cin >> n)
	{
		ans = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> tmp;
			ans += tmp;
		}
		cout << ans << endl;
	}
	return 0;
}
