#include<bits/stdc++.h>
using namespace std;
int main() {
    vector<string> vec1 = {"tret", "jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    vector<string> vec2 = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    map<string, int> mp1, mp2;
    for(int i=0; i<vec1.size(); ++i) mp1[vec1[i]] = i;
    for(int i=1; i<vec2.size(); ++i) mp2[vec2[i]] = i;
    int n;
    cin >> n;
    for(int i=0; i<n; ++i) {
        string s;
        cin >> s;
        if('0'<=s[0] && s[0]<='9') {
            int tmp = stoi(s.c_str());
            if(tmp > 12) {
                cout << vec2[tmp/13];
                tmp %= 13;
                if(tmp != 0) cout << " " << vec1[tmp] << endl;
                else cout << endl;
            }
            else cout << vec1[tmp] << endl;
        }
        else {
            char c = getchar();
            int tmp;
            if(c!='\n') {
                string s2;
                cin >> s2;
                tmp = mp2[s]*13 + mp1[s2];
            }
            else {
                if(mp2[s]!=0) tmp = mp2[s]*13;
                else tmp = mp1[s];
            }
            cout << tmp << endl;
        }
    }
}