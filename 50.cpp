#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main() {
    string str, chars;
    getline(cin, str);
    getline(cin, chars);
    vector<int> vec(150, 0);
    for(int i=0; i<chars.length(); ++i) {
//         cout << int(chars[i]) << endl;
        vec[int(chars[i])]=1;
    }
    string res = "";
    for(int i=0; i<str.length(); ++i) {
        if(vec[int(str[i])]==0) res+=str[i];
    }
    cout << res << endl;
}