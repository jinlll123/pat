#include<bits/stdc++.h>
using namespace std;
int main() {
    int n, tmp;
    cin >> n;
    string s;
    set<int> st;
    for(int i=0; i<n; ++i) {
        cin >> s;
        tmp = 0;
        for(int j=0; j<s.length(); ++j) {
            tmp += s[j]-'0';
        }
        st.insert(tmp);
    }
    vector<int> vec;
    for(auto i : st ) {
        vec.push_back(i);
    }
    cout << vec.size() << endl;
    for(int i=0; i<vec.size(); ++i) {
        cout << vec[i] << " \n"[i==vec.size()-1];
    }
}