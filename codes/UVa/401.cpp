#include <bits/stdc++.h>
using namespace std;
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);

const string ss = "ABCDEFGHIJKLMNOPQRSTUVWXYZ123456789";
const string tt = "A   3  HIL JM O   2TUVWXY51SE Z  8 ";

char f(char c) {
	int p = ss.find(c);
	if (p == (int)string::npos) return ' ';
	return tt[p];
}
int solve(string &s) {
	int rt = 3;
	int i = 0, j = (int)s.size() - 1;
	for (; i <= j; i++, j--) {
		if (s[i] != s[j]) rt &= 2;
		if (s[i] != f(s[j])) rt &= 1;
	}
	return rt;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	string s;
	const string a[] = {"not a palindrome.", "a regular palindrome.", "a mirrored string.", "a mirrored palindrome."};
	while (cin >> s)
		cout << s << " -- is " << a[solve(s)] << endl << endl;

	return 0;
}
