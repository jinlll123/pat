#include<iostream>
using namespace std;
int main() {
    string s, tmp;
    int n;
    cin >> s >> n;
    for(int i=1; i<n; ++i) {
        tmp = "";
        for(int j=0; j<s.length(); ) {
            char cur = s[j];
            tmp += cur;
            int k=j+1;
            for(; k<s.length(); ++k) {
                if(s[k] != s[j]) {
                    tmp += ('0'+k-j);
                    j=k;
                    break;
                }
            }
            if(k >= s.length()) {
                tmp += ('0'+k-j);
                break;
            }
        }
//         cout << tmp << endl;
        s = tmp;
    }
    cout << s << endl;
}