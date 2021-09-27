#include<iostream>
#include<string>
using namespace std;
int main() {
    string s;
    cin >> s;
    int len = s.length() + 2;
    int left = len/3;
    int down = left + len%3;
    int space = down - 2;
    left -=1;
    for(int i=0; i<left; ++i) {
        cout << s[i];
        for(int j=0; j<space; ++j) cout << " ";
        cout << s[len-3-i] << endl;
    }
    for(int i=left; i<left+down; ++i) cout << s[i];
    cout << endl;
    
}