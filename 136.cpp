#include<bits/stdc++.h>
using namespace std;

bool isP(string s) {
    if(s=="0") return true;
    int len = s.length();
    int l=0, r=len-1;
    while(l<=r) {
        if(s[l++] != s[r--]) return false;
    }
    return true;
}

string _add(string a) {
    string b = a, res = "";
    int k = 0;
    reverse(b.begin(), b.end());
    for(int i=0; i<a.length(); ++i) {
        k += (a[i]-'0'+b[i]-'0');
        res += ('0'+k%10);
        k/=10;
    }
    if(k!=0) res += ('0'+k);
    reverse(res.begin(), res.end());
    printf("%s + %s = %s\n", a.c_str(), b.c_str(), res.c_str());
    return res;
}

int main() {
    string s;
    cin >> s;
    if(isP(s)) {
        printf("%s is a palindromic number.\n", s.c_str());
    }else {
        int i=0;
        for(; i<10; ++i) {
            s = _add(s);
            if(isP(s)) {
                printf("%s is a palindromic number.\n", s.c_str());
                break;
            }
        }
        if(i>=10) {
            printf("Not found in 10 iterations.\n");
        }
    }
    
}