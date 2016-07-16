#include <iostream>
#include <cstring>
#include <cstdio>
#include <queue>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)

const int N = 500050;
struct Trie {
	int next[N][26], fail[N], end[N];
	int root, L;
	int newnode() {
		for (int i = 0; i < 26; i++)
			next[L][i] = -1;
		end[L++] = 0;
		return L - 1;
	}
	void init() {
		L = 0;
		root = newnode();
	}
	void insert(char s[]) {
		int len = strlen(s);
		int now = root;
		for (int i = 0; i < len; i++) {
			int d = s[i] - 'a';
			if (next[now][d] == -1)
				next[now][d] = newnode();
			now = next[now][d];
		}
		end[now]++;
	}
	void build() {
		queue<int> q;
		fail[root] = root;
		for (int i = 0; i < 26; i++)
			if (next[now][i] == -1)
				next[now][i] = next[fail[now]][i];
			else {
				fail[next[now][i]] = next[fail[now]][i];
				q.push(next[now][i]);
			}
	}
	int query(char s[]) {
		int len = strlen(s);
		int now = root;
		int res = 0;
		for (int i = 0; i < len; i++) {
			now = next[now][s[i] - 'a'];
			int tmp = now;
			while (tmp != root) {
				res += end[tmp];
				end[tmp] = 0;
				tmp = fail[tmp];
			}
		}
		return res;
	}
};

char s[N << 1];
Trie ac;

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif


	return 0;
}
