#include <bits/stdc++.h>
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
#define mp(a,b) make_pair(a,b)
#define X first
#define Y second
using namespace std;
typedef pair<int, int> PII;
string G[5];
PII p;

void out() {
	puts("------------------------");
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			printf("%c%c", G[i][j], j == 4 ? '\n' : ' ');
	puts("------------------------");
}

bool go(char c) {
	PII q;
	if (c == 'A') {
		if (p.X == 0) return 0;
		q = mp(p.X - 1, p.Y);
	}
	if (c == 'B') {
		if (p.X == 4) return 0;
		q = mp(p.X + 1, p.Y);
	}
	if (c == 'L') {
		if (p.Y == 0) return 0;
		q = mp(p.X, p.Y - 1);
	}
	if (c == 'R') {
		if (p.Y == 4) return 0;
		q = mp(p.X, p.Y + 1);
	}
	swap(G[p.X][p.Y], G[q.X][q.Y]);
	p = q;
	// putchar(c);
	// out();
	return 1;
}

bool solve(string &op) {
	for (int i = 0; i < (int)op.size() - 1; i++)
		if (!go(op[i])) return 0;
	return 1;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
#endif
	fastin
	int cnt = 0;
	while (getline(cin, G[0]) && G[0].size() != 1 && G[0][0] != 'Z') {
		if (cnt) puts("");
		printf("Puzzle #%d:\n", ++cnt);
		for (int i = 1; i < 5; i++)
			getline(cin, G[i]);
		for (int i = 0; i < 5; i++) {
			G[i] += ' ';
			for (int j = 0; j < 5; j++)
				if (G[i][j] == ' ')
					p = mp(i, j);
		}
		string op, tmp;
		while (cin >> tmp) {
			op += tmp;
			if (tmp[(int)tmp.size() - 1] == '0')
				break;
		} cin.get();
		if (solve(op)) {
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					printf("%c%c", G[i][j], j == 4 ? '\n' : ' ');
		} else printf("This puzzle has no final configuration.\n");
	}
	return 0;
}
