#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define set(a,b) memset((a),(b),sizeof(a))

typedef long long ll;

const int MAXN = 10001;
int phi[MAXN] = {0, 1};
void CalEuler() {
	for (int i = 2; i < MAXN; i++)
		if (!phi[i])
			for (int j = i; j < MAXN; j += i) {
				if (!phi[j]) phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	CalEuler();
	cin >> n;
	cout << phi[n] << endl;

	return 0;
}
