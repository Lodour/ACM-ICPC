#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
    freopen("/Users/Lodour/data.in", "r", stdin);
#endif

    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        getchar();
        vector<pair<string, string> > v;
        string a, b, s;
        for (int i = 0; i < n; i++) {
            getline(cin, s);
            a = s.substr(0, s.size() - 5);
            b = s.substr(s.size() - 4, 4);
            v.push_back(make_pair(b, a));
        }
        sort(v.begin(), v.end());
        for (int i = n - 1; i >= 0; i--)
            cout << v[i].second << endl;
    }

    return 0;
}