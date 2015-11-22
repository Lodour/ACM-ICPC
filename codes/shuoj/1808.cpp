#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;


int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	string line;
	vector<int> v;
	set<int> vis;
	while (getline(cin, line)) {
		v.clear(); vis.clear();
		stringstream ss(line);
		int t;
		while (ss >> t) {
			if (vis.count(t)) continue;
			vis.insert(t);
			v.push_back(t);
		}
		for (int i = 0; i < (int)v.size(); i++)
			printf("%d%c", v[i], i == (int)v.size() - 1 ? '\n' : ' ');
	}

	return 0;
}