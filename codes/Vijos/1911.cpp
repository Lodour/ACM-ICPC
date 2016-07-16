#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);
#define N 10010

bool vis[N], v[N];
int a[111];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif
	fastcin;
	int n, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		vis[a[i]] = 1;
	}
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++) {
			int s = a[i] + a[j];
			if (s < 10010 && vis[s])
				v[s] = 1;
		}
	for (int i = 0; i < N; i++)
		res += v[i];
	cout << res << endl;

	return 0;
}