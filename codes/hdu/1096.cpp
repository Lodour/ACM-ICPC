#include <iostream>
using namespace std;
int main()
{
	int n, m, tmp, ans;
	bool first = true;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		ans = 0;
		for (int j = 0; j < m; j++)
		{
			cin >> tmp;
			ans += tmp;
		}
		if (first)
		{
			cout << ans << endl;
			first = false;
		}
		else cout <<  endl << ans << endl;
	}
	return 0;
}
