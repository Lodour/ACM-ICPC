#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	string s;
	vector<string> v;
	while (getline(cin, s))
		v.push_back(s.substr(0, s.find('(')));
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (int i = 0; i < v.size(); i++)
		cout << v[i] << endl;

	return 0;
}
