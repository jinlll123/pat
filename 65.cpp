#include<iostream>
#define ll long long
using namespace std;
struct number{
    ll num;
    int over;
    number(ll n=0, int o=0) : num(n), over(o) {}
};
number s2ll(string s) {
    if(s=="9223372036854775808") return number(9223372036854775807, 1);
    ll a=0;
    int k, i;
    if(s[0]=='-') {
        k=-1;
        a = -(s[1]-'0');
        i=2;
    }
    else {
        k=1;
        a = s[0]-'0';
        i=1;
    }
    for(; i<s.length(); ++i) a=a*10+(s[i]-'0')*(a>=0 ? 1:-1);
    return number(a, 0);
}
int main() {
    int n;
    cin >> n;
    string sa, sb, sc;
    number a, b, c;
    bool fg;
    for(int i=1; i<=n; ++i) {
        cin >> sa >> sb >> sc;
        a = s2ll(sa);
//         cout << a.num << " " << a.over << endl;
        b = s2ll(sb);
//         cout << b.num << " " << b.over << endl;
        c = s2ll(sc);
//         cout << c.num << " " << c.over << endl;
        if(a.over==1 && b.over==1) fg = true;
        else if(a.num>0 && b.num>0) {
            if(c.over == 1) {
                if(a.num+b.num+a.over+b.over < 0)  // 两边都溢出
                    fg = a.num+b.num+a.over+b.over > c.num + c.over;
                else fg = false; // 左边不溢出，肯定会小
            }
            else {
                if(a.num+b.num+a.over+b.over < 0) fg = true;
                else fg = a.num+b.num+a.over+b.over > c.num;
            }
            
        }
        else if(a.num<0 && b.num<0) {
            if(a.num==-9223372036854775808 || b.num==-9223372036854775808) fg = false;
            else if(a.num+b.num > 0) fg = false;
            else fg = a.num+b.num > c.num;
        }
        else fg = a.num+b.num+a.over+b.over > c.num;
//         cout << a.num << " =a \n " << b.num << " =b \n " << c.num << " =c \n " << a.num+b.num+a.over+b.over << " =a+b \n ";
        if(fg) printf("Case #%d: true\n", i);
        else printf("Case #%d: false\n", i);
    }
}