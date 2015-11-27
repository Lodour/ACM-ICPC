#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);

const int maxn = 100100;
int ex[maxn];
int Next[maxn];
int kmp(char *A, char *B) {
	int lenA = strlen(A);
	int lenB = strlen(B);
	int cnt = 0;
	Next[0] = 0;
	int j = 0;
	for (int i = 1; i < lenB; ++i) {
		while (j && B[i] != B[j]) j = Next[j - 1];
		if (B[i] == B[j]) j++;
		Next[i] = j;
	}
	j = 0;
	for (int i = 0; i < lenA; ++i) {
		while (j && A[i] != B[j]) j = Next[j - 1];
		if (A[i] == B[j]) j++;
		ex[i] = j;
		//if(ex[i]==lenB) return i-lenB+1;
		cnt = cnt > j ? cnt : j;
		if (cnt == lenB) return cnt;
	}
	return cnt;
}

char a[maxn], b[maxn];

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
	// freopen("data.out", "w", stdout);
	// freopen("/Users/Lodour/Downloads/yjs2.in", "r", stdin);
#endif

	while (~scanf("%s%s", a, b))
		printf("%d\n", kmp(a, b));

	return 0;
}