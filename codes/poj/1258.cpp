#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
/*********************************************/
//Kruskal求最小生成树
//vector版
/*********************************************/
const int MAXN = 100010;
int pa[MAXN];
int ra[MAXN];
void init(int n) {
	for (int i = 0; i <= n; i++) {
		pa[i] = i;
		ra[i] = 0;
	}
}
int find(int x) {
	if (pa[x] != x)pa[x] = find(pa[x]);
	return pa[x];
}
int unite(int x, int y) {
	x = find(x);
	y = find(y);
	if (x == y)return 0;
	if (ra[x] < ra[y]) {
		pa[x] = y;
	} else {
		pa[y] = x;
		if (ra[x] == ra[y])ra[x]++;
	}
	return 1;
}
typedef pair<int, int> PII;
vector<pair<int, PII> > G;
//
void init_G() {
	G.clear();
}
void add_edge(int u, int v, int d) {
	G.push_back(make_pair(d, make_pair(u, v)));
}
int Kruskal(int n) {
	init(n);
	sort(G.begin(), G.end());
	int m = G.size();
	int num = 0, ret = 0;
	for (int i = 0; i < m; i++) {
		pair<int, PII> p = G[i];
		int x = p.second.first;
		int y = p.second.second;
		int d = p.first;
		if (unite(x, y)) {
			num++;
			ret += d;
		}
		if (num == n - 1)break;
	}
	if (num == n - 1) return ret;
	return -1;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("data.in", "r", stdin);
#endif

	int n;
	while (scanf("%d", &n) == 1) {
		init_G();
		int a;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++) {
				scanf("%d", &a);
				add_edge(i, j, a);
			}
		printf("%d\n", Kruskal(n));
	}

	return 0;
}