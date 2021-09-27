#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int main() {
    string table = "0123456789ABC";
    string res="", tmp;
    int n;
    for(int i=0; i<3; ++i) {
        cin >> n;
        tmp = "";
        while(n) {
            tmp += table[n%13];
            n/=13;
        }
        for(int i=tmp.length(); i<2; ++i) tmp += "0";
        reverse(tmp.begin(), tmp.end());
        res += tmp;
    }
    cout << "#" << res << endl;
}