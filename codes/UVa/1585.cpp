#include <iostream>
using namespace std;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	char s[88];
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		int res = 0, cnt = 0;
		for (int i = 0; s[i]; i++) {
			if (s[i] == 'O') cnt++;
			else {
				res += (1 + cnt) * cnt / 2;
				cnt = 0;
			}
		}
		res += (1 + cnt) * cnt / 2;
		printf("%d\n", res);
	}
	return 0;
}
