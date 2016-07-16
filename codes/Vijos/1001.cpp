#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
const int N = 111;

struct Node {
	string name;
	int qimo, banji, lunwen, id;
	string ganbu, xibu;
	ll sum;
	bool operator < (const Node &b) const {
		if (sum != b.sum) return sum > b.sum;
		return id < b.id;
	}
	void cal() {
		sum = 0;
		if (qimo > 80 && lunwen >= 1) sum += 8000;
		if (qimo > 85 && banji > 80) sum += 4000;
		if (qimo > 90) sum += 2000;
		if (qimo > 85 && xibu[0] == 'Y') sum += 1000;
		if (banji > 80 && ganbu[0] == 'Y') sum += 850;
	}
} s[N];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif
	fastin;
	int n;
	cin >> n;
	ll res = 0;
	for (int i = 0; i < n; i++) {
		s[i].id = i;
		cin >> s[i].name >> s[i].qimo >> s[i].banji >> s[i].ganbu >> s[i].xibu >> s[i].lunwen;
		s[i].cal();
		res += s[i].sum;
	}
	sort(s, s + n);
	cout << s[0].name << endl;
	cout << s[0].sum << endl;
	cout << res << endl;

	return 0;
}