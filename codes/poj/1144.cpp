#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define fastcin ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
typedef vector<int> VI;
VI G[110];

void init(int n) {
	for (int i = 0; i < n; i++)
		G[i].clear();
}
void add_edge(int u, int v) {
	G[u].pb(v);
	G[v].pb(u);
}


int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif
	fastcin;
	int n;
	while (cin >> n && n != 0) {
		REP(i, n) G[i].clear();
		cin.get();
		string s; cin.getline(cin, s)
		stringstream ss(s);
		int u, v; ss >> u;
		if (u != 0) {
			while (ss >> v) G[u].pb(v);
		}
		else {

		}
	}

	return 0;
}