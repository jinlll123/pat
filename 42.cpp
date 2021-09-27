#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
int main() {
    int n;
    vector<int> vec(54);
    map<int, int> mp;
    cin >> n;
    for(int i=0; i<54; ++i) {
        vec[i] = i;
        int t;
        cin >> t;
        --t;
        mp[t] = i;
    }
    for(int i=0; i<n; ++i) {
        vector<int> vt(54);
        for(int i=0; i<54; ++i) {
            vt[i] = vec[mp[i]];
        }
        vec = vt;
    }
    string s = "SHCDJ";
    for(int i=0; i<54; ++i) {
        cout << s[vec[i]/13] << (vec[i]%13+1) << " \n"[vec[i]==vec.back()];
    }
}