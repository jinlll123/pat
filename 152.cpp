#include<bits/stdc++.h>
using namespace std;
bool isPrime(int x) {
    if(x < 2) return false;
    if(x == 2) return true;
    for(int i=2; i<=(int)sqrt(x); ++i) {
        if(x%i==0) return false;
    }
    return true;
}
int main() {
    int l, k, i;
    string s;
    cin >> l >> k >> s;
    int num = 0;
    int sz = pow(10, k-1);
    for(i=0; i<k; ++i) {
        num = num*10+s[i]-'0';
    }
    for(i=k; i<l; ++i) {
//         cout << num << endl;
        if(isPrime(num)) break;
        num = num%sz;
        num = num*10+s[i]-'0';
    }
    if(i<l || isPrime(num)) {
        string res = to_string(num);
        for(int i=res.size(); i<k; ++i) {
            res = "0"+res;
        }
        cout << res << endl;
    }
    else printf("404\n");
}