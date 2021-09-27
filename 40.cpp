#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    string s;
    getline(cin, s);
    int len = s.length();
    int res = 0;
    for(int i=0; i<len; ++i) {
        int l = i-1, r = i+1, tmp = 1;
        while(l>=0 && r<len) {
            if(s[l--]==s[r++]) tmp += 2;
            else break;
        }
        res = max(res, tmp);
        if(s[i]==s[i+1]) {
            l=i-1, r=i+2, tmp = 2;
            while(l>=0 && r<len) {
                if(s[l--]==s[r++]) tmp += 2;
                else break;
            }
            res = max(res, tmp);
        }
//         int j;
//         for(j=1; i>=j && i+j<len && s[i-j]==s[i+j]; ++j);
//         res = max(res, 2*j-1);
//         for(j=0; i>=j && i+j+1<len && s[i-j]==s[i+j+1]; ++j);
//         res = max(res, 2*j);
    }
    cout << res << endl;
    
}