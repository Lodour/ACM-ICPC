#include <bits/stdc++.h>
using namespace std;
#define fastin ios_base::sync_with_stdio(0);cin.tie(0);
#define set(a,b) memset(a,b,sizeof(a))

string G[5];
int sx, sy;

bool solve(string &op) {
	for (int i = 0; i < (int)op.size(); i++) {
		switch (op[i]) {
		case 'A': {
			if (sx == 0) return 0;
			swap(G[sx][sy], G[sx - 1][sy]);
			sx--;
			break;
		}
		case 'R': {
			if (sy == 4) return 0;
			swap(G[sx][sy], G[sx][sy + 1]);
			sy++;
			break;
		}
		case 'B': {
			if (sx == 4) return 0;
			swap(G[sx][sy], G[sx + 1][sy]);
			sx++;
			break;
		}
		case 'L': {
			if (sy == 0) return 0;
			swap(G[sx][sy], G[sx][sy - 1]);
			sy--;
			break;
		}
		}
		// {
		// 	for (int ii = 0; ii < 5; ii++)
		// 		for (int j = 0; j < 5; j++)
		// 			cout << G[ii][j] << (j == 4 ? '\n' : ' ');
		// } cout << endl;
	}
	return 1;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	fastin;
	int cnt = 0;
	bool fi = 1;
	while (getline(cin, G[0]) && G[0].size() != 1 && G[0][0] != 'Z') {
		if (G[0].size() == 4) G[0] += " ";
		for (int i = 1; i < 5; i++) {
			getline(cin, G[i]);
			if (G[i].size() == 4) G[i] += " ";
		}
		for (int i = 0; i < 5; i++)
			for (int j = 0; j < 5; j++)
				if (G[i][j] == ' ')
					sx = i, sy = j;
		string op, tmp;
		while (cin >> tmp) {
			op += tmp;
			if (tmp[tmp.size() - 1] == '0')
				break;
		} cin.get();
		if (!fi) cout << endl;
		cout << "Puzzle #" << ++cnt << ":" << endl;
		if (solve(op)) {
			for (int i = 0; i < 5; i++)
				for (int j = 0; j < 5; j++)
					cout << G[i][j] << (j == 4 ? '\n' : ' ');
		}
		else cout << "This puzzle has no final configuration." << endl;
		fi = 0;
	}


	return 0;
}
