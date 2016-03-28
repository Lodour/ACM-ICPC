#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <iterator>
using namespace std;
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);

map<string, int> sum;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	fastcin;
	int n;
	while (cin >> n && n) {
		sum.clear();
		string s;
		while (n--) {
			cin >> s;
			sum[s]++;
		}
		string ans;
		int ma = 0;
		map<string, int>::iterator i;
		for (i = sum.begin(); i != sum.end(); i++)
			if (i->second > ma) {
				ma = i->second;
				ans = i->first;
			}
		cout << ans << endl;
	}

	return 0;
}
