#include <iostream>
using namespace std;

int main() {
#ifdef MANGOGAO
    freopen("data.in", "r", stdin);
#endif

    int a, b;
    while (cin >> a >> b)
        cout << a + b << endl;
    return 0;
}
