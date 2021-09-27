#include<iostream>
#include<string>
using namespace std;
int main() {
    int n;
    cin >> n;
    int res=0, left, right, now, a=1;
    while(n/a) {
        left = n/(a*10), right = n%a, now = n/a%10;
        if(now==0) res += left*a;
        else if(now==1) res += (left*a + right + 1);
        else res += (left+1)*a;
        a *= 10;
    }
    cout << res << endl;
//     string s = to_string(n);
//     int cnt = 0, a=1, res = 0;
//     for(int i=0; i<s.length(); ++i) a*=10;
//     for(int i=0; i<s.length(); ++i) {
//         a/=10;
//         if(s[i]=='0') {
//             res += (cnt*a);
//         }
//         else if(s[i]=='1') {
//             res += (cnt*a+1+n%a);
//         }
//         else {
//             res += ((cnt+1)*a);
//         }
//         cnt = cnt*10 + (s[i]-'0');
//     }
//     cout << res << endl;
}