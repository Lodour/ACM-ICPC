#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define set(a,b) memset(a,b,sizeof(a))
#define REP(i,n) for(int i=0;i<(int)(n);i++)

struct Node {
	int cnt;
	Node* next[26];
	Node() {
		cnt = 0;
		REP(i, 26) next[i] = NULL;
	}
};

Node* rt = new Node();

void insert(char s[]) {
	Node *p = rt;
	for (int i = 0; s[i]; i++) {
		int d = s[i] - 'a';
		if (!p->next[d]) p->next[d] = new Node();
		p = p->next[d];
		p->cnt++;
	}
}

int find(char s[]) {
	Node *p = rt;
	for (int i = 0; s[i]; i++) {
		int d = s[i] - 'a';
		if (!p->next[d]) return 0;
		p = p->next[d];
	}
	return p->cnt;
}

int main() {
#ifdef MANGOGAO
	freopen("data.in", "r", stdin);
#endif

	int n;
	scanf("%d", &n);
	while (n--) {
		char s[20];
		scanf("%s", s);
		insert(s);
	}
	int m;
	scanf("%d", &m);
	while (m--) {
		char s[20];
		scanf("%s", s);
		printf("%d\n", find(s));
	}

	return 0;
}
