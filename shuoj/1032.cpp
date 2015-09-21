#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
    char a[1000];
    gets(a);
    for (int i = strlen(a) - 1; i >= 0; i--)putchar(a[i]);
    return 0;
}
/**************************************************************
    Problem: 1032
    User: 14123090
    Language: C++
    Result: Accepted
    Time:0 ms
    Memory:1052 kb
****************************************************************/