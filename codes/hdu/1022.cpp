#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back

vector<bool> ans;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	fastin;
	int n;
	string s, t;
	while (cin >> n >> s >> t) {
		stack<char> st;
		ans.clear();
		int p = 0, q = 0;
		while (p < n && q < n) {
			if (st.empty()) {
				ans.pb(0);
				st.push(s[p++]);
			}
			while (st.top() != t[q]) {
				st.push(s[p++]);
				ans.pb(0);
				if (p >= n) break;
			}
			while (!st.empty() && st.top() == t[q]) {
				st.pop(); q++;
				ans.pb(1);
				if (q >= n) break;
			}
			if (p >= n && !st.empty()) {
				ans.clear();
				break;
			}
		}
		puts(ans.empty() ? "No." : "Yes.");
		for (bool i : ans)
			puts(i ? "out" : "in");
		puts("FINISH");
	}

	return 0;
}
