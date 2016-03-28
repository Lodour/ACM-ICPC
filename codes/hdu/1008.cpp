#include <iostream>
using namespace std;
int main() {
    int n;
    while (cin >> n && n) {
        int cur = 0, ans = 0, tmp;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            if (tmp > cur) ans += (tmp - cur) * 6 + 5;
            if (tmp <= cur) ans += (cur - tmp) * 4 + 5;
            cur = tmp;
        }
        cout << ans << endl;
    }
    return 0;
}
