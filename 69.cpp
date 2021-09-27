#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
using namespace std;

int main() {
    string s;
    int left, right, res=-1, tmp;
    cin >> s;
    while(true) {
        while(s.length()<4) s+="0";
        sort(s.begin(), s.end());
        right = stoi(s.c_str());
        reverse(s.begin(), s.end());
        left = stoi(s.c_str());
        tmp = left - right;
        if(res==tmp) break;
        res = tmp;
        s = to_string(tmp);
        printf("%04d - %04d = %04d\n", left, right, res);
    }
//     sort(s.begin(), s.end());
//     cout << s << endl;
//     reverse(s.begin(), s.end());
//     cout << s << endl;
    
}