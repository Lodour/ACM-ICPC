#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))
#define pi 3.1415926

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	double r, v1, v2;
	while (cin >> r >> v1 >> v2)
		cout << (v2 < v1 * pi ? "Yes" : "No") << endl;

	return 0;
}
