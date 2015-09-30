#include <iostream>
using namespace std;
int main()
{
	int a, b, n, tmp, m, ans;
	cin >> n;
	for (int j = 0; j < n; j++)
	{
		ans = 0;
		cin >> m;
		for (int i = 0; i < m; i++)
		{
			cin >> tmp;
			ans += tmp;
		}
		cout << ans << endl;
	}
	return 0;
}
