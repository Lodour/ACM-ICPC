#include <iostream>
#include <cstdio>
using namespace std;

char s[88];

double cal(int i, int j) {
	double a = 0;
	switch (s[i]) {
	case 'C': a = 12.01; break;
	case 'H': a = 1.008; break;
	case 'O': a = 16.00; break;
	case 'N': a = 14.01;
	}
	int cnt = 0;
	if (i + 1 == j) cnt = 1;
	else {
		for (int k = i + 1; k < j; k++)
			cnt = cnt * 10 + s[k] - '0';
	}
	return a * cnt;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		scanf("%s", s);
		double res = 0;
		int cnt = 0;
		for (int i = 0; s[i]; i++) {
			int j;
			for (j = i + 1; s[j]; j++)
				if ('A' <= s[j] && s[j] <= 'Z')
					break;
			res += cal(i, j);
			i = j - 1;
		}
		printf("%.3f\n", res);
	}
	return 0;
}
