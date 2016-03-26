#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;

const int N = 40000;
int phi[N] = {0, 1};

void init() {
	for (int i = 2; i < N; i++)
		if (!phi[i])
			for (int j = i; j < N; j += i) {
				if (!phi[j]) phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}

}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	init();
	int t;
	scanf("%d", &t);
	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", phi[n]);
	}

	return 0;
}
