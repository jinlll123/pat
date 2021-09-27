#include<iostream>
#include<string>
using namespace std;
int main() {
    string s;
    getline(cin, s);
//     char sg1 = s[0];
//     cout << sg1 << endl;
    if(s[0]=='-') cout << '-';
    string coe = "";
    int i=1;
    for(; i<s.length(); ++i) {
        if(s[i]=='E') break;
        if('0'<=s[i] && s[i]<='9') coe += s[i];
    }
//     cout << coe << endl;
    ++i;
    char sg2 = s[i++];
//     cout << sg2 << endl;
    string exp = "";
    for(; i<s.length(); ++i) {
        exp += s[i];
    }
    int ie = stoi(exp.c_str());
//     cout << ie << endl;
    if(sg2=='+') {
        ie += 1;
        int j=0;
        for(; j<coe.length() && j<ie; ++j) {
            cout << coe[j];
        }
        if(j<coe.length()) {
            cout << '.';
            for(; j<coe.length(); ++j) cout << coe[j];
        }
        else if(j<ie)
            for(; j<ie; ++j) cout << '0';
        cout << endl;
    }
    else {
        ie -= 1;
        int j=0;
        cout << "0.";
        for(; j<ie; ++j) cout << '0';
        cout << coe << endl;
    }
}