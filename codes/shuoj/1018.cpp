#include <iostream>
using namespace std;

int n, m, cnt;
bool G[1010][100];
const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int dfs(int x, int y) {
	cnt++;
	G[x][y] = 0;
	// cout << x << " " << y << endl;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < n && ny < m && G[nx][ny])
			dfs(nx, ny);
	}
	return 1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	cin >> m >> n;
	string s;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++)
			G[i][j] = s[j] == '*';
	}
	int ans = 0;
	// cout << dfs(0, 0) << endl; return 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (G[i][j]) {
				cnt = 0;
				dfs(i, j);
				ans = max(ans, cnt);
			}
	cout << ans << endl;

	return 0;
}
/**************************************************************
	Problem: 1018
	User: 14123090
	Language: C++
	Result: Accepted
	Time:0 ms
	Memory:1660 kb
****************************************************************/