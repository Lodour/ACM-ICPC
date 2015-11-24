#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;

const int MAXN = 111;
const int INF = 0x3f3f3f3f;
int G[MAXN][MAXN];
int GG[MAXN][MAXN];

void init(int n) {
	memset(G, 0x3f, sizeof(G));
	memset(GG, 0, sizeof(GG));
	for (int i = 0; i < n; i++)
		G[i][i] = 0;
}

void add_edge(int u, int v, int w, int k) {
	G[u][v] = min(G[u][v], w);
	GG[u][v] = k;
}

void Floyd(int n) {
	for (int k = 0; k < n; k++)
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				if (G[i][j] > G[i][k] + G[k][j]) {
					G[i][j] = G[i][k] + G[k][j];
					GG[i][j] = GG[i][k] + GG[k][j];
				}
				else if (G[i][j] == G[i][k] + G[k][j])
					GG[i][j] = max(GG[i][j], GG[i][k] + GG[k][j]);
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int t;
	scanf("%d", &t);
	while (t--) {
		int n, m, s, e;
		scanf("%d%d%d%d", &n, &m, &s, &e);
		s--; e--;
		init(n);
		int u, v, a, b;
		for (int i = 0; i < m; i++) {
			scanf("%d%d%d%d", &u, &v, &a, &b);
			u--; v--;
			add_edge(u, v, a, b);
			add_edge(v, u, a, b);
		}
		Floyd(n);
		printf("%d %d\n", G[s][e], GG[s][e]);
	}
	return 0;
}
