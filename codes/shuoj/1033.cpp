#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	string s;
	cin >> n;cin.get();
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		if (i) cout << endl;
		cout << s << endl;
	}
	while (getline(cin, s)) {
		stringstream ss(s);
		while (ss >> s)
			cout << endl << s << endl;
	}


	return 0;
}
