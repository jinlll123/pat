#include<iostream>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
using namespace std;

map<char, int> mp;

long long getNum(string s, long long r) {
    long long res = 0;
    for(int i=0; i<s.length(); ++i) {
//         cout << "getNum  i= " << i << "/ res = " << res << "/ s[i] = " << s[i] << endl;
        res = res*r;
        if(s[i]>='0' && s[i]<='9') res += (s[i]-'0');
        else res += (10+s[i]-'a');
    }
//     cout << "getnum res = " << res << endl;
    return res;
}

long long getRes(string s, long long tar) {
    int st = 0;
    for(int i=0; i<s.length(); ++i) {
        st = max(st, mp[s[i]]);
    }
    long long l=st+1, r = max(tar, l);
    while(l <= r) {
        long long mid = (l+r)/2;
        long long tmp = getNum(s, mid);
        if(tmp < 0 || tmp > tar) r = mid-1;
        else if (tmp < tar) l = mid+1;
        else return mid;
    }
    return -1;
//     for(; i<36; ++i) {
//         long long tmp = getNum(s, i);
//         if(tmp == tar) break;
//     }
//     if(i < 36) cout << i << endl;
//     else cout << "Impossible\n";
}

int main() {
    for(int i=0; i<10; ++i) mp['0'+i] = i;
    for(int i=0; i<26; ++i) mp['a'+i] = 10+i;
    string a, b;
    int fg, r;
    cin >> a >> b >> fg >> r;
    long long res;
    if(fg==1) {
//         cout << " ??? " << getNum(a, r) << endl;
        res = getRes(b, getNum(a, r));
    }
    else res = getRes(a, getNum(b, r));
    if(res==-1) cout << "Impossible\n";
    else cout << res << endl;
}