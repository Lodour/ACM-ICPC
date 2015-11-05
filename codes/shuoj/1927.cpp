#include <cstdio>
#include <algorithm>
using namespace std;

const int N = 10;
int mp[N][N], a[N][N];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				scanf("%d", &mp[i][j]);
		int cnt, ans = 20, Max = 1 << n;
		bool is1, is2, flag;
		for (int i = 0; i < Max; i++) {
			cnt = flag = 0;
			for (int j = 0; j < n; j++) {
				cnt += flag = i & (1 << j);
				for (int k = 0; k < n; k++)
					a[j][k] = flag && mp[j][k] ? 2 : mp[j][k];
			}
			for (int j = 0; j < n; j++) {
				is1 = is2 = 0;
				for (int k = 0; k < n; k++) {
					is1 |= a[k][j] == 1;
					is2 |= a[k][j] == 2;
				}
				if (is1 && !is2) cnt++;
				if (is1 && is2) break;
			}
			if (!(is1 && is2)) ans = min(ans, cnt);
		}
		printf("%d\n", ans);
	}
	return 0;
}
