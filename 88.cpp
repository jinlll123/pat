#include<iostream>
#include<map>
#include<cstdio>
#include<string>
#define ll long long
using namespace std;
ll gcd(ll t1, ll t2) {
    return (t2==0 ? t1 : gcd(t2, t1%t2));
}
void gets(ll m, ll n) {
    if (m * n == 0) {
        printf("%s", n == 0 ? "Inf" : "0");
        return ;
    }
    bool flag = true;
    if((n<0 && m>0) || (n>0 && m<0)) flag = false;
    m=abs(m), n=abs(n);
    if(!flag) printf("(-");
    ll x = m/n;
    if(x!=0) printf("%lld", x);
    if(m%n == 0) {
        if(!flag) printf(")");
        return;
    }
    if(x != 0) printf(" ");
    m -= x*n;
    ll t = gcd(m, n);
    printf("%lld/%lld%s", m/t, n/t, (flag?"":")"));
}

int main() {
    ll a, b, c, d;
    scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
    gets(a, b); printf(" + "); gets(c, d); printf(" = "); gets(a*d+b*c, b*d); printf("\n");
    gets(a, b); printf(" - "); gets(c, d); printf(" = "); gets(a*d-b*c, b*d); printf("\n");
    gets(a, b); printf(" * "); gets(c, d); printf(" = "); gets(a*c, b*d); printf("\n");
    gets(a, b); printf(" / "); gets(c, d); printf(" = "); gets(a*d, b*c); printf("\n");
}