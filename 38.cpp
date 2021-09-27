#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(string &a, string &b) {
//     if(a==b) return true;
//     for(int i=0; i<min(a.length(), b.length()); ++i) {
//         if(a[i] != b[i]) return a[i] < b[i];
//     }
//     if(a.length() > b.length()) {
//         string tmp = a.substr(b.length());
//         return cmp(tmp, b);
//     }
//     else {
//         string tmp = b.substr(a.length());
//         return cmp(a, tmp);
//     }
    return (a+b) <= (b+a);
}

int clearzero(string s) {
    int i=0;
    for(; i<s.length(); ++i) {
        if(s[i] != '0') return i;
    }
    return -1;
}

int main() {
    int n;
    cin >> n;
    vector<string> vec(n);
    for(int i=0; i<n; ++i) cin >> vec[i];
    sort(vec.begin(), vec.end(), cmp);
    bool flag = true;
    for(int i=0; i<n; ++i) {
        if(flag) {
            int idx = clearzero(vec[i]);
//             cout << "idx = " << idx << endl;
            if(idx!=-1) {
                flag = false;
                cout << vec[i].substr(idx);
            }
        }
        else cout << vec[i];
    }
    if(flag) cout << 0;
    cout << endl;
}