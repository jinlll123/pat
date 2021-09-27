#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main() {
    string s, ds="";
    cin >> s;
    vector<int> vec(10, 0);
    for(int i=0; i<s.length(); ++i) vec[s[i]-'0']++;
    int tmp = 0;
    vector<int> dvec(10, 0);
    for(int i=s.length()-1; i>=0; --i) {
        tmp = tmp + 2*(s[i]-'0');
        dvec[tmp%10]++;
        ds = to_string(char(tmp%10)) + ds;
        tmp /= 10;
//             cout << "ds = " << ds << endl;
    }
    if(tmp > 0) ds = to_string(tmp) + ds;
    bool flag = true;
    if(s[0] >= '5') flag = false;
    else {
        for(int i=0; i<10; ++i) {
            if(vec[i] != dvec[i]) {
                flag = false;
                break;
            }
        }
    }
    if(flag) cout << "Yes\n";
    else cout << "No\n";
    cout << ds << endl;
}