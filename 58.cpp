#include<iostream>
#include<cstdio>
using namespace std;
int main() {
    int a, b, c, d, e, f;
    scanf("%d.%d.%d %d.%d.%d", &a, &b, &c, &d, &e, &f);
    int k=0;
    c += f;
    k=c/29;
    c%=29;
    b = b+e+k;
    k=b/17;
    b%=17;
    a = a+d+k;
    printf("%d.%d.%d\n", a, b, c);
}