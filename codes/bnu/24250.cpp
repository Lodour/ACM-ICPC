#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
#define CLR(a); memset(a,0,sizeof(a));
typedef long long ll;
const int max_bit = 31;
const int maxn = 50050;

// count the num of 1
int AND[max_bit], OR[max_bit], XOR[max_bit];
int sumAND[max_bit], sumOR[max_bit], sumXOR[max_bit];
int a[maxn];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	for (int T = 1; T <= t; T++) {
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
			scanf("%d", &a[i]);
		CLR(AND); CLR(OR); CLR(XOR);
		CLR(sumAND); CLR(sumOR); CLR(sumXOR);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < max_bit; j++) {
				if (i) {
					if (a[i] & (1 << j)) {
						OR[j] = i;
						XOR[j] = i - XOR[j];
					}
					else AND[j] = 0;
				}
				if (a[i] & (1 << j)) {
					AND[j]++;
					OR[j]++;
					XOR[j]++;
				}
				sumAND[j] += AND[j];
				sumOR[j] += OR[j];
				sumXOR[j] += XOR[j];
			}
		}
		ll tot = 1LL * n * (n + 1) / 2;
		ll val = 1, res1, res2, res3;
		res1 = res2 = res3 = 0;
		for (int i = 0; i < max_bit; i++) {
			res1 += val * sumAND[i];
			res2 += val * sumOR[i];
			res3 += val * sumXOR[i];
			val <<= 1;
		}
		double ans1 = 1.0 * res1 / tot;
		double ans2 = 1.0 * res2 / tot;
		double ans3 = 1.0 * res3 / tot;
		printf("Case #%d: %.6f %.6f %.6f\n", T, ans1, ans2, ans3);
	}

	return 0;
}
