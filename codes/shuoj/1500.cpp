#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	int cnt = 0, x, fi = 1;
	char op[5];
	stack<int> st;
	while (~scanf("%s", op)) {
		if (fi == 1) {
			printf("Case %d:\n", ++cnt);
			fi = 0;
		}
		if (op[0] == '#') {
			while (!st.empty())st.pop();
			fi = 1;
			puts("");
			continue;
		}
		if (fi == 0) {
			if (op[1] == 'U') {
				scanf("%d", &x);
				st.push(x);
				continue;
			}
			if (op[1] == 'O') {
				if (st.empty()) {
					puts("Error");
					fi = 2;
				}
				else {
					printf("%d\n", st.top());
					st.pop();
				}
			}
		}

	}

	return 0;
}