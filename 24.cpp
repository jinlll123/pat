#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

string cal(string s) {
    string t = s;
    string res = "";
    reverse(t.begin(), t.end());
    int tmp = 0, len = s.length();
    for(int i=len-1; i>=0; --i) {
        tmp += (s[i]-'0' + t[i]-'0');
        res = to_string(tmp%10) + res;
        tmp/=10;
    }
    if(tmp!=0) res = to_string(tmp) + res;
    return res;
}

bool isP(string s) {
    int len = s.length();
    for(int i=0; i<len/2; ++i) {
        if(s[i] != s[len-1-i]) return false;
    }
    return true;
}

int main() {
    string n;
    int k;
    cin >> n >> k;
    if(isP(n)) {
        cout << n << '\n' << 0 << endl;
        return 0;
    }
    int i;
    for(i=1; i<=k; ++i) {
        n = cal(n);
        if(isP(n)) break;
    }
    cout << n << '\n' << (i<=k ? i : k) << endl;
}